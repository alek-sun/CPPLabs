#ifndef LIFE_FILECONDIT_H
#define LIFE_FILECONDIT_H

#include "../Game/Condition.h"
#include "Loader.h"
#include "Opener.h"

namespace LifeGame{
    class FileCondit{
        string fileName; // name of file
        Loader ld;  // loader for loading options from file
        Opener op;  //  opener for get condition from loaded options
    public:
        FileCondit();
        FileCondit(vector<Option>& tmp);
        FileCondit(const FileCondit& other);
        FileCondit& operator=(const FileCondit& other);
        ~FileCondit();

        void setCond(Condition c);
        void setFileName(string str);
        Condition load();
    };
}
#endif //LIFE_FILECONDIT_H
