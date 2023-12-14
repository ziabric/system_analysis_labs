#include <task4/task.cpp>

int main() {
    auto result = task();
    for (double val : result) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    return 0;
}