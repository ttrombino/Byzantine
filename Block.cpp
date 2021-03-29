//
// Created by Z on 3/26/2021.
//

#include "Block.h"


Block::Block(unsigned block) {
    DateTime dt;
    timeCreated = dt.getDT();
    hash = "";
    nextHash = "";
    prevHash = "";
    blockNum = block;
    nonce = 0;
}

void Block::mineBlock() {
    std::vector<std::string> transactionHashes = getTransactionHashes();
    merkleRoot = merkle(transactionHashes);

    while (hash.substr(0,difficulty.size()) != difficulty) {
        computeHash(nonce);
        nonce++;
    }

    DateTime dtMined;
    timeMined = dtMined.getDT();

    std::cout << "Block " << blockNum << " mined" << std::endl;
    std::cout << "Time: " << timeMined << std::endl;
    std::cout << "Hash: " << hash << std::endl;
    std::cout << "Nonce: " << nonce << std::endl;

    printHeader();


}

std::vector<std::string> Block::getTransactionHashes() {
    std::vector<std::string> transactionHashes;
    for (int i = 0; i < transactions.size(); i++) {
        transactionHashes.push_back(transactions[i].getHash());
    }
    return transactionHashes;
}

void Block::computeHash(int n) {
    std::string headerSum = hash + timeCreated + std::to_string(blockNum) + merkleRoot + std::to_string(n);
    hash = sha256(headerSum);
}

void Block::addTransaction(Transaction& t) {
    t.setBlockNum(blockNum);
    transactions.push_back(t);
}

std::string Block::getHash(){
    return hash;
}

void Block::setNextBlock(Block* nextBlock) {
    next = nextBlock;
    nextHash = nextBlock->getHash();
}

void Block::setPrevBlock(Block* prevBlock) {
    prev = prevBlock;
    prevHash = prevBlock->getHash();
}

void Block::printHeader() {

    std::cout << "|Block " << blockNum << std::endl;
    std::cout << " |Hash: " << hash << std::endl;
    std::cout << " |Time Created: " << timeCreated << std::endl;
    std::cout << " |Time Added: " << timeMined << std::endl;
    std::cout << " |Transactions: " << transactions.size() << std::endl;
    std::cout << " |Merkle root: " << merkleRoot << std::endl;
    std::cout << " |Nonce: " << nonce << std::endl;
    std::cout << " |Block Reward: " << blockReward << std::endl;
}