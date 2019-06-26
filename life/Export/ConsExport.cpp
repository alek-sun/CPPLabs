#include "ConsExport.h"

namespace LifeGame{
    //DEFAULT
    ConsExport::ConsExport() {}

    ConsExport::ConsExport(const ConsExport &other) {
        cond = other.cond;
    }

    ConsExport &ConsExport::operator=(const ConsExport &other) {
        cond = other.cond;
        return *this;
    }

    ConsExport::ConsExport(Condition finish) {
        cond = finish;
    }

    ConsExport::~ConsExport() {}

    //METHODS

    //Console output
    void ConsExport::consOut() {
        int count = 0;
        for (auto &it: cond.fld){
            count++;
            if (it == LIVE) {
                cout << "*";
            }
            else {
                cout << ".";
            }
            if (count % cond.fldW == 0){
                cout << endl;
            }
        }
    }
}