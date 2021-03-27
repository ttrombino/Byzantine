//
// Created by Z on 3/26/2021.
//

#ifndef BLOCK_H
#define BLOCK_H
#include "Transaction.h"
#include <vector>


class Block {
private:
    std::string hash;
    std::string dt;
    std::vector<Transaction> transactions;
    unsigned number;
    std::string merkleRoot;
    unsigned nonce;
    unsigned blockReward = 32;


public

    Block(int blockNum);


};



#endif //BLOCK_H
