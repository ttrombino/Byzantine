//
// Created by Z on 4/1/2021.
//

#ifndef RUNBLOCKCHAIN_H
#define RUNBLOCKCHAIN_H
#include "Blockchain.h"


class runBlockchain {

private:
    Blockchain bc;

public:

    void showCommandsScreen();
    runBlockchain();
    char getCommand();
    void runCommand(char& command);
    void rbRegisterAddress();
    void rbMinePendingBlock();
    void rbNewTransaction();
    void rbGetAddressBalance();
    void rbPrintBlockchain();
    void run();




};


#endif //RUNBLOCKCHAIN_H
