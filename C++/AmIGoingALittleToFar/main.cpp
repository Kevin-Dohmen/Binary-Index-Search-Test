#include <ostream>
#include <iostream>
#include <chrono>
#include <vector>
#include "binarySearch.h"
#include "writeToFile.h"
#include <filesystem>
#include <random>

int main() {

    std::cout << "start" << std::endl;

    int rows = 5000000; // 5.000.000

    // init and fill index array
    int** index = new int*[rows];

    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(-500000, 500000);

    for (int i = 0; i < rows; i++) {
        index[i] = new int[2]{
            dist(rng),
            i + 1
        };
    }

    // pick 100.000 random indexes to search
    int testIndexesCount = 100000; // 100.000
    int** testIndexes;
    testIndexes = new int*[testIndexesCount];

    for (int i = 0; i < testIndexesCount; i++){
        int randomIndex = rand() % rows;
        testIndexes[i] = new int[2]{
            index[randomIndex][0],
            index[randomIndex][1]
        };
    }

    std::filesystem::create_directories("./tmp");

    // write indexes to file
    std::ofstream outFile("./tmp/index", std::ios::binary);
    if (!outFile) {
        std::cerr << "Failed to open output file!" << std::endl;
        return 1;
    }

    WriteToFile(index, rows, outFile);

    outFile.close();

    // cleanup
    for (int i = 0; i < rows; i++){
        delete[] index[i];
    }
    delete[] index;
    index = nullptr;

    // start test

    std::cout << "starting test, searching for " << testIndexesCount << " indexes in an index of " << rows << " rows" << std::endl;

    std::ifstream inFile("./tmp/index", std::ios::binary);
    if (!inFile) {
        std::cerr << "Failed to open input file!" << std::endl;
        return 1;
    }

    inFile.seekg(0, std::ios::end);
    std::streampos fileSize = inFile.tellg();
    inFile.seekg(0, std::ios::beg);

    std::cout << "file size: " << fileSize << " bytes" << std::endl;

    auto sTime = std::chrono::high_resolution_clock::now();

    int correctSearches = 0;
    for (int i = 0; i < testIndexesCount; i++) {
        volatile int ptr = SearchUnique(testIndexes[i][1], rows, inFile); // marked volatile to prevent optimizations
        if (ptr != (int)0xFFFFFFFF && ptr == testIndexes[i][0]){
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
    testIndexes = nullptr;
}
