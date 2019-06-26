#include "Exporter.h"

namespace LifeGame{
    // CONSTRUCTORS
    FileExport::FileExport() {}

    FileExport::FileExport(const FileExport &other) {
        cond = other.cond;
        fileName = other.fileName;
    }

    FileExport &FileExport::operator=(const FileExport &other) {
        cond = other.cond;
        fileName = other.fileName;
        return *this;
    }

    //Constructor by finish condition and file name
    FileExport::FileExport(Condition finish, string name) {
        cond = finish;
        fileName = name;
    }

    FileExport::~FileExport() {}

    //METHODS

    //Save condition to file
    void FileExport::saveToFile() {
        std::ofstream out;
        out.open(fileName);
        if (!out.is_open()){
            cout << "Can't open file " << fileName << endl;
            return;
        }
        fieldOut(out);
    }

    //Print field and rules condition
    void FileExport::fieldOut(std::ofstream &out){
        int count = 0;
        if (cond.m != 3 || cond.n != 2 || cond.k != 3){
            out << "RULES " << cond.m << " " << cond.n << " " << cond.k << endl;    //  print not default rules
        }
        if (cond.fldH != 10 || cond.fldW != 10){
            out << "FIELD " << cond.fldW << " " << cond.fldH << endl;    // print not default field size
        }
        for (auto &it: cond.fld){
            if (it == LIVE) {
                out << "SET " <<
                    count % cond.fldW << " " << count / cond.fldW << endl;
            }
            count++;
        }
    }
};