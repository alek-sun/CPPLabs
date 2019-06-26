#ifndef LIFE_COMMANDPARSER_H
#define LIFE_COMMANDPARSER_H
#include "../Parser/Parser.h"

namespace LifeGame{
        class CommandPrs{
            Parser comParser;
            vector<string> cinToVect(bool& exitFalg);
        public:
            CommandPrs();
            CommandPrs(vector<Option>& tmp);
            CommandPrs(const CommandPrs& other);
            CommandPrs& operator=(const CommandPrs& other);
            ~CommandPrs();
            Option cinParse(bool& exitFlag);//1 option
        };
}

#endif //LIFE_COMMANDPARSER_H
