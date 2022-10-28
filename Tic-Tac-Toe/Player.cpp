#include<iostream>
#include <string>
#include<list>
# include "Piece.cpp"

# define SIZE 10
using namespace std;

class Player{
    private:
        string name;
        Piece *piecetype;

        // This is O(1) way to check if player win or not.
        int rowCount [SIZE];
        int colCount [SIZE];
        int diagonalCount;
        int antiDiagonalCount;
    public:
        Player(string name, Piece *piecetype, int size){
            this-> name = name;
            this->piecetype = piecetype;
            for(int i =0; i<size; i++){
                rowCount[i] = 0;
                colCount[i] = 0;
            }
            diagonalCount =0;
            antiDiagonalCount = 0;
        }
        string getName(){
            return name;
        }
        Piece* getPieceType(){
            return piecetype;
        }
        void setRowCount(int row){
            rowCount[row] += 1;
        }
        int getRowCount(int row){
            return rowCount[row];
        }
        void setColCount(int col){
            colCount[col] += 1;
        }
        int getColCount(int col){
            return colCount[col];
        }
        void setDiagonalCount(){
            diagonalCount += 1;
        }
        int getDiagonalCount(){
            return diagonalCount;
        }
        void setAntiDiagonalCount(){
            antiDiagonalCount += 1;
        }
        int getAntiDiagonalCount(){
            return antiDiagonalCount;
        }

};