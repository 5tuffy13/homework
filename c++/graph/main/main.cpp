#include <iostream>
#include "graph.h"
#include "bfs.h"
using namespace std;
int main()
{
    string filename = "testgraph.txt"; // Имя файла для теста
    // string filename = "1000.csv"; // Позже можно проверить и этот файл

    cout << "--- Testing Graph Constructor ---" << endl;
    cout << "Attempting to load graph from: " << filename << endl;

    try {
        // Создаем объект графа. Конструктор читает файл.
        // Используем фигурные скобки, чтобы ограничить время жизни graph
        // и увидеть вызов деструктора до конца main (для теста).
        { // Начало блока видимости для graph
            Graph graph(filename);

            cout << "Graph loaded successfully!" << endl;
            cout << "Number of nodes found: " << graph.nodeCount() << endl;

            cout << "\n--- Node Adjacency List ---" << endl;

            // Проверяем, есть ли узлы вообще
            if (graph.nodeCount() == 0) {
                cout << "(Graph is empty)" << endl;
            }
            else {
                // Итерируемся по всем узлам в графе
                // Используем auto для упрощения типа итератора
                for (auto it = graph.begin(); it != graph.end(); ++it) {
                    Node* currentNode = *it; // Получаем указатель на текущий узел

                    // Выводим имя текущего узла (используем перегруженный operator<<)
                    cout << "Node [" << *currentNode << "]:\tNeighbours: { ";

                    // Получаем соседей текущего узла
                    set<Node*> neighbours = currentNode->getNeighbours();

                    // Выводим соседей
                    bool firstNeighbour = true;
                    for (Node* neighbour : neighbours) {
                        if (!firstNeighbour) {
                            cout << ", ";
                        }
                        cout << *neighbour; // Выводим имя соседа
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

