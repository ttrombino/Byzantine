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
    std::vector<std::string> registeredAddresses;
    unsigned blockNum;
    std::string merkleRoot;
    unsigned nonce;
    unsigned blockReward = 32;
    std::string prevHash;
    std::string nextHash;
    std::string difficulty = "0000";
    void computeHash(int n);




public:

    Block(unsigned blockNum);
    Block* prev;
    Block* next;
    void mineBlock();
    std::vector<std::string> getTransactionHashes();
    std::string getHash();
    unsigned getReward();
    void addTransaction(Transaction& t);
    void setNextBlock(Block* nextBlock);
    void setPrevBlock(Block* nextBlock);
    void printHeader();
    int getAddressBalanceFromBlock(std::string& address);
    void printTransactions();
    void printHeaderWithTransactions();
    void addAddressToBlock(std::string& address);
    void printAddresses();
    bool findAddressInBlock(std::string& address);




};



#endif //BLOCK_H
