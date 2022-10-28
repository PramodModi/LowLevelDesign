# include<iostream>
# include<string>
#include<deque>
#include<vector>
#include"Board.cpp"
#include"Player.cpp"
#include "Piece.cpp"
#include"PieceType.h"


using namespace std;

class TicTacGame{
    private:
        Board *board;
        deque<Player*> players;
        int boardSize;

    public:
        TicTacGame(int boardSize, int playerCount){
            this->boardSize = boardSize;
            board =  new Board(boardSize);
            initializePlayers(playerCount);
            

        }

        void startGame(){
            bool noWinner = true;
            int occupied = 0;
            while(noWinner){
                if(occupied == boardSize*boardSize){
                    cout<<"Game is Tie "<<endl;
                    return;
                }
                Player* currentPlayer = players.front();
                board->printBoard();
                cout<<"Player: " + currentPlayer->getName()+" Enter row :"<<endl;
                int row;
                int col;
                cin>>row;
                cout<<"Enter Column: "<<endl;
                cin>>col;
                bool placed = board->setCell(row, col, currentPlayer->getPieceType());
                if(placed == false){
                    continue;
                }
                occupied += 1;
                //board->printBoard();
                currentPlayer->setRowCount(row);
                currentPlayer->setColCount(col);
                if(row == col){
                    currentPlayer->setDiagonalCount();
                }
                if(row+col+1 == boardSize){
                    currentPlayer->setAntiDiagonalCount();
                }

                if(currentPlayer->getRowCount(row) == boardSize or 
                    currentPlayer->getColCount(col) == boardSize or
                    currentPlayer->getAntiDiagonalCount() == boardSize or
                    currentPlayer->getDiagonalCount() == boardSize){
                        noWinner = false;
                        board->printBoard();
                        cout<<"Winer is Player : "<<currentPlayer->getName()<<endl;
                    }
                players.pop_front();
                players.push_back(currentPlayer);

            }
        }

    private:
        void initializePlayers(int playerCount){
            for(int i =0; i<playerCount;i++){
                string name = "P"+to_string(i+1);
                //players.push_back(new Player("P"+to_string(i+1), new Piece(PieceIdentifier[i]), boardSize));
                players.push_back(new Player(name, new Piece(PieceIdentifier[i]), boardSize));
            }
        }

};
