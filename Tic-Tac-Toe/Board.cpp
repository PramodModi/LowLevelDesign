#include<iostream>
#include "Cell.h"

using namespace std;

#define MAX_SIZE  10

class Board{
    private:
        int size;
        Cell ***cells = new Cell** [MAX_SIZE];
    public:
        Board(int size){
            this->size = size;
            initializeBoard();
        }

        bool setCell(int row, int col, Piece* p){
            if(row<0 || col < 0 || row>= size || col>= size){
                cout<<"invalid move !!!"<<endl;
                return false;
            }
            if(cells[row][col]->piece != NULL){
                cout<<"Cell is not empty !!! Invalid move."<<endl;
                return false;
            }
            
            cells[row][col]->piece = p;
            
            return true;   
        }

        void printBoard(){
            for(int i =0; i<size;i++){
                for(int j = 0; j<size; j++){
                    cout<<"| ";
                    if (cells[i][j]->piece != NULL)
                        cout<<cells[i][j]->piece->pieceType<<" ";
                    else
                        cout<<"  ";
                }
                cout<<"| "<<endl;
            }
        }

    private:
        void initializeBoard(){
            for(int i =0; i<size;i++)
            {
                cells[i] = new Cell*[size];
                for(int j = 0; j<size; j++)
                    cells[i][j] = new Cell();
            }
        }

};