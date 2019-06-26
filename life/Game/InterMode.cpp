#include "InterMode.h"
#include "Setter.h"
#include "Stepper.h"
#include "../Loader/FileCondit.h"
#include "../Export/Exporter.h"

namespace LifeGame{
    //DEFAULT
    InterMode::InterMode() {}

    InterMode::InterMode(FileCondit &ld) {
        fileLoader = ld;
    }

    InterMode::InterMode(const InterMode &other) {
        curCmd = other.curCmd;
    }

    InterMode &InterMode::operator=(const InterMode &other) {
        curCmd = other.curCmd;
        return *this;
    }

    InterMode::~InterMode() {}

    //METHODS
    //Call methods depending on the command
    Condition InterMode::oneIter() {
        Condition newCond = getCurCond();
        if (curCmd.getName() == "set"){
            return set(newCond, ALIVE);
        }
        if (curCmd.getName() == "clear"){
            return set(newCond, DEAD);
        }
        if (curCmd.getName() == "reset"){
            return reset(newCond);
        }
        if (curCmd.getName() == "back"){
            return back(newCond);
        }
        if (curCmd.getName() == "step"){
            return step(newCond);
        }
        if (curCmd.getName() == "rules"){
            return setRules(newCond);
        }
        if (curCmd.getName() == "load"){
            return load(newCond);
        }
        if (curCmd.getName() == "save"){
            return save(newCond);
        }
        return newCond;
    }

    //Save current condition to file
    Condition InterMode::save(const Condition &newCond) {
        string name = curCmd.getStrArg(0);  // get first string argument - file name
        FileExport exp(getCurCond(), name);     //  set exporter by current condition and filename
        exp.saveToFile();
        return newCond;
    }

    //Load field condition from file
    Condition InterMode::load(Condition &newCond){
        newCond.clearField();   //  clear field
        string name = curCmd.getStrArg(0);  // get first string argument - file name
        fileLoader.setFileName(name);   //  send filename in loader
        fileLoader.setCond(newCond);    // send current condition in loader
        newCond = fileLoader.load();    //  load condition from file
        counter.push_back(newCond);     // push new condition in counter
        return newCond;
    }

    //Set rules m n k
    Condition InterMode::setRules(Condition &newCond){
        newCond.m = curCmd.getIntArg(0);    // get m
        newCond.n = curCmd.getIntArg(1);    // get n
        newCond.k = curCmd.getIntArg(2);    // get k
        counter.push_back(newCond);     // push new rules in counter
        return newCond;
    }

    //Step and push new condition to counter
    Condition InterMode::step(Condition &newCond) {
        Stepper step(getCurCond(), curCmd.getIntArg(0));    //  send in stepper count of steps and current condition
        newCond = step.start(); //  step n
        counter.push_back(newCond);    //   push new condition in counter
        return newCond;
    }

    //Close last command
    Condition InterMode::back(Condition &newCond) {
        if (counter.size() == 1){   // if it's not command earlier
                throw std::out_of_range("Empty command stack\n");
            }
        counter.pop_back(); //  extract 1 command from counter
        newCond = getCurCond(); // return previos condition
        return newCond;
    }

    //Clear field and condition counter
    Condition& InterMode::reset(Condition &newCond){
        newCond.clearField();   //  clear field
        while (counter.size() != 1){    //  extract all previos conditions
                counter.pop_back();
            }
        newCond = getCurCond();//  return start condition
        //counter.push_back(newCond);
        return newCond;
    }

    //Set dead or live to coordinates x y
    Condition& InterMode::set(Condition &newCond, int val) {
        Setter setter(val, curCmd.getIntArgs());    // send in setter value and coordinates
        setter.setCond(getCurCond());   //  send in setter current condition
        newCond.fld = setter.setField();  // set value on (x,y)
        counter.push_back(newCond); // push new condition in counter
        return newCond;
    }

    //Push condition in counter
    void InterMode::pushCondit(Condition &cond) {
        counter.push_back(cond);
    }

    //Load current condition
    Condition InterMode::getCurCond() {
        return counter[counter.size()-1];
    }

    //Set current command
    void InterMode::setCmd(Option& command) {
        curCmd = command;
    }
}