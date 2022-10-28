# include "Cell.cpp"
# include "utility.h"

# define BOARD_SIZE 100

class Board{
    private:
        int size;
        Cell*** cells = new Cell** [BOARD_SIZE];
    public:
        Board(int size, int numberOfSnake, int numberOfLadder){
            this->size = size;
            initializeCells();
            addJump(numberOfSnake, true);
            addJump(numberOfLadder, false);
        }

        int getSize(){
            return size;
        }

        void initializeCells(){
            for(int i = 0; i<size;i++){
                cells[i] = new Cell*[size];
                for(int j= 0; j<size;j++){
                    cells[i][j] = new Cell();
                }
            }
        }
        // Add snake and ladders in the cells.
        void addJump(int number, bool isSnake){
            while(number > 0){
                int startPos = randomNumber(1, size * size -2 );
                int endPos = randomNumber(1, size * size -2);

                //If it is snake then start pos should be greater than end pos
                if(isSnake == true and startPos <= endPos){
                    continue;
                }
                //if it is ladder then start pos should be smaller than end pos
                if(isSnake == false and startPos >= endPos){
                    continue;
                }
                //cout<<"Startposition = "<<startPos<<endl;
                Jump * jump = new Jump();
                jump->setStart(startPos);
                jump->setEnd(endPos);

                Cell * cell = getCell(startPos);
                cell->jump = jump;
                number -= 1;
            }
        }

        Cell * getCell(int pos){
            int row = pos/size;
            int col = pos%size;
            if (row %2 != 0)
                col = (size-1) -col;
            return cells[row][col];
        }

};