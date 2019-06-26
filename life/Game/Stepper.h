#ifndef LIFE_STEPPER_H
#define LIFE_STEPPER_H

#include "Condition.h"

namespace LifeGame{
    class Stepper{
        Condition cond; //  start condition
        int count;  //step count

        static const int LIVE = 1;
        static const int DEAD = 0;

        void changeFld();
        int getX(int numb);
        int getY(int numb);
        int liveNeigh(int x, int y);
        bool isLive(int x, int y, int dx, int dy);
    public:
        Stepper();
        Stepper(Condition start, int stepCount);
        Stepper(const Stepper& other);
        Stepper& operator=(const Stepper& other);
        virtual ~Stepper();
        Condition start();
    };
}

#endif //LIFE_STEPPER_H
