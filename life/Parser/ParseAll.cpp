#include "ParseAll.h"
#include "ParseError.h"

namespace LifeGame{
    //  CONSTRUCTORS

    ParseAll::ParseAll() {}

    //Create ParsAll with option templates
    ParseAll::ParseAll(vector<Option> consOptTmp, vector<Option> fileOptTmp, vector<Option> defVal):
            consParse(consOptTmp), loader(fileOptTmp), defVal(defVal){}

    ParseAll::ParseAll(const ParseAll &other) {
        consParse = other.consParse;
        loader = other.loader;
        defVal = other.defVal;
    }

    ParseAll &ParseAll::operator=(const ParseAll &other) {
        consParse = other.consParse;
        loader = other.loader;
        defVal = other.defVal;
        return *this;
    }

    ParseAll::~ParseAll() {}

    //METHODS

    //Get input file name from option set
    string ParseAll::getInputFile(vector<Option> consArgs) {
        for (auto &it : consArgs){
            if (it.getName() == "input file" && !it.isEmptyOpt()){
                return it.getStrArg(0);
            }
        }
        return "";
    }

    //Convert char**argv to vector<string>
    vector<string> ParseAll::convertToVect(char **argv, int argc) {
        vector<string> argArr;
        for (int i = 1; i < argc; ++i) {
            argArr.push_back(static_cast<string>(argv[i]));
        }
        return argArr;
    }

    //Unite options from file and from console
    //If in the console remainded some options, fill it form file
    //Add option SET from file, because it isn't in console
    vector<Option> ParseAll::uniteArgs(vector<Option>& consOpt, vector<Option>& otherOpt) {
        for (auto &it : consOpt){
            if (it.isEmptyOpt()){
                it = pasteOpt(it, otherOpt);
            }
        }
        for (auto &it : otherOpt){
            if (it.getName() == "set") {
                consOpt.push_back(it);
            }
        }
        return consOpt;
    }

    //Find option by name
    Option ParseAll::pasteOpt(Option& empty, vector<Option>& set){
        for (auto &it : set){
            if (it.getName() == empty.getName()){
                return it;
            }
        }
        return empty;
    }


    //Load default values in empty options
    void ParseAll::addDef(vector<Option> &consOpt, vector<Option> &defOpt) {
        for (auto &it : consOpt){
            if (it.isEmptyOpt()){
                it = pasteOpt(it, defOpt);
            }
        }
    }

    //Parse console and file
    vector<Option> ParseAll::prsAll(char **argv, int argc) {
        vector<string> consArgs = convertToVect(argv, argc);
        vector<Option> prsConsRes;
        if (consArgs.empty()){
            return prsConsRes;  // empty vector
        }
        prsConsRes = consParse.parse(consArgs);     // parse console
        string fileName = getInputFile(prsConsRes);     // get file name
        if (fileName == "") {   // if file isn't found
            addDef(prsConsRes, defVal);     // add default values
            return prsConsRes;
        }
        loader.setFileName(fileName);   // send file name in loader
        vector<Option> prsFileRes;  // for parse file results
       try {
            prsFileRes = loader.getOptions();   //  parse file
       }catch(ExactPrsErr &err){}
        catch (RepeitFlags &err){
           cout << "Oops! Error in parse file " << fileName << "! ";
           err.what();
           cout << endl;
       }catch(CountArgErr &err){
           cout << "Oops! Error in parse file: ";
           err.what();
           cout << endl;
       }
        uniteArgs(prsConsRes, prsFileRes);  // unite file and console options
        addDef(prsConsRes, defVal);     // add default values on empty places
        return prsConsRes;
    }
}