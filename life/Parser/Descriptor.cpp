#include "Descriptor.h"
#include "Option.h"
namespace LifeGame {

//  CONSTRUCTORS

    Descriptor::Descriptor() {}

    Descriptor::Descriptor(const Descriptor &other) {
        constName = other.constName;
        tempNames = other.tempNames;
        optDescr = other.optDescr;
        countArgs = other.countArgs;
        argType = other.argType;
    }

    Descriptor::~Descriptor() {
    }

    Descriptor &Descriptor::operator=(const Descriptor &other) {
        constName = other.constName;
        tempNames = other.tempNames;
        optDescr = other.optDescr;
        countArgs = other.countArgs;
        argType = other.argType;
        return *this;
    }

    Descriptor::Descriptor(string nm, vector<string> tmpNm, string desc, int argc, string type) {
        constName = nm;
        tempNames = tmpNm;
        optDescr = desc;
        countArgs = argc;
        argType = type;
    }

    //  METHODS

    //Print help
    void Descriptor::print() {
        cout << "Option name : " << constName << endl;
        cout << "Description : " << optDescr << endl;
        cout << "Possible names : ";
        printNames();
        cout << "Arguments : ";
        printArgs();
        cout << "===============================================" << endl;
        cout << endl;
    }

    //Print possible names
    void Descriptor::printNames() {
        for (auto &it : tempNames) {
            cout << it << " ";
        }
        cout << endl;
    }

    //Print arguments for help
    void Descriptor::printArgs() {
        for (int i = 0; i < countArgs; ++i) {
            cout << "<" << argType << "> ";
        }
        cout << endl;
    }
}