#include "writeToFile.h"

int WriteToFile(int** index, int rows, std::ofstream& outFile, int startPos){
    int byteCount = rows * 8;
    char* barr = new char[byteCount];

    for (int i = 0; i < rows; i++){
        int ptr = index[i][0];
        int val = index[i][1];

        int arrPos = i * 8;
        int shift = 8 * 3;

        for (int j = 0; j < 4; j++){
            barr[arrPos] = (ptr >> shift) & 0xFF;
            barr[arrPos + 4] = (val >> shift) & 0xFF;

            arrPos += 1;
            shift -= 8;
        }
    }

    int byteLoc = startPos * 8;

    outFile.seekp(byteLoc);
    outFile.write(barr, byteCount);

    delete[] barr;

    return 0;
}
