#include "Driver.h"
#include "Parser/ParseAll.h"
#include "Export/Exporter.h"
#include "Game/CommandParser.h"
#include "Parser/ParseError.h"
#include "Game/Stepper.h"

namespace LifeGame{
    //DEFAULT
    Driver::Driver() {}

    Driver::Driver(const Driver &other) {
        actOpt = other.actOpt;
        consOptTmp = other.consOptTmp;
        fileOptTmp = other.fileOptTmp;
        defVal = other.defVal;
        interOpt = other.interOpt;
    }

    Driver &Driver::operator=(const Driver &other) {
        actOpt = other.actOpt;
        consOptTmp = other.consOptTmp;
        fileOptTmp = other.fileOptTmp;
        defVal = other.defVal;
        interOpt = other.interOpt;
        return *this;
    }

    Driver::~Driver() {}

    //METHODS
    void Driver::launch(char** argv, int argc) {
        fileOptTemp(); //   get option templates
        getDefVal();    //  get options with default values
        if (argc == 1) {//  interactive mode
            launchInteractive();
        }
        else{ // auto mode
            launchAuto(argv, argc);
        }
    }

    void Driver::launchInteractive() {
        getInterOpt(); // set interactive optio template
        FileCondit loader(fileOptTmp);  //  create loader by file option template
        InterMode game(loader); //  create game with loader
        Opener defOpen(defVal); // opener for default condition
        Condition def = defOpen.getCond();  // get default condition
        game.pushCondit(def);   //  put start condition in game condition couter
        ConsExport startExp(game.getCurCond()); //  export start condition in console
        startExp.consOut();
        Option cmd; // for current command
        bool exitFlag = false;  // for exit from interactive mode
        while (1) {
            try {
                CommandPrs interParser(interOpt);   //  create command parser
                cmd = interParser.cinParse(exitFlag);   // get command from console
                if (exitFlag){
                    break;
                }
                game.setCmd(cmd);   // send current command to game
                Condition c = game.oneIter();   // launch game and get new condition
                ConsExport exporter(c);     // create exporter for new condition
                exporter.consOut(); // output in console
            } catch (ExactPrsErr &err) {
                cout << "Incorrect command" << endl;
            }
            catch (CountArgErr &err) {
                cout << "Incorrect count of arguments" << endl;
            }
            catch (ArgFormErr &err) {
                err.what();
            }
            catch (RepeitFlags &err) {
                err.what();
            }
            catch (std::logic_error &err) {
                cout << err.what();
            }
        }
    }

    void Driver::launchAuto(char**argv, int argc) {
        consoleOptTmp();    //  get console option templates
        ParseAll parser(consOptTmp, fileOptTmp, defVal);    //  create parser by templates
        actOpt = parser.prsAll(argv, argc); //  get options from file and console + default values
        Opener openStart(actOpt);   //  opener for start condition
        Condition start = openStart.getCond();  //  get condition from actual option
        int itCount = openStart.getArg("iteration count", 0, 0);   //  get iteration count (get 0 argument in iteration count option)
        string outFile = openStart.getStrArg("output file");    // get output file name
        Stepper game(start, itCount);   //  send to stepper start condition and steps count
        Condition finish = game.start();    //  launch auto mode and get finish condition
        FileExport out(finish, outFile);    //  create file exporter by finish condition and output file name
        out.saveToFile();   //   export in file
    }

