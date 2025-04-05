#include <fstream>
#include <iostream>
#include "writeToFile.cpp"

int main(){
    std::ofstream outFile("index.idx", std::ios::binary);

    if (!outFile) {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    WriteToFile(0, 1, 2, outFile);
    WriteToFile(1, 3, 4, outFile);

    outFile.close();

    std::cout << "written to file" << std::endl;

    return 0;
}