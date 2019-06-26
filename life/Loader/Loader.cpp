#include "Loader.h"
#include "../Parser/ParseError.h"

namespace LifeGame{
     //DEFAULT
     Loader::Loader() {}

    //Create loader by option template for file parser
     Loader::Loader(vector<Option> &temp): filePrs(temp){}

     Loader::Loader(const Loader &other) {
         fileName = other.fileName;
         prsFileRes = other.prsFileRes;
         filePrs = other.filePrs;
     }

     Loader& Loader::operator=(const Loader &other) {
         fileName = other.fileName;
         prsFileRes = other.prsFileRes;
         filePrs = other.filePrs;
         return *this;
     }

     Loader::~Loader() {}

     // METHODS

    //Get options by file parsing
     vector<Option> Loader::getOptions() {
         vector<string> fileArgs = fileToVect(); // convert file to vector<string>
         try {
             prsFileRes = filePrs.parse(fileArgs);  //  parse file
         } catch (ExactPrsErr &err){
             cout << "Error reading file " << fileName << endl;
             throw ExactPrsErr();
         }
         openRules();   //  open rules m n k separately
         return prsFileRes;
     }

    //Open rules m n k separately: create new options m n k by values from rules
     void Loader::openRules() {
         for (auto &it : prsFileRes){
             if (it.getName() == "rules" && !it.isEmpty){
                 Option o1("m", "int");
                 o1.isEmpty = false;
                 o1.intArgs.push_back(it.intArgs[0]);
                 Option o2("n", "int");
                 o2.isEmpty = false;
                 o2.intArgs.push_back(it.intArgs[1]);
                 Option o3("k", "int");
                 o3.isEmpty = false;
                 o3.intArgs.push_back(it.intArgs[2]);
                 prsFileRes.push_back(o1);  // push new option on parse result
                 prsFileRes.push_back(o2);
                 prsFileRes.push_back(o3);
                 break;
             }
         }
     }

    //Convert file to vector<string>
     vector<string> Loader::fileToVect() {
         vector<string> res;
         std::ifstream in;  //
         in.open(fileName);
         if (!in.is_open()){
             cout << fileName << " can't be opened" << endl;
             return res;
         }
         char c = ' ';
         string curOpt; // string for reding characters
         while (in.get(c)) {    // reading character-by-character
             if (c == '\n' || c == ' ' || c == '#'){
                 if (!addOpt(in, c, curOpt, res)){
                     throw RepeitFlags(curOpt);
                 }
                 continue;
             }
             curOpt.push_back(c);   //  add char if it's not delim char
         }
         if (!curOpt.empty()) { // add last string
             res.push_back(curOpt);
         }
         return res;
     }

    //Add option to result vector
    bool Loader::addOpt(std::ifstream &in, char c, string &curOpt, vector<string> &res) {
        if (!curOpt.empty()){
            if (isRepeit(curOpt, res)){
                return false;
            }
            res.push_back(curOpt);
            curOpt.clear(); //clear for new iteration
        }
        if (c == '#'){  // ignore all after # to \n
            in.ignore(3000, '\n');
        }
        return true;
    }

    //Check repeit options
    bool Loader::isRepeit(string s, vector<string> v){
        if (s == "RULES" || s == "FIELD") {
            for (auto &it : v) {
                if (it == s) return true;
            }
        }
        return false;
    }

    //Set file name
    void Loader::setFileName(string name) {
        fileName = name;
    }

    //Clear loader for next iteration
    void Loader::clear() {
        filePrs.clearTmp();
        prsFileRes.clear();
    }

}