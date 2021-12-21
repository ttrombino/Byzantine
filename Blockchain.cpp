//
// Created by Z on 3/27/2021.
//

#include "Blockchain.h"
//Creates a blockchain using the singly linked list data structure
Blockchain::Blockchain() {
    sz = 0;
    pendingBlock = new Block(sz);
    tailBlock = NULL;
    headBlock = NULL;
}

Blockchain::~Blockchain() {
    Block* current = headBlock;
    Block* tmp = NULL;
    while (current != NULL) {
        tmp = current->next;
        delete current;
        current = tmp;
    }
}

//Creates a new transaction depending on the validity of the sender and recipient address
void Blockchain::newTransaction(int amt, std::string snd, std::string rec){

    try {
        if (snd != "Mine Reward") {
            verifyTransaction(amt, snd, rec);
        }
        Transaction tr(amt, snd, rec);
        tr.calculateHash();
        pendingBlock->addTransaction(tr);
        std::cout << "Transaction complete" << std::endl;
        std::cout << amt << " BYZ sent from " << snd << " to " << rec << std::endl;
    } catch(InvalidSendAddress& b) {
        std::cout << "Error: transaction invalid " << std::endl;
        std::cout << b.what() << std::endl;
    } catch(InvalidRecAddress& b) {
        std::cout << "Error: transaction invalid " << std::endl;
        std::cout << b.what() << std::endl;
    } catch(BalanceException& b) {
        std::cout << "Error: transaction invalid " << std::endl;
        std::cout << b.what() << std::endl;
        std::cout << snd << " balance: " << getAddressBalance(snd) << std::endl;
    }
}

void Blockchain::minePendingBlock(std::string& address){
    pendingBlock->mineBlock();
    addMinedBlock(address);
}

//Adds the mined block to the blockchain and provides the reward to the miner on the next block's transactions
void Blockchain::addMinedBlock(std::string& address) {
    if (sz == 0) {
        tailBlock = pendingBlock;
        headBlock = pendingBlock;
    }
    else {
        tailBlock->setNextBlock(pendingBlock);
        pendingBlock->setPrevBlock(tailBlock);
        tailBlock = pendingBlock;
    }
    sz++;

    setNewPendingBlock();
    newTransaction(tailBlock->getReward(), "Mine Reward", address);
}

void Blockchain::setNewPendingBlock() {
    Block* newPending = new Block(sz);
    pendingBlock = newPending;
}

void Blockchain::printBlockchain() {
    Block* current = headBlock;
    while (current != NULL) {
        current->printHeader();
        current = current->next;
    }
}

void Blockchain::printBlockchainWithTransactions() {
    Block* current = headBlock;
    while (current != NULL) {
        current->printHeaderWithTransactions();
        current = current->next;
    }
}

//Creates the public address using a SHA256 hash of the user name and the current date+time
std::string Blockchain::registerAddress(std::string user) {
    DateTime dt;
    std::string address = sha256(user + dt.getDT());
    pendingBlock->addAddressToBlock(address);
    return address;
}

//Traverses the entire blockchain to get the given address's balance from each block
int Blockchain::getAddressBalance(std::string& address) {
    Block* current = headBlock;
    int balance = 0;
    while (current != NULL) {
        balance += current->getAddressBalanceFromBlock(address);
        current = current->next;
    }
    return balance;
}

void Blockchain::verifyTransaction(int amt, std::string snd, std::string rec) {
    if (!verifyAddress(snd)) {
        throw InvalidSendAddress();
    }
    else if (!verifyAddress(rec)) {
        throw InvalidRecAddress();
    }
    else if (getAddressBalance(snd) - amt < 0) {
        throw BalanceException();
    }

}

//Searches the entire blockchain to ensure the given address has been registered
bool Blockchain::verifyAddress(std::string& address) {
    Block* current = headBlock;
    bool found = false;
    while (current != NULL) {
        found = current->findAddressInBlock(address);
        if (found == true) {
            return found;
        }
        else {
            current = current->next;
        }
    }
    return found;
}

