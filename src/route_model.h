#pragma once

#include <limits>
#include <cmath>
#include <unordered_map>
#include "model.h"
#include <iostream>
//���Model �e��ֻ��һ��Node ���YӍ, Ҫ����A*, ����Ҫ���е�Node,
//����҂��^��Model ����һ��RouteModel �ʂ��ռ�����Ҫ�õ�Node �oA*

/*
Task:
In route_model.h:

Add a private vector of Node objects named m_Nodes. This will store all of the nodes from the Open Street Map data.
Add a public "getter" method SNodes. This method should return a reference to the vector of Nodes stored as m_Nodes.



*/
class RouteModel : public Model {

public:
	//RouteModel �� Node Ҳ���^�Ё��
	class Node : public Model::Node {
	public:
		// Add public Node variables and methods here.

		Node() {
			std::cout << "RouteModel Init" << "\n";
		}
		//�����init һ��pointer parent_model, ���һ��Ҫ���� initial list �ķ�ʽ
		Node(int idx, RouteModel * search_model, Model::Node node) : Model::Node(node), parent_model(search_model), index(idx) {
			std::cout << "RouteModel Init" << "\n";
		}

	private:
		// Add private Node variables and methods here.
		int index;
		RouteModel * parent_model = nullptr;

	};

	// Add public RouteModel variables and methods here.
	RouteModel(const std::vector<std::byte> &xml);

	//�@�� path ����������Y��
	std::vector<Node> path; // This variable will eventually store the path that is found by the A* search.

							//Task2:Add a public "getter" method SNodes. This method should return a reference to the vector of Nodes stored as m_Nodes.
	std::vector<Node>& SNodes() {
		return m_Nodes;
	}

private:
	// Add private RouteModel variables and methods here.

	//Taks1:Add a private vector of Node objects named m_Nodes. This will store all of the nodes from the Open Street Map data.
	//�@��m_Nodes ���Á������open street map �� data, ֮��oAstar ��
	std::vector<Node> m_Nodes;
};
