#ifndef LIFE_DRIVER_H
#define LIFE_DRIVER_H
#include "Parser/Parser.h"
#include "Game/InterMode.h"

namespace LifeGame {
    class Driver{
        vector<Option> actOpt;  // options for game
        vector<Option> defVal;  // default options
        //Options Templates:
        vector<Option> consOptTmp; // for console
        vector<Option> fileOptTmp;  // for file
        vector<Option> interOpt;    // for interactive mode
        //Set templates:
        void consoleOptTmp();
        void fileOptTemp();
        void getDefVal();
        void getInterOpt();
    public:
        Driver();
        Driver(const Driver& other);
        Driver& operator=(const Driver& other);
        ~Driver();
        //------------------------------------
        void launch(char** argv, int argc); // launch game
        void launchAuto(char**argv, int argc);
        void launchInteractive();
        //void printConsOpt();
        //void printOpt(vector<Option>);
    };
}
#endif //LIFE_DRIVER_H
