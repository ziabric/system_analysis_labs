#include <task2/task.cpp>

// 1,2\n1,3\n3,4\n3,5

int main() 
{
    std::string csv = "1,2\n1,3\n3,4\n3,5";
    auto result = processGraphCSV(csv);

    std::cout<<result<<std::endl;

    return 0;
}