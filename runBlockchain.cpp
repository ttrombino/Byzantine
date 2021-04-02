//
// Created by Z on 4/1/2021.
//

#include "runBlockchain.h"

void runBlockchain::showCommandsScreen() {
    std::cout << "---------------------------------Commands----------------------------------" << std::endl;
    std::cout << "r: register address" << std::endl;
    std::cout << "m: mine pending block" << std::endl;
    std::cout << "t: create new transaction" << std::endl;
    std::cout << "b: get address balance" << std::endl;
    std::cout << "p: print blockchain" << std::endl;
    std::cout << "---------------------------------------------------------------------------" << std::endl;
}