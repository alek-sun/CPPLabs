#include "Option.h"
#include "ParseError.h"


namespace LifeGame {

    //  CONSTRUCTORS
    Option::Option() {
        isEmpty = true;
    }

    Option::Option(string name, string type) {
        descr.constName = name;
        descr.argType = type;
    }

    //Constructor by descriptor
    Option::Option(const Descriptor& d) {
        descr = d;
        isEmpty = true;
    }

    Option::Option(const Option &other) {
        descr = other.descr;
        intArgs = other.intArgs;
        strArgs = other.strArgs;
        isEmpty = other.isEmpty;
    }

    Option::~Option() {}

    Option &Option::operator=(const Option &other) {
        descr = other.descr;
        intArgs = other.intArgs;
        strArgs = other.strArgs;
        isEmpty = other.isEmpty;
        return *this;
    }

    //  METHODS

    //It's one of possible names of this option?
    bool Option::isName(string name) {
        for (auto &it : descr.tempNames) {
            if (name == it) {
                return true;
            }
        }
        return false;
    }

    //Parse option argumets
    //Start iterator points on option name
    void Option::parseArgs(vector<string>::iterator &it, vector<string>& v) {
        for (int i = 0; i < descr.countArgs; ++i) {
            if (it == v.end()){ // step crutch
                intArgs.push_back(1);
                isEmpty = false;
                --it;
                return;
            }
            ++it;   //  move to arguments
            string curArg = *it;
            try {
                if (descr.argType == "int") {
                    intArgs.push_back(std::stoi(curArg)); // put value in args
                }
            }catch (std::invalid_argument &err) { // stoi exeption (arguments type mistmach)
                throw ArgFormErr(getName());
            }
            catch (std::out_of_range &err) {    // stoi exeption
                throw ArgFormErr(getName());
            }
            if (descr.argType == "string") {
                strArgs.push_back(curArg);  // put string in args
            }
            if (!isValidArg(curArg)){ // there can be you'r right conditions
                throw ArgFormErr(getName());
            }
        }
        isEmpty = false; // if all arguments pushed right, set empty false
        return;
    }


    //There can be you'r right conditions for any arguments type
    bool Option::isValidArg(string arg) {
        if (descr.argType == "int") {
            return std::stoi(arg) >= 0; // the program does not have negative arguments
        }
        return true;
    }

    string Option::getName() {
        return descr.constName;
    }
    string LifeGame::Option::getType() {
        return descr.argType;
    }

    bool Option::isEmptyOpt() {
        return isEmpty;
    }

    vector<int> Option::getIntArgs() {
        return intArgs;
    }

    string Option::getStrArg(int ind) {
        return strArgs[ind];
    }

    int Option::getIntArg(int ind) {
        return intArgs[ind];
    }
}