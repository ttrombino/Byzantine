//
// Created by Z on 4/3/2021.
//

#ifndef BLOCKCHAINEXCEPTIONS_H
#define BLOCKCHAINEXCEPTIONS_H
#include <exception>

class BalanceException : public std::exception {
public:
    const char * what() const throw() {
        return "Insufficient address balance for transaction amount.";
    }
};

class InvalidSendAddress : public std::exception {
public:
    const char * what() const throw() {
        return "Sender address not registered";
    }
};

class InvalidRecAddress : public std::exception {
public:
    const char * what() const throw() {
        return "Recipient address not registered";
    }
};



#endif //BLOCKCHAINEXCEPTIONS_H
