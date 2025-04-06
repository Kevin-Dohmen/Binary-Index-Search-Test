#include <ostream>
#include <iostream>
#include <chrono>
#include <vector>
#include "binarySearch.h"
#include "writeToFile.h"

int main() {

    std::cout << "start" << std::endl;

    int rows = 5000000; // 5.000.000

    // init and fill index array
    int** index = new int*[rows];

    srand(static_cast<unsigned>(time(0)));

    for (int i = 0; i < rows; i++) {
        index[i] = new int[2]{
            rand() % 1000000 + 1 - 500000,
            i + 1
        };
    }

    // pick 100.000 random indexes to search
    int testIndexesCount = 1000; // 1000
    int** testIndexes;
    testIndexes = new int*[testIndexesCount];

    for (int i = 0; i < testIndexesCount; i++){
        int randomIndex = rand() % rows;
        testIndexes[i] = new int[2]{
            index[randomIndex][0],
            index[randomIndex][1]
        };
    }

    // write indexes to file
    std::ofstream outFile("./out/index", std::ios::binary);

    WriteToFile(index, rows, outFile);

    outFile.close();

    // cleanup
    for (int i = 0; i < rows; i++){
        delete[] index[i];
    }
    delete[] index;

    // start test

    std::cout << "starting test, searching for " << testIndexesCount << " indexes in an index of " << rows << " rows" << std::endl;

    std::ifstream inFile("./out/index", std::ios::binary);

    inFile.seekg(0, std::ios::end);
    std::streampos fileSize = inFile.tellg();
    inFile.seekg(0, std::ios::beg);

    std::cout << "file size: " << fileSize << " bytes" << std::endl;

    auto sTime = std::chrono::high_resolution_clock::now();

    int correctSearches = 0;
    for (int i = 0; i < testIndexesCount; i++) {
        int ptr = SearchUnique(testIndexes[i][1], rows, inFile);
        if (ptr != 0xFFFFFFFF && ptr == testIndexes[i][0]){
            correctSearches++;
        }
    }

    auto eTime = std::chrono::high_resolution_clock::now();

    inFile.close();

    std::cout << "Correct: " << correctSearches << std::endl;

    std::chrono::duration<double> elapsed = eTime - sTime;

    std::cout << "Time taken: " << elapsed.count() * 1000 << " ms" << std::endl;
    std::cout << "Average per search: " << elapsed.count() * 1000 / testIndexesCount << " ms" << std::endl;

    // cleanup
    for (int i = 0; i < testIndexesCount; i++){
        delete[] testIndexes[i];
    }
    delete[] testIndexes;
}
