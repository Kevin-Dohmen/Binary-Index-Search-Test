#ifndef WRITE_TO_FILE_H
#define WRITE_TO_FILE_H

#include <fstream>
#include <iostream>

int WriteToFile(int** index, int rows, std::ofstream& outFile, int startPos = 0);

#endif
