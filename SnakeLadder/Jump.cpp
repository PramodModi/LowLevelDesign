#include<iostream>
using namespace std;

class Jump{
    private:
        int start;
        int end;
    public:
        int getStart(){
            return start;
        }
        int getEnd(){
            return end;
        }
        void setStart(int s){
            start = s;
        }

        void setEnd(int e){
            end = e;
        }
};