//
// Created by Z on 3/26/2021.
//

#include "Block.h"


Block::Block(int block) {
    blockNum = block;
}

void Block::mineBlock() {
    std::string transactionHashes = getTransactionHashes();
    merkleRoot = merkle(transactionHashes);

    std::string headerSum =

}

std::vector<std::string> Block::getTransactionHashes() {
    std::vector<std::string> transactionHashes;
    for (int i = 0; i < transactions.size(); i++) {
        transactionHashes.push_back(transactions[i]);
    }
    return transactionHashes;
}
