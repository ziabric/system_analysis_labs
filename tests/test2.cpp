#include <task2/task.cpp>
int main() {
    std::string csv = "0,1\n0,2\n1,3\n2,4";
    int maxNode;
    auto graph = parseGraph(csv, maxNode);
    auto parents = computeParents(graph, maxNode);

    // Вывод результатов
    for (int i = 0; i <= maxNode; ++i)
    {
        std::cout << "Node: " << i << "\n";
        std::cout << "Children: ";
        for (int child : graph[i])
        {
            std::cout << child << " ";
        }
        std::cout << "\nParents: ";
        for (int parent : parents[i])
        {
            std::cout << parent << " ";
        }
        std::cout << "\n\n";
    }

    return 0;
}