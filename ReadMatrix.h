#ifndef UNTITLED2_READMATRIX_H
#define UNTITLED2_READMATRIX_H
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <sstream>
#include "Move.h"
class ReadMatrix {
public:
    static void ReadMapMatrix(string mapName, string keyName, string output);

    static void ReadKeyMatrix(int **KeyMatrix, int **MapMatrix, int **SubMatrix, int sizeOfKeyMatrix,
                              int rowNumberOfMapMatrix, int columnNumberOfMapMatrix, string keyName, string output);
};
#endif //UNTITLED2_READMATRIX_H
