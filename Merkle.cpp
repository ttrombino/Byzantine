//
// Created by Z on 3/22/2021.
//
#include <iostream>
#include "Merkle.h"
#include "sha256.h"

std::string hash2(std::string &a, std::string &b) {
//    std::string a1 = std::string(a.rbegin(), a.rend());
//    std::string b1 = std::string(b.rbegin(), b.rend());
//
//    std::cout << "a1: " << a1 << std::endl;
//    std::cout << "b1: " << b1 << std::endl;
//
//    return "";
    std::string a1 = flipEndian(a);
    std::string b1 = flipEndian(b);

    std::cout << "a1+b1: " << a1+b1 << std::endl;

    std::string h = sha256(a1+b1);
    std::cout << "hash: " << h << std::endl;
    std::string returnH = flipEndian(h);
    std::cout << "final: " << returnH << std::endl;
    return returnH;
}

std::string merkle(std::vector<std::string> &hashList) {
    if (hashList.size() == 1) {
        return hashList[0];
    }
    std::vector<std::string> newHashList;
    for (int i = 0; i < hashList.size() - 1; i = i + 2) {
//        std::cout << "Branch " << i+1 << " is " << hashList[i] << std::endl;
//        std::cout << "Branch " << i+2 << " is " << hashList[i+1] << std::endl;
//        std::cout << "Their hash is: " << hash2(hashList[i], hashList[i+1]) << std::endl;
        newHashList.push_back(hash2(hashList[i], hashList[i+1]));
    }
    if (hashList.size() % 2 == 1) {
        newHashList.push_back(hash2(hashList[hashList.size() - 1], hashList[hashList.size() - 1]));
    }
   // std::cout << "return" << std::endl;
    return merkle(newHashList);
}

std::string flipEndian(std::string &str) {
    std::string newEndian = "";

    for (int i = str.size() - 1; i > 0; i = i - 2) {

        newEndian.push_back(str[i-1]);
        newEndian.push_back(str[i]);

    }

    if (str.size() % 2 == 1) {
        newEndian.push_back(str[0]);
    }

    return newEndian;
}


