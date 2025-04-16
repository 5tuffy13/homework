#include <iostream>
#include "graph.h"
#include "bfs.h"
using namespace std;
int main()
{
    string filename = "testgraph.txt";
    cout << "--- Testing Graph Constructor ---" << endl;
    cout << "Attempting to load graph from: " << filename << endl;

    try {
            Graph graph(filename);

            cout << "Graph loaded successfully!" << endl;
            cout << "Number of nodes found: " << graph.nodeCount() << endl;

            cout << "\n--- Node Adjacency List ---" << endl;

            if (graph.nodeCount() == 0) {
                cout << "(Graph is empty)" << endl;
            }
            else {

                for (auto it = graph.begin(); it != graph.end(); ++it) {
                    Node* currentNode = *it;

                    cout << "Node [" << *currentNode << "]:\tNeighbours: { ";

                    set<Node*> neighbours = currentNode->getNeighbours();

                    bool firstNeighbour = true;
                    for (Node* neighbour : neighbours) {
                        if (!firstNeighbour) {
                            cout << ", ";
                        }
                        cout << *neighbour;
                        firstNeighbour = false;
                    }
                    cout << " }" << endl;
                }
            }
            cout << "--- End of Adjacency List ---" << endl;

            cout << "\nGraph object is about to go out of scope." << endl;

        } // Конец блока видимости для graph - здесь должен вызваться деструктор ~Graph()

        cout << "--- Constructor Test Finished ---" << endl;
        return 0; // Успешное завершение

        }
    catch (const std::runtime_error& e) {
        // Ловим ошибки, которые мог выбросить конструктор
        cerr << "[ERROR] Failed to create graph: " << e.what() << endl;
        return 1; // Завершение с ошибкой
    }
    catch (...) {
        // Ловим любые другие непредвиденные исключения
        cerr << "[ERROR] An unexpected error occurred during graph creation." << endl;
        return 2; // Завершение с другой ошибкой
    }
}

