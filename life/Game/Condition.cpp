#include "Condition.h"

namespace LifeGame{
    //Set all field DEAD
    void Condition::clearField() {
        for (auto &it : fld){
            it = DEAD;
        }
    }

    //DEFAULT
    Condition::Condition() {}

    Condition::Condition(const Condition &other) {
        m = other.m;
        n = other.n;
        k = other.k;
        fldH = other.fldH;
        fldW = other.fldW;
        fld = other.fld;
        }


    Condition &Condition::operator=(const Condition &other) {
        m = other.m;
        n = other.n;
        k = other.k;
        fldH = other.fldH;
        fldW = other.fldW;
        fld = other.fld;
        return *this;
    }

    Condition::~Condition() {}
}