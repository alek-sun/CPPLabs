#ifndef LIFE_PARSEALL_H
#define LIFE_PARSEALL_H

#include "Parser.h"
#include "../Loader/Loader.h"

namespace LifeGame {
    class ParseAll {
        Parser consParse;
        Loader loader;
        vector<Option> defVal;

        vector<string> convertToVect(char **argv, int argc);
        string getInputFile(vector<Option> consArgs);
        vector<Option> uniteArgs(vector<Option>& consOpt, vector<Option>& fileOpt);
        Option pasteOpt(Option& empty, vector<Option>& fileOpt);
        void addDef(vector<Option>& consOpt, vector<Option>& defOpt);
    public:
        ParseAll();
        ParseAll(vector<Option> consOptTmp,
                 vector<Option> fileOptTmp,
                 vector<Option> defVal);
        ParseAll(const ParseAll& other);
        ParseAll& operator=(const ParseAll& other);
        ~ParseAll();

        vector<Option> prsAll(char **argv, int argc);
    };
}
#endif //LIFE_PARSEALL_H
