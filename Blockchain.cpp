//
// Created by Z on 3/27/2021.
//

#include "Blockchain.h"

Blockchain::Blockchain() : pendingBlock(0) {
    sz = 0;
    tailBlock = NULL;
}

void Blockchain::newTransaction(int amt, std::string snd, std::string rec){
    Transaction tr(amt, snd, rec);
    tr.calculateHash();
    pendingBlock.addTransaction(tr);
}

void Blockchain::minePendingBlock(){
    pendingBlock.mineBlock();
    addMinedBlock();

}

void Blockchain::addMinedBlock() {
    if (sz == 0) {
        tailBlock = &pendingBlock;
    }
    else {
        tailBlock->setNextBlock(&pendingBlock);
        pendingBlock.setPrevBlock(tailBlock);
    }
    sz++;

    setNewPendingBlock();

}

void Blockchain::setNewPendingBlock() {
    Block newPending(sz);
    pendingBlock = newPending;
}