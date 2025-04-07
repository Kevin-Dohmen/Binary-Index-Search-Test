#ifndef READINDEXFROMFILE_H
#define READINDEXFROMFILE_H

#include <fstream>
#include <iostream>

int* ReadSingleIndexFromFile(int row, std::ifstream& inFile){
    int byteLoc = row * 8;

    char* barr = new char[8];

    inFile.seekg(byteLoc);
    inFile.read(barr, 8);

    int ptr = 0;
    int val = 0;

    // int shift = 32; // 8 bits * 4 = 4 bytes = int
    for (int i = 0; i < 4; i++){
        ptr = (ptr << 8) | static_cast<unsigned char>(barr[i]);
        val = (val << 8) | static_cast<unsigned char>(barr[i + 4]);

        // shift -= 8;
        // ptr |= static_cast<unsigned char>(barr[i]) << shift;     // just something i thought of
        // val |= static_cast<unsigned char>(barr[i + 4]) << shift; // might be faster in some cases, but reading is already way slower

        // ptr = (ptr << 8) | (barr[i] & 0xFF);     // same same... but different
        // val = (val << 8) | (barr[i + 4] & 0xFF);
    }

    delete[] barr;

    int* idx = new int[2]{
        ptr,
        val
    };

    return idx;
}

#endif
