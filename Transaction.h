//
// Created by Z on 3/26/2021.
//

#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <string>
#include "DateTime.h"
#include "sha256.h"
//#include <format>
#include <iostream>
#include <cstdio>


class Transaction {
private:
    std::string hash = "";
    unsigned blockNum;
    unsigned amount;
    std::string senderAddr = "";
    std::string recAddr = "";
    std::string dt;

public:


    Transaction(int block, int amt, std::string snd, std::string rec){
        DateTime time;
        blockNum = block;
        amount = amt;
        senderAddr = snd;
        recAddr = rec;
        dt = time.getDT();
    }

    void calculateHash() {
        std::string h = std::to_string(blockNum) + std::to_string(amount) + senderAddr + recAddr + dt;
        hash = sha256(h);
    }

    std::string getHash(){
        return hash;
    }

    void setBlockNum(unsigned block) {
        blockNum = block;
    }

    void printTransaction() {
        std::cout << "Transaction:             " << hash << std:: endl;
        std::cout << "  |Time:                 " << dt << std:: endl;
        std::cout << "  |Hash:                 " << hash << std::endl;
        std::cout << "  |Block:                " <<  blockNum << std::endl;
        std::cout << "  |Amount:               " <<  amount << std::endl;
        std::cout << "  |Sender Address:       " <<  senderAddr << std::endl;
        std::cout << "  |Recipient Address:    " <<  recAddr << std::endl;

    }



};




#endif //TRANSACTION_H
