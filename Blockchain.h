//
// Created by Z on 3/27/2021.
//

#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H
#include "Block.h"
#include "BlockchainExceptions.h"


class Blockchain {
private:
    unsigned int sz;
    Block* pendingBlock;
    Block* tailBlock;
    Block* headBlock;
    void setNewPendingBlock();
    void addMinedBlock(std::string& address);

public:
    Blockchain();
    ~Blockchain();
    void newTransaction(int amt, std::string snd, std::string rec);
    void minePendingBlock(std::string& address);
    void printBlockchain();
    std::string registerAddress(std::string user);
    int getAddressBalance(std::string& address);
    void printBlockchainWithTransactions();
    void verifyTransaction(int amt, std::string snd, std::string rec);
    bool verifyAddress(std::string& address);

};


#endif //BLOCKCHAIN_H
