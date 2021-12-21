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

//Mine the current pending block using SHA256 proof of work via a merkle tree and the preset difficulty
void Block::mineBlock() {
    std::vector<std::string> transactionHashes = getTransactionHashes();
    if (transactionHashes.size() != 0) {
        merkleRoot = merkle(transactionHashes);
    }
    else {
        merkleRoot = "";
    }

    //Computes the SHA256 depending on if the result matches the difficulty requirements
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
}

//Puts all the transaction hashes into a vector
std::vector<std::string> Block::getTransactionHashes() {
    std::vector<std::string> transactionHashes;
    for (int i = 0; i < transactions.size(); i++) {
        transactionHashes.push_back(transactions[i].getHash());
    }
    return transactionHashes;
}

//Creates the block's SHA256 hash using the time, block number, merkle root and the nonce
void Block::computeHash(int n) {
    std::string headerSum = hash + timeCreated + std::to_string(blockNum) + merkleRoot + std::to_string(n);
    hash = sha256(headerSum);
}

//Add transaction to the list of transactions
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

//Computes the balance by calculating each transaction so that all balances can be verified exclusively on the blockchain
int Block::getAddressBalanceFromBlock(std::string& address) {
    int balance = 0;
    for (int i = 0; i < transactions.size(); i++) {
        if (transactions[i].getSender() == address && transactions[i].getRec() == address) {
            //Do not adjust balance since this is a legal but net-zero transaction.
        }
        //If the address was the sender, subtract the amount
        else if (transactions[i].getSender() == address) {
            balance -= transactions[i].getAmount();
        }
        //If the address was the recipient, add the amount
        else if (transactions[i].getRec() == address) {
            balance += transactions[i].getAmount();
        }
    }
    return balance;
}

void Block::addAddressToBlock(std::string& address) {
    registeredAddresses.push_back(address);
}

//Checks if entered address is in the block so that the transaction can be verified
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