#include "bfs.h"
// #include <set>  // ��� �������� ����� bfs.h
// #include <queue>

// ���������� ������� ������ connected (�������� ��� ���������)
bool BFS::connected(Node* begin, Node* end) {
    if (!begin || !end) return false;
    if (begin == end) return true;

    std::queue<Node*> nodes; nodes.push(begin);
    std::set<Node*> visited_local; // ��������� ��������� ��� ���� ��������
    visited_local.insert(begin);

    while (!nodes.empty()) {
        Node* next = nodes.front(); nodes.pop();

        for (Node* neighbour : next->getNeighbours()) { // ���������� getNeighbours ��� ��������
            if (neighbour == end) return true;

            if (visited_local.find(neighbour) == visited_local.end()) {
                visited_local.insert(neighbour);
                nodes.push(neighbour);
            }
        }
    }
    return false;
}


// --- ���������� ������ ������ findComponent ---
std::set<Node*> BFS::findComponent(Node* startNode, std::set<Node*>& visitedNodes) {
    std::set<Node*> componentNodes; // ���� ��� ���� ����������

    // ���� ��������� ���� ���� ��� ��� ������� ���������, �� ������ �� ������
    if (!startNode || visitedNodes.find(startNode) != visitedNodes.end()) {
        return componentNodes; // ���������� ������ set
    }

    // ���� �� ������� - �������� BFS ��� ����� ����������
    std::queue<Node*> q;
    q.push(startNode);
    visitedNodes.insert(startNode);   // �������� ��� ���������� ���������
    componentNodes.insert(startNode); // ��������� � ������� ����������

    while (!q.empty()) {
        Node* currentNode = q.front();
        q.pop();

        // �������� �� ���� �������
        for (Node* neighbour : currentNode->getNeighbours()) {
            // ���� ������ ��� �� �������� ���������
            if (visitedNodes.find(neighbour) == visitedNodes.end()) {
                visitedNodes.insert(neighbour);    // �������� ���������
                componentNodes.insert(neighbour);  // ��������� � ������� ����������
                q.push(neighbour);                 // ��������� � ������� ��� ������
            }
        }
    }

    // BFS ��������, ���������� ��� ���� ��������� ����������
    return componentNodes;
}