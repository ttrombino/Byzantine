//
// Created by Z on 3/26/2021.
//

#ifndef BLOCK_H
#define BLOCK_H
#include "Transaction.h"
#include "Merkle.h"
#include <vector>


class Block {
private:
    std::string hash;
    std::string timeCreated;
    std::string timeMined;
    std::vector<Transaction> transactions;
    unsigned blockNum;
    std::string merkleRoot;
    unsigned nonce;
    unsigned blockReward = 32;
    std::string prevHash;
    std::string nextHash;
    Block* prev;
    Block* next;
    std::string difficulty = "00000";
    void computeHash(int n);




public:

    Block(unsigned blockNum);
    void mineBlock();
    std::vector<std::string> getTransactionHashes();
    std::string getHash();
    void addTransaction(Transaction& t);
    void setNextBlock(Block* nextBlock);
    void setPrevBlock(Block* nextBlock);
    void printHeader();



};



#endif //BLOCK_H
