#ifndef LIFE_CONDITION_H
#define LIFE_CONDITION_H
#include "../stuff.h"
namespace LifeGame {
    class Condition {
        //rules
        int m;
        int n;
        int k;
        //field
        int fldH;   // field height
        int fldW;   //  field width
        vector<int> fld;    // field: 0 - dead, 1 - life
        //friends
        friend class Opener;
        friend class Setter;
        friend class InterMode;
        friend class FileExport;
        friend class Stepper;
        friend class ConsExport;
        //const
        static const int DEAD = 0;
    public:
        Condition();
        Condition(const Condition &other);
        Condition &operator=(const Condition &other);
        ~Condition();
        void clearField();
    };
}
#endif //LIFE_CONDITION_H
