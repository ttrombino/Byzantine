//
// Created by Z on 3/27/2021.
//

#include "Blockchain.h"

Blockchain::Blockchain() {
    sz = 0;
    pendingBlock = new Block(sz);
    tailBlock = pendingBlock;
    headBlock = pendingBlock;
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

void Blockchain::newTransaction(int amt, std::string snd, std::string rec){
    Transaction tr(amt, snd, rec);
    tr.calculateHash();
    pendingBlock->addTransaction(tr);
}

void Blockchain::minePendingBlock(std::string& address){
    pendingBlock->mineBlock();
    addMinedBlock(address);
}

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
    newTransaction(tailBlock->getReward(), "Mine", address);

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

std::string Blockchain::registerAddress(std::string user) {
    DateTime dt;
    std::string address = sha256(user + dt.getDT());
    return address;
}

int Blockchain::getAddressBalance(std::string& address) {
    Block* current = headBlock;
    int balance = 0;
    while (current != NULL) {
        balance += current->getAddressBalanceFromBlock(address);
        current = current->next;
    }
}

