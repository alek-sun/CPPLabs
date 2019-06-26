#include "Setter.h"
#include "../Loader/Opener.h"

namespace LifeGame{
    //DEFAULT
    Setter::Setter(): val(0) {}

    //Create setter by value and coordinate vector
    Setter::Setter(int val, vector<int> xy): val(val), xy(xy){}

    Setter::Setter(const Setter &other) {
        xy = other.xy;
        val = other.val;
        cond = other.cond;
    }

    Setter &Setter::operator=(const Setter &other) {
        xy = other.xy;
        val = other.val;
        cond = other.cond;
        return *this;
    }

    Setter::~Setter() {}

    //METHODS

    //Set value to coordinates x y
    //Accepts vector<int>  - coordinates.
    // There can be several pair of coordinates, for example <2, 3, 4, 5, 5, 1>
    //Even positions - x, odd positions - y
    vector<int> Setter::setField() {
        int x, y;
        for (vector<int>::iterator it = xy.begin(); it != xy.end(); ++it) {
            x = *it;
            ++it;
            y = *it;
            if (x >= cond.fldW || y >= cond.fldH){ // if specified coordinates outside the field
                throw std::out_of_range("Error! Specified coordinates outside the field\n");
            }
            int ind = y * cond.fldW + x;    //  index in field vector
            cond.fld[ind] = val;    // set value
        }
        return cond.fld;
    }

    //Set start condition
    void Setter::setCond(Condition c) {
        cond = c;
    }




}