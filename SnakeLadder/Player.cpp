# include <iostream>
#include<string>

using namespace std;

class Player{
    private:
        string id;
        int position;
    public:
        Player(string id, int pos){
            this->id = id;
            this->position = pos;
        }
        int getPosition()
        {
            return position;
        }
        void setPosition(int pos){
            position = pos;
        }
        string getId(){
            return id;
        }
};