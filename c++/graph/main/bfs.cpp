#include "bfs.h"
// #include <set>  // Уже включены через bfs.h
// #include <queue>

// Реализация старого метода connected (остается без изменений)
bool BFS::connected(Node* begin, Node* end) {
    if (!begin || !end) return false;
    if (begin == end) return true;

    std::queue<Node*> nodes; nodes.push(begin);
    std::set<Node*> visited_local; // Локальное множество для этой проверки
    visited_local.insert(begin);

    while (!nodes.empty()) {
        Node* next = nodes.front(); nodes.pop();

        for (Node* neighbour : next->getNeighbours()) { // Используем getNeighbours для простоты
            if (neighbour == end) return true;

            if (visited_local.find(neighbour) == visited_local.end()) {
                visited_local.insert(neighbour);
                nodes.push(neighbour);
            }
        }
    }
    return false;
}


// --- Реализация нового метода findComponent ---
std::set<Node*> BFS::findComponent(Node* startNode, std::set<Node*>& visitedNodes) {
    std::set<Node*> componentNodes; // Узлы для этой компоненты

    // Если стартовый узел пуст или УЖЕ посещен глобально, то ничего не делаем
    if (!startNode || visitedNodes.find(startNode) != visitedNodes.end()) {
        return componentNodes; // Возвращаем пустой set
    }

    // Узел не посещен - начинаем BFS для новой компоненты
    std::queue<Node*> q;
    q.push(startNode);
    visitedNodes.insert(startNode);   // Отмечаем как посещенный ГЛОБАЛЬНО
    componentNodes.insert(startNode); // Добавляем в ТЕКУЩУЮ компоненту

    while (!q.empty()) {
        Node* currentNode = q.front();
        q.pop();

        // Проходим по всем соседям
        for (Node* neighbour : currentNode->getNeighbours()) {
            // Если соседа еще не посещали ГЛОБАЛЬНО
            if (visitedNodes.find(neighbour) == visitedNodes.end()) {
                visitedNodes.insert(neighbour);    // Отмечаем глобально
                componentNodes.insert(neighbour);  // Добавляем в текущую компоненту
                q.push(neighbour);                 // Добавляем в очередь для обхода
            }
        }
    }

    // BFS завершен, возвращаем все узлы найденной компоненты
    return componentNodes;
}