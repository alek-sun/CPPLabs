#ifndef LIFE_SETTER_H
#define LIFE_SETTER_H

//#include "../Loader/Opener.h"

#include "../Parser/Option.h"
#include "Condition.h"

namespace LifeGame{
    class Setter{
    protected:
        int val;    // setted value
        Condition cond; //  start condition
        vector<int> xy; //  coordinate vector

        static const int ALIVE = 1;
    public:
        Setter();
        Setter(int val, vector<int> xy);
        Setter(const Setter& other);
        Setter& operator=(const Setter& other);
        virtual ~Setter();
        vector<int> setField();
        void setCond(Condition c);
    };



}
#endif //LIFE_SETTER_H
