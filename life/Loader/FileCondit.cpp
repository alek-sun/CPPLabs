#include "FileCondit.h"

namespace LifeGame{
    //DEFAULT
    FileCondit::FileCondit() {}

    //Create FileCondit by template options for loader
    FileCondit::FileCondit(vector<Option> &tmp):ld(tmp){}

    FileCondit::FileCondit(const FileCondit &other) {
        fileName = other.fileName;
        ld = other.ld;
        op = other.op;
    }

    FileCondit& FileCondit::operator=(const FileCondit &other) {
        fileName = other.fileName;
        ld = other.ld;
        op = other.op;
        return *this;
    }

    FileCondit::~FileCondit() {}

    //METHODS

    Condition FileCondit::load() {
        ld.setFileName(fileName);   //  send file name in loader
        vector<Option> opt = ld.getOptions();   //  load options from file
        ld.clear();     // clear loader for next iteration
        op.setOpt(opt); //  send options in opener
        return op.getCond();    // get condition
    }

    //Set name of openable file
    void FileCondit::setFileName(string str) {
        fileName = str;
    }

    //Set condition in opener
    void FileCondit::setCond(Condition c) {
        op.setCond(c);
    }


}