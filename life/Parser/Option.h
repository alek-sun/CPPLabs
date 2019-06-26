#ifndef LIFE_OPTION_H
#define LIFE_OPTION_H
#include "../stuff.h"
#include "Descriptor.h"
namespace LifeGame {
    class Option {
        Descriptor descr;
        bool isEmpty;   //  is filled option?
        vector<int> intArgs;    // int arguments
        vector<string> strArgs; //  string arguments

        friend class Parser;
        friend class Driver;
        friend class Descriptor;
        friend class Loader;

        bool isValidArg(string arg);
    public:
        bool isEmptyOpt();
        bool isName(string name);
        void parseArgs(vector<string>::iterator &it, vector<string>& v);
        string getName();
        string getType();
        vector<int> getIntArgs();
        string getStrArg(int ind);
        int getIntArg(int ind);
        //-------------------------
        Option();
        Option(string name, string type);
        Option(const Descriptor& d);
        Option(const Option &other);
        Option &operator=(const Option &other);
        ~Option();
    };

}

#endif //LIFE_OPTION_H
