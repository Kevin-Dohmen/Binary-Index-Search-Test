#include <fstream>
#include <iostream>

int WriteToFile(int index, int ptr, int val, std::ofstream& outFile){
    char barr[8];
    for (int i = 0; i < 4; i++){
        int shift = 8*(3-i);
        barr[i] = (ptr>>shift) & 0xFF;
        barr[i+4] = (val>>shift) & 0xFF;
    }

    int byteLoc = index * 8;

    outFile.seekp(byteLoc); // Move to the beginning of the file
    outFile.write(barr, 8);

    return 0;
}
