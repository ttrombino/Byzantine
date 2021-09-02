//
// Created by Z on 4/1/2021.
//

#include "runBlockchain.h"

runBlockchain::runBlockchain() {

}

void runBlockchain::showCommandsScreen() {
    std::cout << "---------------------------------Commands----------------------------------" << std::endl;
    std::cout << "r: register address" << std::endl;
    std::cout << "m: mine pending block" << std::endl;
    std::cout << "t: create new transaction" << std::endl;
    std::cout << "b: get address balance" << std::endl;
    std::cout << "p: print blockchain" << std::endl;
    std::cout << "q: quit" << std::endl;
    std::cout << "---------------------------------------------------------------------------" << std::endl;
}


char runBlockchain::getCommand() {

    char command;
    std::cout << "Enter command: "  << std::endl;
    std::cin >> command;
    std::cin.ignore();


    return command;

}

void runBlockchain::runCommand(char& command) {
    switch(command) {
        case 'r':
            rbRegisterAddress();
            break;
        case 'm':
            rbMinePendingBlock();
            break;
        case 't':
            rbNewTransaction();
            break;
        case 'b':
            rbGetAddressBalance();
            break;
        case 'p':
            rbPrintBlockchain();
            break;
        case 'q':
            break;

    }
}

void runBlockchain::rbRegisterAddress() {
    std::string user;
    std::string address;
    std::cout << "Enter user: " << std::endl;
    std::getline(std::cin, user);
    address = bc.registerAddress(user);
    std::cout << "Address created: " << address << std::endl;
}

void runBlockchain::rbMinePendingBlock() {
    std::string address;
    std::cout << "Enter reward address: " << std::endl;
    std::cin >> address;
    std::cin.ignore();

    std::cout << "-------------------------------------------" << std::endl;
    bc.minePendingBlock(address);
    std::cout << "-------------------------------------------" << std::endl;
}

void runBlockchain::rbNewTransaction() {
    std::string sender;
    std::string rec;
    unsigned amount;

    std::cout << "Enter sender address: " << std::endl;
    std::cin >> sender;
    std::cin.ignore();

    std::cout << "Enter recipient address: " << std::endl;
    std::cin >> rec;
    std::cin.ignore();

    std::cout << "Enter amount: " << std::endl;
    std::cin >> amount;
    std::cin.ignore();

    bc.verifyTransaction(amount, sender, rec);

    bc.newTransaction(amount, sender, rec);


}

void runBlockchain::rbGetAddressBalance() {
    std::string address;

    std::cout << "Enter address: " << std::endl;
    std::cin >> address;
    std::cin.ignore();

    std::cout << address << " balance: " << bc.getAddressBalance(address) << std::endl;


}

void runBlockchain::rbPrintBlockchain() {
    bc.printBlockchainWithTransactions();
}

void runBlockchain::run() {

    //showCommandsScreen();
    char input = 'a';
    while (input != 'q') {
        showCommandsScreen();
        input = getCommand();
        try {
            runCommand(input);
        } catch(InvalidSendAddress& b) {
            std::cout << "Error: transaction invalid " << std::endl;
            std::cout << b.what() << std::endl;
        } catch(InvalidRecAddress& b) {
            std::cout << "Error: transaction invalid " << std::endl;
            std::cout << b.what() << std::endl;
        } catch(BalanceException& b) {
            std::cout << "Error: transaction invalid " << std::endl;
            std::cout << b.what() << std::endl;
        }
    }


}