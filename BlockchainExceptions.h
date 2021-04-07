//
// Created by Z on 4/3/2021.
//

#ifndef BLOCKCHAINEXCEPTIONS_H
#define BLOCKCHAINEXCEPTIONS_H
#include <exception>

class BlockchainException : public std::exception {

};

class BalanceException : public BlockchainException {
public:
    const char * what() const throw() {
        return "Insufficient address balance for transaction amount.";
    }
};

class InvalidSendAddress : public BlockchainException {
public:
    const char * what() const throw() {
        return "Sender address not registered";
    }
};

class InvalidRecAddress : public BlockchainException {
public:
    const char * what() const throw() {
        return "Recipient address not registered";
    }
};



#endif //BLOCKCHAINEXCEPTIONS_H
