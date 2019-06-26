#ifndef INC_LIFE_PARSER_H
#define INC_LIFE_PARSER_H
#include "Option.h"

namespace LifeGame {
    class Parser{
        vector<Option> optSet; // option template for filling
        bool isSomeName(string name);
        void parseOpt(const string& name, vector<string>& args,
                       vector<string>::iterator &it);
    public:
        Parser();
        Parser(const Parser& other);
        Parser& operator=(const Parser& other);
        Parser(vector<Option> tmp);
        ~Parser();

        void clearTmp();
        void getHelp();
        vector<Option> parse(vector<string>& args);
        bool checkArgCount(vector<string> &args,
           vector<string>::iterator &it, Option &iter);
    };
}
#endif //LIFE_PARSER_H
