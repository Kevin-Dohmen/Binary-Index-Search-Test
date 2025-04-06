#include <fstream>
#include <iostream>

#ifndef READINDEXFROMFILE_H
#define READINDEXFROMFILE_H

int* ReadSingleIndexFromFile(int row, std::ifstream& inFile){
    int byteLoc = row * 8;

    char* barr = new char[8];

    inFile.seekg(byteLoc);
    inFile.read(barr, 8);

    int ptr = 0;
    int val = 0;

    for (int i = 0; i < 4; i++){
        ptr = (ptr << 8) | static_cast<unsigned char>(barr[i]);
        val = (val << 8) | static_cast<unsigned char>(barr[i + 4]);
    }

    delete[] barr;

    int* idx = new int[2]{
        ptr, val
    };

    return idx;
}

#endif
