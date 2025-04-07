#pragma once
#include <iostream>
#include <set>
#include "node.h"
#include <fstream>
using namespace std;

typedef std::set<Node*>::const_iterator node_iterator;

class Graph {
	
	set<Node*> nodes;
	Node* findOrCreateNode(const string& name);
public:
	Graph(const string& file);
	~Graph();
	size_t nodeCount() const {
		return nodes.size();
	}
	void addNode(Node* node);
	void removeNode(Node* node);
	void addEdge(Node* begin, Node* end);
	node_iterator begin() const { return nodes.begin(); }
	node_iterator end() const { return nodes.end(); }

};