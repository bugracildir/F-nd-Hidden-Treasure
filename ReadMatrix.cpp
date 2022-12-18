//
// Created by user on 24.10.2022.
//
#include <iostream>
#include <algorithm>
#include <string>
#include "ReadMatrix.h"
using namespace std;

       void ReadMatrix::ReadMapMatrix(string mapName, string keyName, string output){ //Function to read map and create a matrix
        std::string line;
        std::ifstream readFile2(mapName);

        int rowNumberOfMapMatrix = 0;
        int columnNumberOfMapMatrix = 0;
        while (getline (readFile2, line)){ // While loop to find row number and column number of matrix
            rowNumberOfMapMatrix++;
            columnNumberOfMapMatrix = (line.size()/2)+1;
        }
        readFile2.close();
        std::ifstream readFile(mapName);

        int** MapMatrix = new int*[rowNumberOfMapMatrix];  //For loop to create MapMatrix
        for(int i=0;i<rowNumberOfMapMatrix;i++)
            MapMatrix[i] = new int[columnNumberOfMapMatrix];


        for (int i = 0; i < rowNumberOfMapMatrix; i++) { // And this for loop is for taking the elements from map and save them to my MapMatrix
            getline (readFile, line);
            std::stringstream sstream;
            sstream << line;
            int temp;
            for (int j = 0; j < columnNumberOfMapMatrix; j++) {
                sstream >> temp;
                MapMatrix[i][j] = temp;
            }

        }

        readFile.close();

        int sizeOfKeyMatrix;
        int** KeyMatrix;
        int** SubMatrix;

        ReadMatrix::ReadKeyMatrix(KeyMatrix, MapMatrix, SubMatrix,sizeOfKeyMatrix, rowNumberOfMapMatrix, columnNumberOfMapMatrix, keyName, output);
    }

     void ReadMatrix::ReadKeyMatrix(int** KeyMatrix ,int** MapMatrix, int** SubMatrix, int sizeOfKeyMatrix,
                              int rowNumberOfMapMatrix, int columnNumberOfMapMatrix, string keyName, string output){  //Function to read KeyMatrix and save them into KeyMatrix
        std::string line2;
        std::ifstream readFile2(keyName);

        getline (readFile2, line2);
        readFile2.close();

        sizeOfKeyMatrix=0;
        for (int i = 0; i < line2.size(); i++) { //For loop to find keymatrix's size
            if(line2[i]==' '){
                sizeOfKeyMatrix++;
            }
        }
        sizeOfKeyMatrix++;

        KeyMatrix = new int*[sizeOfKeyMatrix]; //For loop to create KeyMatrix
        for(int i=0;i<sizeOfKeyMatrix;i++)
            KeyMatrix[i] = new int[sizeOfKeyMatrix];
        readFile2.close();

        std::ifstream readFile3(keyName);

        for (int i = 0; i < sizeOfKeyMatrix; i++) { //Saving the elements on keymatrix.txt to my KeyMatrix
             getline (readFile3, line2);
             std::stringstream sstream2;
             sstream2 << line2;
             int temp;
             for (int j = 0; j < sizeOfKeyMatrix; j++) {
                 sstream2 >> temp;
                 KeyMatrix[i][j] = temp;
             }
         }

        readFile3.close();

        SubMatrix = new int*[sizeOfKeyMatrix]; // For loop to create SubMatrix which will be sized as KeyMatrix and I will multiply them
        for(int i=0;i<sizeOfKeyMatrix;i++) {
            SubMatrix[i] = new int[sizeOfKeyMatrix];
            for (int j = 0; j < sizeOfKeyMatrix; j++) {
                SubMatrix[i][j] = MapMatrix[i][j];
            }
        }

        int centerRowNumber = (sizeOfKeyMatrix/2), centerColumnNumber = (sizeOfKeyMatrix/2); //I took the element on the middle as center and these are the coordinates
        ofstream writeToFile(output);
        Move::multiplyMatrix(MapMatrix,KeyMatrix,SubMatrix,centerColumnNumber,centerRowNumber,
                             sizeOfKeyMatrix, rowNumberOfMapMatrix,columnNumberOfMapMatrix,writeToFile); //The function which will multiply keymatrix and submatrix
    }


