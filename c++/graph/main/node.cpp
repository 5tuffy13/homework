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

set<Node*> Node::getNeighbours()
{
	return this->neighbours;
}

ostream& operator<<(ostream& os, const Node& node)
{
	os << node.getName(); // Печатаем имя узла
	return os;
}
