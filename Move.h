#ifndef UNTITLED2_MOVE_H
#define UNTITLED2_MOVE_H
#include <iostream>
#include <fstream>
using namespace std;
class Move{
public:
    static void move(int** mapMatrix, int** keyMatrix, int** subMatrix, int columnNumber, int rowNumber, int sizeOfKeyMatrix);
    static void multiplyMatrix(int** mapMatrix, int** keyMatrix, int** subMatrix, int columnNumber, int rowNumber, int sizeOfKeyMatrix,
                               int rowNumberOfMapMatrix,int columnNumberOfMapMatrix, ofstream& writeToFile);

};


#endif //UNTITLED2_MOVE_H
