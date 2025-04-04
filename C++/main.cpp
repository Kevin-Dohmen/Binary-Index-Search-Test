#include <ostream>
#include <iostream>
#include <chrono>

int SearchUnique(int **index, int indexLength, int searchValue){ // 21 lines
    int left = 0;
    int right = indexLength - 1;

    while (left <= right){
        int center = (left + right) / 2;
        int value = index[center][1];

        if (value == searchValue){
            return index[center][0];
        }
        else if (value < searchValue){
            left = center + 1; // right split
        }
        else {
            right = center - 1; // left split
        }
    }

    return 0xFFFFFFFF; // mark as not found
}

int main() {
    const int rows = 5000000; // 5.000.000

    // init and fill index array
    int **index;
    index = new int*[rows];

    srand(static_cast<unsigned>(time(0)));

    for (int i = 0; i < rows; i++) {
        index[i] = new int[2];
        index[i][0] = rand() % 999999 + 1;
        index[i][1] = i + 1;
    }

    // pick 100.000 random indexes to search
    int testIndexesCount = 100000; // 100.000
    int **testIndexes;
    testIndexes = new int*[testIndexesCount];

    for (int i = 0; i < testIndexesCount; i++){
        testIndexes[i] = new int[2];
        int randomIndex = rand() % rows;
        testIndexes[i][0] = index[randomIndex][0];
        testIndexes[i][1] = index[randomIndex][1];
    }

    // start test

    std::cout << "starting test, searching for " << testIndexesCount << "indexes in an index of " << rows << "rows" << std::endl;

    auto sTime = std::chrono::high_resolution_clock::now();

    unsigned int dummySum = 0;
    for (int i = 0; i < testIndexesCount; i++) {
        dummySum += SearchUnique(index, rows, testIndexes[i][1]); // marked as volatile to prevent optimizers from skipping the function
    }

    std::cout << "DummySum: " << dummySum << std::endl;

    auto eTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = eTime - sTime;

    std::cout << "Time taken: " << elapsed.count() * 1000 << " ms" << std::endl;
    std::cout << "Average per search: " << elapsed.count() * 1000 / testIndexesCount << "ms" << std::endl;

    // cleanup
    for (int i = 0; i < rows; i++){
        delete index[i];
    }
    delete index;

    for (int i = 0; i < testIndexesCount; i++){
        delete testIndexes[i];
    }
    delete testIndexes;
}
