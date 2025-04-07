#ifndef READINDEXFROMFILE_H
#define READINDEXFROMFILE_H

#include <fstream>
#include <iostream>

int* ReadSingleIndexFromFile(int row, std::ifstream& inFile){
    int byteLoc = row * 8;

    char barr[8];

    inFile.seekg(byteLoc);
    inFile.read(barr, 8);

    int ptr = 0;
    int val = 0;

    for (int i = 0; i < 4; i++){
        ptr = (ptr << 8) | static_cast<unsigned char>(barr[i]);
        val = (val << 8) | static_cast<unsigned char>(barr[i + 4]);
    }

    int* idx = new int[2]{
        ptr,
        val
    };

    return idx;
}

#endif
