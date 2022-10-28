#include <deque>
# include<list>
#include "Board.cpp"
#include "Dice.cpp"
#include "Player.cpp"

using namespace std;

class Game{
    private:
        Board * board;
        Dice * dice;
        deque<Player*> players;
        list<string> winners;
    public:
        Game(int boardSize, int numOfDice, int snakes, int ladders, int players){
            board = new Board(boardSize, snakes,ladders);
            dice = new Dice(numOfDice);
            addPlayers(players);
        }

        void startGame(){
            cout<<"Game is starting"<<endl;
            while(winners.size() < 3){
                Player * currentPlayer = getPlayer();
                cout<< "Current player : "<<currentPlayer->getId()<<" : ";
                cout<<"Position = "<<currentPlayer->getPosition()<<endl;

                int diceNumber = dice->rollDice();
                cout<<"Dice number = "<<diceNumber<<endl;

                int playerNewPosition = currentPlayer->getPosition() + diceNumber;
                int boardSize  = board->getSize();
                if(playerNewPosition == boardSize*boardSize-1)
                {
                    winners.push_back(currentPlayer->getId());
                    cout<<"We got the winner : "<<currentPlayer->getId()<<endl;
                    players.pop_back();
                }
                else if(playerNewPosition < boardSize*boardSize-1){
                    //cout<<"Player new position = "<<playerNewPosition<<endl;
                    playerNewPosition = getPlayerPosition(playerNewPosition);
                    currentPlayer->setPosition(playerNewPosition);
                }                

            }

            cout<<"Game end"<<endl;
        }
    private:
        void addPlayers(int num){
            for(int i =0; i<num; i++){
                Player* player = new Player("p"+to_string(i+1), 0);
                players.push_back(player);
            }
        }
        Player* getPlayer(){
            Player* p = players.front();
            players.pop_front();
            players.push_back(p);
            return p;
        }

        int getPlayerPosition(int currentPos){
            Cell * cell = board->getCell(currentPos);
            // cout<<"Getting player position"<<endl;
            // if(cell->jump == NULL)
            //     cout<<"No Snake and no ladder at poition : "<<currentPos<<endl;
            // else
            //     cout<<"Snake or ladder at poition : "<<cell->jump->getStart()<< "but I am at: "<< currentPos<<endl;
            if(cell->jump != NULL && cell->jump->getStart() == currentPos){
                int endPos = cell->jump->getEnd();
                if (currentPos> endPos)
                    cout<<"Alas !!!  Snake bitten me, I am going down from: "<<currentPos<<" to "<<endPos<<endl;
                else
                    cout<<" Wow!!! I got the ladder, going up from: "<<currentPos<<" to "<<endPos<<endl;
                return cell->jump->getEnd();
            }
            else{
                return currentPos;
            }
        }


};