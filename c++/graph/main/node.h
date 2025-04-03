#pragma once
#include <iostream>
#include <set>
using namespace std;
class Node {
	string name;
	set<Node*> neighbours;
	void addNeighbour(Node* neighbour);
	void removeNeighbour(Node* neighbour);
public:
	Node(const string& aname) : name(aname) {}
	const string& getName() const { return name; }
	auto nb_begin() const { return neighbours.cbegin(); }
	auto nb_end() const { return neighbours.cend(); }
	friend class Graph;
};