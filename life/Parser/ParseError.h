#ifndef LIFE_PARSEERROR_H
#define LIFE_PARSEERROR_H
#include "../stuff.h"

//For errors in option name
class ExactPrsErr {
    string wt;
public:
    ExactPrsErr();
    ExactPrsErr(const string what);
    string what();
};

//For errors in arguments form
class ArgFormErr{
protected:
    string optName;
public:
    ArgFormErr();
    ArgFormErr(string name);
    virtual void what();
};

//For repeit flags errors
class RepeitFlags{
    string optName;
public:
    RepeitFlags();
    RepeitFlags(string name);
    void what();
};

//For errors in srgument count
class CountArgErr: public ArgFormErr {
    int argCount;
    string argType;
public:
    CountArgErr();
    CountArgErr(string optName, int argCount, string argType);
    void what();
};
#endif //LIFE_PARSEERROR_H
