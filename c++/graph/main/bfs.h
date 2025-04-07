#pragma once
#include "graph.h"
#include <gueue>
class BFS {
	const Graph& graph;
public:
	BFS(const Graph& agraph) : graph(agraph) {}
	bool connected(Node* begin, Node* end);
	std::set<Node*> findComponent(Node* startNode, std::set<Node*>& visitedNodes);
};