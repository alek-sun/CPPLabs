#ifndef LIFE_INTERMODE_H
#define LIFE_INTERMODE_H

#include "../Parser/Option.h"
#include "Condition.h"
#include "../Loader/FileCondit.h"

namespace LifeGame{
    class InterMode{
        Option curCmd;
        vector<Condition> counter;
        FileCondit fileLoader;

        Condition& set(Condition &newCond, int val);
        Condition& reset(Condition &newCond);
        Condition back(Condition &newCond);
        Condition step(Condition &newCond);
        Condition setRules(Condition &newCond);
        Condition load(Condition &newCond);
        Condition save(const Condition &newCond);

        static const int ALIVE = 1;
        static const int DEAD = 0;
    public:
        InterMode();
        InterMode(FileCondit& ld);
        InterMode(const InterMode& other);
        InterMode& operator=(const InterMode& other);
        ~InterMode();

        Condition getCurCond();
        void setCmd(Option& com);
        Condition oneIter();
        void pushCondit(Condition& cond);
    };
}

#endif //LIFE_INTERMODE_H
