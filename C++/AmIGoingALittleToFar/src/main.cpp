#include <iostream>
#include <chrono>
#include <filesystem>
#include <vector>
#include "search.hpp"
#include "sort.hpp"
// #include "writeToFile.h"
#include "index.hpp"

int main() {
    std::cout << "start" << std::endl;

    size_t rows = 5000000; // 5.000.000

    std::cout << "Generating " << rows << " random indexes.";

    // init and fill index array
    std::vector<IndexValue<uint32_t, int32_t>> index(rows);

    srand(static_cast<unsigned>(time(0)));

    std::cout << ".";

    for (size_t i = 0; i < rows; i++) {
        index[i] = IndexValue<uint32_t, int32_t>(
            (uint32_t)i + 1,
            rand() % 10000000 - 5000000
        );
    }

    std::cout << "." << std::endl;

    std::cout << "Sorting indexes..." << std::endl;

    auto sortSTime = std::chrono::high_resolution_clock::now();
    sort::MergeSortInPlace(index);
    auto sortETime = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> sortElapsed = sortETime - sortSTime;

    std::cout << "Sort time: " << sortElapsed.count() * 1000 << " ms sorted: " << sort::CheckSorted(index) << std::endl;

    std::cout << "Generated indexes!" << std::endl;

    // pick 100.000 random indexes to search
    size_t testIndexesCount = 100000; // 100.000

    std::cout << "\nPicking " << testIndexesCount << " random indexes from original dataset for test..." << std::endl;

    std::vector<IndexValue<uint32_t, int32_t>> testIndexes(testIndexesCount);

    for (size_t i = 0; i < testIndexesCount; i++){
        size_t randomIndex = rand() % rows;
        testIndexes[i] = index[randomIndex];
    }

    std::cout << "Picked indexes!" << std::endl;

    std::cout << "\nStarting test, searching for " << testIndexesCount << " indexes in an index of " << rows << " rows" << std::endl;

    auto sTime = std::chrono::high_resolution_clock::now();

    int correctSearches = 0;
    for (int i = 0; i < testIndexesCount; i++) {
        volatile IndexValue<uint32_t, int32_t>* found = search::InterpolationSearchUnique(index, testIndexes[i].Value); // marked volatile to prevent optimizations
        if (found != nullptr && found->Value == testIndexes[i].Value){
            correctSearches++;
        }
    }

    auto eTime = std::chrono::high_resolution_clock::now();

    // inFile.close();

    std::cout << "Correct: " << correctSearches << std::endl;

    std::chrono::duration<double> elapsed = eTime - sTime;

    std::cout << "Time taken: " << elapsed.count() * 1000 << " ms" << std::endl;
    std::cout << "Average per search: " << elapsed.count() * 1000 / testIndexesCount << " ms" << std::endl;

    // // cleanup
    // for (int i = 0; i < testIndexesCount; i++){
    //     delete[] testIndexes[i];
    // }
    // delete[] testIndexes;
    // testIndexes = nullptr;

    std::cout << "\nPress enter to exit...";
    std::cin.get();
    std::cout << std::endl;
}
