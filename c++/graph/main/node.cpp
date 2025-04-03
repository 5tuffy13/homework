#include "node.h"
void Node::addNeighbour(Node* neighbour)
{
	if (neighbour != nullptr)
	{
		this->neighbours.insert(neighbour);
		neighbour->neighbours.insert(this);
	}
}

void Node::removeNeighbour(Node* neighbour)
{
	if (neighbour != nullptr)
	{
		this->neighbours.erase(neighbour);
		neighbour->neighbours.erase(this);
	}
}
