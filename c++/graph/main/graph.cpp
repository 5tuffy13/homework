#include "graph.h"
using namespace std;
void Graph::removeNode(Node* node)
{
	nodes.erase(node);
	for (set<Node*>::iterator it = nodes.begin(); it != nodes.end(); it++)
	{
		(*it)->removeNeighbour(node);
	}
}

void Graph::addEdge(Node* begin, Node* end)
{
	if (begin && end)
	{
		begin->addNeighbour(end);
		end->addNeighbour(begin);
	}
}

void Graph::addNode(Node* node)
{
	nodes.insert(node);
}

