#include <fstream>
#include <iostream>

int ReadFromFile(int index, std::ifstream& inFile){
    int byteLoc = index * 8;

    char barr[8];

    inFile.seekg(byteLoc); // Move to the specified location in the file
    inFile.read(barr, 8);  // Read 8 bytes from the file into barr

    int ptr = 0;
    int val = 0;

    for (int i = 0; i < 4; i++){
        int shift = 8*(3-i);
        ptr = (ptr<<8) + barr[i];
        val = (val<<8) + barr[i+4];
    }

    std::cout << ptr << std::endl;
    std::cout << val << std::endl;

    return 0; // how return?? struct?? tuple?
}