    //Create console option templates
    void Driver::consoleOptTmp() {
        Descriptor d1(
                "iteration count",
                {"-ic", "--iterations"},
                "count of iterations in life game",
                1,
                "int");
        Option o1(d1);
        consOptTmp.push_back(o1);

        Descriptor d2(
                "field size",
                {"-f", "--field"},
                "size of game field: width and height",
                2,
                "int");
        Option o2(d2);
        consOptTmp.push_back(o2);

         Descriptor d3(
                "input file",
                {"-if", "--input"},
                "file with the start state of the field and rules",
                1,
                "string");
        Option o3(d3);
        consOptTmp.push_back(o3);

        Descriptor d4(
                "output file",
                {"-o", "--output"},
                "file for writing final state of the field",
                1,
                "string");
        Option o4(d4);
        consOptTmp.push_back(o4);

        Descriptor d5(
                "m",
                {"-m"},
                "if the dead cell has exactly m neighbors-living cells, then the next move in her life is born",
                1,
                "int");
        Option o5(d5);
        consOptTmp.push_back(o5);

        Descriptor d6(
                "n",
                {"-n"},
                "if a living cell has less than n living neighbors, then it dies of being alone",
                1,
                "int");
        Option o6(d6);
        consOptTmp.push_back(o6);

        Descriptor d7(
                "k",
                {"-k"},
                "if a living cell has more than k living neighbors, then it dies from overpopulation",
                1,
                "int");
        Option o7(d7);
        consOptTmp.push_back(o7);
    }

    //Create file option templates
    void Driver::fileOptTemp() {
        Descriptor d1(
                "set",
                {"SET"},
                "",
                2,
                "int"
        );
        Option o1(d1);
        fileOptTmp.push_back(o1);

        Descriptor d2(
                "field size",
                {"FIELD"},
                "",
                2,
                "int"
        );
        Option o2(d2);
        fileOptTmp.push_back(o2);

        Descriptor d3(
                "rules",
                {"RULES"},
                "",
                3,
                "int"
        );
        Option o3(d3);
        fileOptTmp.push_back(o3);
    }

    //Create default options
    void Driver::getDefVal() {
        Descriptor d1(
                "m",
                {"-m"},
                "",
                1,
                "int"
        );
        Option o1(d1);
        o1.isEmpty = false;
        o1.intArgs.push_back(3);
        defVal.push_back(o1);

        Descriptor d2(
                "n",
                {"-n"},
                "",
                1,
                "int"
        );
        Option o2(d2);
        o2.isEmpty = false;
        o2.intArgs.push_back(2);
        defVal.push_back(o2);

        Descriptor d3(
                "k",
                {"-k"},
                "",
                1,
                "int"
        );
        Option o3(d3);
        o3.isEmpty = false;
        o3.intArgs.push_back(3);
        defVal.push_back(o3);

        Descriptor d4(
                "field size",
                {"FIELD"},
                "",
                2,
                "int"
        );
        Option o4(d4);
        o4.isEmpty = false;
        o4.intArgs.push_back(10);
        o4.intArgs.push_back(10);
        defVal.push_back(o4);
    }

    //Create interactive mode options (commands) templates
    void Driver::getInterOpt() {
        Descriptor d1(
                "reset",
                {"reset"},
                "clear field and counter",
                0,
                "");
        Option o1(d1);
        interOpt.push_back(o1);

        Descriptor d2(
                "set",
                {"set"},
                "set life in x y",
                2,
                "int");
        Option o2(d2);
        interOpt.push_back(o2);

        Descriptor d3(
                "clear",
                {"clear"},
                "set dead in x y",
                2,
                "int");
        Option o3(d3);
        interOpt.push_back(o3);

        Descriptor d5(
                "back",
                {"back"},
                "undo the last command",
                0,
                "");
        Option o5(d5);
        interOpt.push_back(o5);

        Descriptor d6(
                "save",
                {"save"},
                "save the state of the game field to a text file",
                1,
                "string");
        Option o6(d6);
        interOpt.push_back(o6);

        Descriptor d7(
                "load",
                {"load"},
                "Load the state of the game field from a text file",
                1,
                "string");
        Option o7(d7);
        interOpt.push_back(o7);

        Descriptor d8(
                "rules",
                {"rules"},
                "set rules m n k",
                3,
                "int"
        );
        Option o8(d8);
        interOpt.push_back(o8);

        Descriptor d4(
                "step",
                {"step"},
                "change field condition by n steps",
                1,
                "int");
        Option o4(d4);
        interOpt.push_back(o4);
    }

}
