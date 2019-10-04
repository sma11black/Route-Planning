﻿#include "route_planner.h"
#include <algorithm>

RoutePlanner::RoutePlanner(RouteModel &model, float start_x, float start_y, float end_x, float end_y) : m_Model(model) {
	// Convert inputs to percentage
	start_x *= 0.01;
	start_y *= 0.01;
	end_x *= 0.01;
	end_y *= 0.01;

	start_node = &m_Model.FindClosestNode(start_x, start_y);
	end_node = &m_Model.FindClosestNode(end_x, end_y);
}

void RoutePlanner::AStarSearch()
{
	// Initialize open_list with starting node
	start_node->visited = true;
	open_list.push_back(start_node);
	RouteModel::Node *current_node = nullptr;

	// Expand nodes until reach the goal.
	while (open_list.size() > 0)
	{
		// Select the best node to explore next.
		current_node = NextNode();
		if (current_node->distance(*end_node) == 0)
		{
			m_Model.path = ConstructFinalPath(current_node);
			return;
		}
		AddNeighbors(current_node);
	}
}

void RoutePlanner::AddNeighbors(RouteModel::Node * current_node)
{
	// Expand the current node
	// Add all unvisited neighbors to the open list
	current_node->FindNeighbors();
	for (auto neighbor : current_node->neighbors)
	{
		neighbor->parent = current_node;
		neighbor->g_value = current_node->g_value + current_node->distance(*neighbor);
		neighbor->h_value = CalculateHValue(neighbor);

		// Add the neighbor to the open list
		open_list.push_back(neighbor);
		neighbor->visited = true;
	}
}

float RoutePlanner::CalculateHValue(RouteModel::Node * node)
{
	return node->distance(*end_node);
}

std::vector<RouteModel::Node> RoutePlanner::ConstructFinalPath(RouteModel::Node *current_node)
{
	// Create path_found vector
	distance = 0.0f;
	std::vector<RouteModel::Node> path_found;
	RouteModel::Node parent;

	while (current_node->parent != nullptr)
	{
		path_found.push_back(*current_node);
		parent = *(current_node->parent);
		distance += current_node->distance(parent);
		current_node = current_node->parent;
	}
	path_found.push_back(*current_node);
	distance *= m_Model.MetricScale();
	return path_found;
}

RouteModel::Node * RoutePlanner::NextNode()
{
	std::sort(open_list.begin(), open_list.end(), [](const auto &_1st, const auto &_2nd) {
		return _1st->h_value + _1st->g_value < _2nd->h_value + _2nd->g_value;
	});

	RouteModel::Node *lowest_node = open_list.front();
	open_list.erase(open_list.begin());
	return lowest_node;
}
