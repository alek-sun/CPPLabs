#ifndef LIFE_LOADER_H
#define LIFE_LOADER_H

#include "../Parser/Parser.h"
#include "../stuff.h"
#include "../Game/Condition.h"

namespace LifeGame {
    class Loader {
        Parser filePrs; //  parser for file
        vector<Option> prsFileRes;  // parsing result
        string fileName;    //  name of load file

        //methods------------------
        void openRules();
        bool isRepeit(string s, vector<string> v);
        vector<string> fileToVect();
        bool addOpt(std::ifstream &in, char c, string &opt, vector<string> &res);
    public:
        vector<Option> getOptions();
        void setFileName(string name);
        void clear();

        Loader();
        Loader(vector<Option> &temp);
        Loader(const Loader &other);
        Loader &operator=(const Loader &other);
        ~Loader();
    };



}
#endif //LIFE_LOADER_H
