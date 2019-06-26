#include "Stepper.h"

namespace LifeGame{

    //DEFAULT

    Stepper::Stepper():count(0){}

    Stepper::Stepper(const Stepper &other) {
        cond = other.cond;
        count = other.count;
    }

    Stepper &Stepper::operator=(const Stepper &other) {
        cond = other.cond;
        count = other.count;
        return *this;
    }

    Stepper::~Stepper() {}

    //Create stepper by condition and step count
    Stepper::Stepper(Condition start, int stepCount) {
        cond = start;
        count = stepCount;
    }

    //METHODS

    //Step n
    Condition Stepper::start() {
        int i;
        for (i = 0; i < count; ++i){
            changeFld();
        }
        return cond;
    }

    //Check 8 heighbors of cell (x,y) and count living
    int Stepper::liveNeigh(int x, int y) {
        int count = 0; // count of live neighbors
        if (isLive(x, y, 1, 0)){
            count++;
        }
        if (isLive(x, y, -1,0)){
            count++;
        }
        if (isLive(x, y, 0,1)){
            count++;
        }
        if (isLive(x, y, 0,-1)){
            count++;
        }
        if (isLive(x, y, 1,1)){
            count++;
        }
        if (isLive(x, y, 1,-1)){
            count++;
        }
        if (isLive(x, y, -1,1)){
            count++;
        }
        if (isLive(x, y, -1,-1)){
            count++;
        }
        return count;
    }

    //Get x coordinate by index in field vector
    int Stepper::getX(int numb) {
        return numb % cond.fldW;
    }

    //Get y coordinate by index in field vector
    int Stepper::getY(int numb) {
        return numb / cond.fldW;
    }

    //Change field by rules m n k
    void Stepper::changeFld() {
        vector<int> newFld = cond.fld;  // copy current field
        int num = 0;    // index in field vector
        for (auto &it : cond.fld){
            if (it == DEAD){    // if cell (x,y) dead
                if (liveNeigh(getX(num), getY(num)) == cond.m){     // if cell (x,y) have m neighbors
                    newFld[num] = LIVE;     // set it LIVE
                }
                num++;
                continue;
            }
            if (it == LIVE){    // if cell (x,y) alive
                if (liveNeigh(getX(num), getY(num)) < cond.n){  // if cell (x,y) have <n neighbors
                    newFld[num] = DEAD;
                }
                if (liveNeigh(getX(num), getY(num)) > cond.k){  // if cell (x,y) have >k neighbors
                    newFld[num] = DEAD;
                }
                num++;
            }
        }
        cond.fld = newFld;  //  update field
    }

    //Check live in cell from coordinates (x,y) by shift on x (dx) and y (dy)
    // dx: -1 left, 1 right
    // dy: -1 down, 1 up
    bool Stepper::isLive(int x, int y, int dx, int dy) {
        int torX = (x + dx + cond.fldW) % cond.fldW;    // toroidal x with shift
        int torY = (y + dy + cond.fldH) % cond.fldH;    // toroidal y with shift
        int num = torY * cond.fldW + torX;  //  index in field vector
        return cond.fld[num] == LIVE;
    }
}