//
// Created by user on 23.10.2022.
//
#include "Move.h"
#include <iostream>
using namespace std;

     void Move::move(int** mapMatrix, int** keyMatrix, int** subMatrix, int columnNumber, int rowNumber, int sizeOfKeyMatrix){ //Function to change submatrix's elements when the submatrix is moved to another place on map
        for(int i=0;i<sizeOfKeyMatrix;i++) {
            for (int j = 0; j < sizeOfKeyMatrix; j++) {
                subMatrix[i][j]=mapMatrix[rowNumber-(sizeOfKeyMatrix/2)+i][columnNumber-(sizeOfKeyMatrix/2)+j];
            }
        }
    }

     void Move::multiplyMatrix(int** mapMatrix, int** keyMatrix, int** subMatrix, int columnNumber, int rowNumber, int sizeOfKeyMatrix,int rowNumberOfMapMatrix,
                               int columnNumberOfMapMatrix, ofstream& writeToFile){  //Function to multiply KeyMatrix and SubMatrix and take an action
        writeToFile<<rowNumber<<","<<columnNumber<<":"; //Writes to output the informations of rownumber and columnnumber

        int multipication = 0;
        for(int i=0;i<sizeOfKeyMatrix;i++) { //For loop to multiply keymatrix and submatrix
            for (int j = 0; j < sizeOfKeyMatrix; j++) {
                int a = (subMatrix[i][j])*(keyMatrix[i][j]);
                multipication += a;
            }
        }
        writeToFile<<multipication<<endl;

        int remaining = multipication % 5;
        while (remaining<0){
            remaining+=5;
        }

        if (remaining==1){
            if (rowNumber==(sizeOfKeyMatrix/2)){ //This means if there is no more up
                rowNumber+=sizeOfKeyMatrix;
                Move::move(mapMatrix,keyMatrix,subMatrix,columnNumber,rowNumber, sizeOfKeyMatrix);
            }
            else{
                rowNumber-=sizeOfKeyMatrix;
                Move::move(mapMatrix, keyMatrix, subMatrix, columnNumber, rowNumber, sizeOfKeyMatrix);
            }
        }
        else if (remaining==2){
            if (rowNumber+1==rowNumberOfMapMatrix-(sizeOfKeyMatrix/2)){ //This means if there is no more down
                rowNumber-=sizeOfKeyMatrix;
                Move::move(mapMatrix, keyMatrix, subMatrix, columnNumber, rowNumber, sizeOfKeyMatrix);
            }
            else{
                rowNumber+=sizeOfKeyMatrix;
                Move::move(mapMatrix,keyMatrix,subMatrix,columnNumber,rowNumber, sizeOfKeyMatrix);
            }
        }
        else if (remaining==3){
            if (columnNumber+1==columnNumberOfMapMatrix-(sizeOfKeyMatrix/2)){ //This means if there is no more right
                columnNumber-=sizeOfKeyMatrix;
                Move::move(mapMatrix,keyMatrix,subMatrix,columnNumber,rowNumber, sizeOfKeyMatrix);
            }
            else {
                columnNumber+=sizeOfKeyMatrix;
                Move::move(mapMatrix, keyMatrix, subMatrix, columnNumber, rowNumber, sizeOfKeyMatrix);
            }
        }
        else if (remaining==4){
            if (columnNumber==(sizeOfKeyMatrix/2)){ //This means if there is no more left
                columnNumber+=sizeOfKeyMatrix;
                Move::move(mapMatrix,keyMatrix,subMatrix,columnNumber,rowNumber, sizeOfKeyMatrix);
            }
            else {
                columnNumber-=sizeOfKeyMatrix;
                Move::move(mapMatrix, keyMatrix, subMatrix, columnNumber, rowNumber, sizeOfKeyMatrix);
            }
        }

        if (remaining!=0){ //If remaining is not 0 the program will continue with recursion
            multiplyMatrix(mapMatrix,keyMatrix,subMatrix,columnNumber,rowNumber,
                           sizeOfKeyMatrix, rowNumberOfMapMatrix,columnNumberOfMapMatrix,writeToFile);
        }
        else if (remaining==0){ //If remaining is zero ı will close writeToFile and end the program
            writeToFile.close();
            for (int i = 0; i < sizeOfKeyMatrix; i++) {
                delete[] keyMatrix[i];
            }
            delete[] keyMatrix;
            for (int i = 0; i < sizeOfKeyMatrix; i++) {
                delete[] subMatrix[i];
            }
            delete[] subMatrix;
            for (int i = 0; i < rowNumberOfMapMatrix; i++) {
                delete[] mapMatrix[i];
            }
            delete[] mapMatrix;
        }
    }

