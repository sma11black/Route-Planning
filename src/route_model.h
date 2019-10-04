#pragma once

#include <limits>
#include <cmath>
#include <unordered_map>
#include "model.h"
#include <iostream>
//The Model class that exists in the current code doesn't contain all the data or methods
//that will be needed to perform an A* search, 
//so we are going to extend that class with a RouteModel class. 

/*
Task:
In route_model.h:

Add a private vector of Node objects named m_Nodes. This will store all of the nodes from the Open Street Map data.
Add a public "getter" method SNodes. This method should return a reference to the vector of Nodes stored as m_Nodes.
*/

class RouteModel : public Model {

public:
	class Node : public Model::Node {
	public:
		Node * parent = nullptr;
		float h_value = std::numeric_limits<float>::max();
		float g_value = 0.0;
		bool visited = false;
		std::vector<Node *> neighbors;

		void FindNeighbors();
		float distance(Node other) const {
			return std::sqrt(std::pow((x - other.x), 2) + std::pow((y - other.y), 2));
		}

		Node() {}
		Node(int idx, RouteModel * search_model, Model::Node node) : Model::Node(node), parent_model(search_model), index(idx) {}

	private:
		int index;
		Node * FindNeighbor(std::vector<int> node_indices);
		RouteModel * parent_model = nullptr;	//  it allows each node to access data stored in the parent model that the node belongs to.

	};

	RouteModel(const std::vector<std::byte> &xml);
	Node &FindClosestNode(float x, float y);
	auto &SNodes() { return m_Nodes; }
	auto &GetNodeToRoadMap() { return node_to_road; }
	std::vector<Node> path; // This variable will eventually store the path that is found by the A* search.

private:
	void CreateNodeToRoadHashmap();
	std::unordered_map<int, std::vector<const Model::Road*>> node_to_road;
	std::vector<Node> m_Nodes;
};
