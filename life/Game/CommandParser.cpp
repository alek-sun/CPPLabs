#include "CommandParser.h"
#include "../Parser/ParseError.h"

namespace LifeGame{
    //DEFAULT
    CommandPrs::CommandPrs() {}

    CommandPrs::CommandPrs(vector<Option> &tmp): comParser(tmp){}

    CommandPrs::CommandPrs(const CommandPrs &other) {
        comParser = other.comParser;
    }

    CommandPrs &CommandPrs::operator=(const CommandPrs &other) {
        comParser = other.comParser;
        return *this;
    }

    CommandPrs::~CommandPrs() {}

    //METHODS

    Option CommandPrs::cinParse(bool& exitFlag) {
        vector<string> v = cinToVect(exitFlag); // get vector<string> by cin
        Option empty;
        if (exitFlag == true)   // if exit is met
            return empty;
        vector<Option> rez = comParser.parse(v);    //  parse command from console
        int countNonEmpty = 0;
        for (auto &it : rez){   //  in parse result find not empty option
            if (!it.isEmptyOpt()){
                if (countNonEmpty != 0){    //  if entered >1 option
                    cout << "Please, enter 1 command" << endl;
                    throw ExactPrsErr();
                }
                empty = it;
                countNonEmpty++;
            }
        }
        return empty;   // return 1 non empty option
    }

    //Get vector<string> (commands) from console
    vector<string> CommandPrs::cinToVect(bool& exitFlag) {
        vector<string> command;
        string buf;
        string newStr;
        std::getline(cin, buf);
        for (auto &it : buf){   //  character-by-character reading
            if (it == '\n' || it == ' ') {
                if (!newStr.empty()) {
                    command.push_back(newStr);
                    newStr.clear();
                }
                if (it == '\n') break;
                continue;
            }
            newStr.push_back(it);
        }
        if (newStr == "exit"){ // if exit command is met
            exitFlag = true;    // set exit flag true
            return command;
        }
        command.push_back(newStr);
        return command;
    }
}