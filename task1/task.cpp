#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>

std::string getItemFromCSV(const std::string& filename, char delimiter, int row, int column)
{
    std::ifstream file(filename);
    std::string line;
    int currentRow = 0;

    while (std::getline(file, line)) 
    {
        currentRow++;
        if (currentRow == row) 
        {
            std::istringstream lineStream(line);
            std::string cell;
            int currentCol = 0;

            while (std::getline(lineStream, cell, delimiter)) 
            {
                currentCol++;
                if (currentCol == column) 
                {
                    return cell;
                }
            }

            break;
        }
    }

    return "None";
}

int main(int argc, char** argv)
{
    if ( argc != 4 )
    {
        std::cout<<"You need to enter 3 arguments\n"
        << "1 - Path to CSV file\n"
        << "2 - Row number\n"
        << "3 - Column number"
        << std::endl;

        return 0;
    }

    auto filePath = std::filesystem::path(argv[1]);

    if ( !exists(filePath) )
    {
        std::cout<< "The file does not exist" <<std::endl;
        return 0;
    }

    auto cell = getItemFromCSV(filePath.string(), ',', atoi(argv[2]), atoi(argv[3]));

    std::cout<<cell<<std::endl;
}