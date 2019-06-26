#include "Opener.h"

namespace LifeGame {
    //DEFAULT
    Opener::Opener() {
        val = ALIVE;
    }

    Opener::Opener(const Opener &other) {
        val = ALIVE;
        opt = other.opt;
        cond = other.cond;
    }

    //Create by vector of openable options
    Opener::Opener(vector<Option> o) {
        opt = o;
        val = ALIVE;
    }

    Opener &Opener::operator=(const Opener &other) {
        opt = other.opt;
        cond = other.cond;
        return *this;
    }

    Opener::~Opener() {}


    //METHODS

    //Change rules and field size
    void Opener::changeCond() {
        cond.m = getArg("m", cond.m, 0);    //   get m value
        cond.n = getArg("n", cond.n, 0);    //  get n value
        cond.k = getArg("k",cond.k, 0);     //  get k value
        cond.fldW = getArg("field size", cond.fldW, 0); //  get field height
        cond.fldH = getArg("field size", cond.fldH, 1); // get field width
        cond.fld.resize(cond.fldW*cond.fldH);   // resize by new size
    }

    //Get new condition
    Condition Opener::getCond() {
        changeCond();   // change rules and field size
        getXY();    //  get coordinates from option SET
        cond.fld = setField();  //  set ALIVE on (x,y)
        return cond;    //new condition
    }

    //Get 1 int argument by option name and argument index in option's args
    // ficktive argument for returning oneself if option not found in option set
    int Opener::getArg(string optName, int fick, int ind) {
        for (auto &it: opt) {
            if (it.getName() == optName && !it.isEmptyOpt()) {
                return it.getIntArg(ind);
            }
        }
        return fick;
    }

    //Set opened options
    void Opener::setOpt(vector<Option> &otherOpt) {
        opt = otherOpt;
    }

    //Get 1 string argument from options by ame of option
    string Opener::getStrArg(string optName) {
        for (auto &it: opt) {
            if (it.getName() == optName && !it.isEmptyOpt()) {
                return it.getStrArg(0);
            }
        }
        return "";
    }

    //Get vector of coordinates from SET option
    void Opener::getXY() {
        for (auto &it: opt) {
            if (it.getName() == "set") {
                xy = it.getIntArgs();
            }
        }
        return;
    }
}