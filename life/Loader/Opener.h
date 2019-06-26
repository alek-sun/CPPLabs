#ifndef LIFE_OPENER_H
#define LIFE_OPENER_H

#include "../Parser/Option.h"
#include "../Game/Condition.h"
#include "../Game/Setter.h"

namespace LifeGame {
    class Opener: public Setter {
        vector<Option> opt; // openable option
        void changeCond();
    public:
        Opener();
        Opener(const Opener& other);
        Opener(vector<Option>);
        Opener& operator=(const Opener& other);
        ~Opener();
        //---------------------
        void getXY();
        void setOpt(vector<Option>& opt);
        string getStrArg(string optName);
        int getArg(string optName, int fickArg, int ind);
        Condition getCond();
    };
}
#endif //LIFE_OPENER_H
