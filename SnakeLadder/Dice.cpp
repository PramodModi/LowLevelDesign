# include <iostream>
# include "utility.h"


using namespace std;

class Dice{
    private:
        int diceCount;
        int min;
        int max;

    public:
        Dice(int diceCount = 1)
        {
            min = 1;
            max = 6;
            this->diceCount = diceCount;
        }
        int rollDice(){
            int totalSum = 0;
            int diceUsed = 0;

            while (diceUsed < diceCount){
                totalSum += randomNumber(min, max);
                diceUsed += 1;
            }
            return totalSum;
        }
};