#include "ParseError.h"


ExactPrsErr::ExactPrsErr() : wt("") {}
ExactPrsErr::ExactPrsErr(const string what) : wt(what) {}

string ExactPrsErr::what() {
    return wt;
}


CountArgErr::CountArgErr() {}
CountArgErr::CountArgErr(string name, int argC, string type) {
    optName = name;
    argCount = argC;
    argType = type;
}

void CountArgErr::what() {
    cout << "Expected flag for " << optName << " and "<< argCount <<
        " arguments of type <" << argType << ">, but failed to parse." << endl;
}


ArgFormErr::ArgFormErr() {}
ArgFormErr::ArgFormErr(const string name) {
    optName = name;
}

void ArgFormErr::what() {
    cout << "Incorrect argument form in option " << optName << endl;
}


RepeitFlags::RepeitFlags() {}
RepeitFlags::RepeitFlags(string name) {
    optName = name;
}

void RepeitFlags::what() {
    cout << "Repeit flags " << optName << endl;
}

