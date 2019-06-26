#ifndef LIFE_DESCRIPTOR_H
#define LIFE_DESCRIPTOR_H
#include "../stuff.h"

namespace LifeGame {
    class Descriptor {
        string constName; // assigned for all options this sense
        string optDescr;    //  description
        vector<string> tempNames;   // possible names
        int countArgs;  //  count of arguments
        string argType; //  argument type

        //methods
        void printNames();
        void printArgs();
        //friends
        friend class Option;
        friend class Parser;
        friend class Driver;
    public:
        Descriptor();
        Descriptor(string nm, vector<string> tmpNm, string desc, int argc, string type);
        Descriptor(const Descriptor &other);
        ~Descriptor();
        Descriptor &operator=(const Descriptor &other);
        void print();
    };
}

#endif //LIFE_DESCRIPTOR_H
