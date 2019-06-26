#include "Parser.h"
#include "ParseError.h"
namespace LifeGame {
    //  CONSTRUCTORS
    Parser::Parser() {}

    Parser::Parser(const Parser &other) {
        optSet = other.optSet;
    }

    Parser& Parser::operator=(const Parser &other) {
        optSet = other.optSet;
        return *this;
    }

    Parser::~Parser() {}

    //Set option template
    Parser::Parser(vector<Option> tmp) {
        optSet = tmp;
    }


    //  METHODS

    //Parse arguments string
    vector<Option> Parser::parse(vector<string>& args) {
        if (args.empty()) {
            return optSet; // empty set
        }
        string curName;
        for (auto it = args.begin(); it != args.end(); ++it) {
            curName = *it; // expected option name
            if (curName == "-h" || curName == "--help") {
                getHelp();
                continue;
            }
            if (!isSomeName(curName)) { // if it's not the name of option
                throw ExactPrsErr("Failed to parse command line arguments: use --help or -h to get help");
            }
            parseOpt(curName, args, it);   // parse 1 option with args
        }
        return optSet;
    }

    //Parse one option
    //At the start iterator it points on current name of option
    void Parser::parseOpt(const string& name, vector<string>& args,
                           vector<string>::iterator &it) {
        for (auto &iter : optSet) {   // find option template
            if (!iter.isName(name)) continue;
            if (!iter.isEmpty && iter.getName()!= "set"){  // if option already is full => repeit flags
                throw RepeitFlags(iter. getName());
            }
            if (!checkArgCount(args, it, iter)){    // check count of arguments
                throw CountArgErr(iter. getName(), iter.descr.countArgs, iter.getType());
            }
            iter.parseArgs(it, args);   // parse arguments if "name" right name option and argCount is right
            break;
        }
    }

    //Checking count of arguments
    bool Parser::checkArgCount(vector<string> &args,
                               vector<string>::iterator &it,
                                Option &iter) {
        for (int i = 0; i < iter.descr.countArgs; ++i) {
            ++it;
            if (it == args.end() || isSomeName(*it)) {  // if met name of option instead argument or end of command line without args
                return iter.getName() == "step";    // step crutch
            }
        }
        for (int i = 0; i < iter.descr.countArgs; ++i) {
            --it;
        }
        return true;
    }

    //Help function
    void Parser::getHelp() {
        for (auto &it : optSet) {
            it.descr.print(); //    print description
        }
    }

    //It's name of some option from template?
    bool Parser::isSomeName(string name) {
        for (auto &it : optSet){
            if (it.isName(name)){
                return true;
            }
        }
        return false;
    }

    //Clear option template
    void Parser::clearTmp() {
        for (auto &it: optSet){
            it.isEmpty = true;
            it.intArgs.clear();
            it.strArgs.clear();
        }
    }
}
