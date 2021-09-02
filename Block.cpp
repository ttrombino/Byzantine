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
    next = NULL;
    prev = NULL;
    nonce = 0;
}

void Block::mineBlock() {
    std::vector<std::string> transactionHashes = getTransactionHashes();
    if (transactionHashes.size() != 0) {
        merkleRoot = merkle(transactionHashes);
    }
    else {
        merkleRoot = "";
    }

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

    //printHeader();


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

unsigned Block::getReward() {
    return blockReward;
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
    std::cout << " |Merkle root: " << merkleRoot << std::endl;
    std::cout << " |Nonce: " << nonce << std::endl;
    std::cout << " |Block Reward: " << blockReward << std::endl;
    std::cout << " |Previous Block Hash: " << prevHash << std::endl;
    std::cout << " |Next Block Hash: " << nextHash << std::endl;
    std::cout << " |Registered Addresses: " << registeredAddresses.size() << std::endl;
    printAddresses();
    std::cout << " |Transactions: " << transactions.size() << std::endl;
}

void Block::printTransactions() {

    std::cout << "  |Transactions" << std::endl;
    for (int i = 0; i < transactions.size(); i++) {
        transactions[i].printTransaction();
    }

}

void Block::printAddresses() {
    for (int i = 0; i < registeredAddresses.size(); i++) {
        std::cout << "    |Address:             " << registeredAddresses[i] << std::endl;
    }

}

void Block::printHeaderWithTransactions() {
    printHeader();
    printTransactions();
}

int Block::getAddressBalanceFromBlock(std::string& address) {
    int balance = 0;
    for (int i = 0; i < transactions.size(); i++) {
        if (transactions[i].getSender() == address && transactions[i].getRec() == address) {
            //Do not adjust balance since this is a legal but net-zero transaction.
        }
        else if (transactions[i].getSender() == address) {
            balance -= transactions[i].getAmount();
        }
        else if (transactions[i].getRec() == address) {
            balance += transactions[i].getAmount();
        }
    }
    return balance;
}

void Block::addAddressToBlock(std::string& address) {
    registeredAddresses.push_back(address);
}

bool Block::findAddressInBlock(std::string& address) {
    bool found = false;
    for (int i = 0; i < registeredAddresses.size(); i++) {
        if (registeredAddresses[i] == address) {
            found = true;
            return found;
        }
    }
    return found;
}