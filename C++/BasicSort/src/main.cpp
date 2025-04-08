#include <iostream>
#include <ctime>
#include <chrono>

#include "sort.h"
#include "checkSort.h"

int main(){
    // generate random data
    int length = 10000; // 10.000
    int* arr = new int[length];

    srand(static_cast<unsigned>(time(0)));

    for (int i = 0; i < length; i++){
        arr[i] = rand() % 1000000;
    }

    std::cout << "sorted: " << (CheckIsSorted(arr, length) ? "yes" : "no") << std::endl;

    auto sTime = std::chrono::high_resolution_clock::now();
    Sort(arr, length);
    auto eTime = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = eTime - sTime;

    std::cout << "sorted: " << (CheckIsSorted(arr, length) ? "yes" : "no") << std::endl;

    std::cout << "sorted in " << elapsed.count() * 1000 << " ms" << std::endl;

    // cleanup
    delete[] arr;
}