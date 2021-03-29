//
// Created by Z on 3/27/2021.
//

#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H
#include "Block.h"


class Blockchain {
private:
    unsigned int sz;
    Block pendingBlock;
    Block* tailBlock;
    void setNewPendingBlock();
    void addMinedBlock();



public:
    Blockchain();
    void newTransaction(int amt, std::string snd, std::string rec);
    void minePendingBlock();



};


#endif //BLOCKCHAIN_H
