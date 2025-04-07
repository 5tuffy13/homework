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

Graph::Graph(const string& file) {
    ifstream in(file);
    if (!in.is_open()) {
        throw runtime_error("Error: Could not open file: " + file);
    }

    string header1, header2;

    if (!(in >> header1 >> header2)) {
        throw runtime_error("Error: Could not read header from file: " + file);
    }

    string sourceName, targetName;
    while (in >> sourceName >> targetName) {

        Node* sourceNode = findOrCreateNode(sourceName);
        Node* targetNode = findOrCreateNode(targetName);

        addEdge(sourceNode, targetNode);
    }
    if (!in.eof() && in.fail()) {
        cerr << "Warning: File reading stopped possibly due to malformed line in " << file << endl;
    }

}

Graph::~Graph() {
    cout << "Destroying graph. Deleting " << nodes.size() << " nodes..." << endl;
    for (Node* nodePtr : nodes) {
        delete nodePtr;
    }
    nodes.clear();
    cout << "Graph destroyed." << endl;
}

void Graph::addNode(Node* node)
{
	nodes.insert(node);
}


Node* Graph::findOrCreateNode(const string& name) {
	for (Node* existingNode : nodes) {
		if (existingNode->getName() == name) {
			return existingNode;
		}
	}

	Node* newNode = new Node(name);
	nodes.insert(newNode);
	return newNode;
}


