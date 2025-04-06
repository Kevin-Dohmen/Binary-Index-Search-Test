#ifndef WRITEINDEXTOFILE_H
#define WRITEINDEXTOFILE_H

#include <fstream>
#include <iostream>

int WriteToFile(int** index, int rows, std::ofstream& outFile, int startPos = 0){
    int byteCount = rows * 8;
    char* barr = new char[byteCount];

    for (int i = 0; i < rows; i++){
        int ptr = index[i][0];
        int val = index[i][1];
        
        for (int j = 0; j < 4; j++){
            int shift = 8 * (3 - j);
            int arrPos = i * 8 + j;

            barr[arrPos] = (ptr >> shift) & 0xFF;
            barr[arrPos + 4] = (val >> shift) & 0xFF;
        }
    }

    int byteLoc = startPos * 8;

    outFile.seekp(byteLoc); // Move to the beginning of the file
    outFile.write(barr, byteCount);

    delete[] barr;

    return 0;
}

#endif
