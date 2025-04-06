#include "readFromFile.cpp"

#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

int SearchUnique(int searchValue, int indexLength, std::ifstream& index){
    int left = 0;
    int right = indexLength - 1;

    bool fetchedFull = false;

    int itCount = 0;

    while (left <= right){

        itCount++;

        int center = (left + right) / 2;

        int* idx = ReadSingleIndexFromFile(center, index);

        int value = idx[1];

        if (value == searchValue){
            return idx[0];
            delete[] idx;
        }
        else if (value < searchValue){
            left = center + 1; // right split
        }
        else {
            right = center - 1; // left split
        }

        delete[] idx;
    }

    return 0xFFFFFFFF; // mark as not found
}

#endif