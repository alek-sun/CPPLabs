//Game "Life"
//Created by Fediaeva Irina
//More information about classes in readme.txt

#include <iostream>
#include "Parser/Parser.h"
#include "Driver.h"
#include "Parser/ParseError.h"

using namespace LifeGame;
     int main(int argc, char **argv) {
         Driver d;
         try {
             d.launch(argv, argc);
         }
         catch (ExactPrsErr &err){
             cout << err.what();
         }
         catch(CountArgErr &err){
             err.what();
         }
         catch(ArgFormErr& err){
            err.what();
         }
         catch (RepeitFlags& err){
             err.what();
         }
         catch (std::out_of_range &err){
             cout << err.what();
         }
         catch(std::runtime_error& err){
             cout << err.what();
         }
         catch(std::bad_alloc& err) {
             cout << err.what();
         }
     }
