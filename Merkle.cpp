
#include <iostream>
#include "Merkle.h"
#include "sha256.h"

std::string hash2(std::string &a, std::string &b) {

    std::string a1 = flipEndian(a);
    std::string b1 = flipEndian(b);


    std::string h = sha256(a1+b1);

    std::string returnH = flipEndian(h);
    return returnH;
}

//Uses a list of transaction hashes to construct a merkle tree
std::string merkle(std::vector<std::string> &hashList) {
    if (hashList.size() == 1) {
        return hashList[0];
    }
    std::vector<std::string> newHashList;
    for (int i = 0; i < hashList.size() - 1; i = i + 2) {

        newHashList.push_back(hash2(hashList[i], hashList[i+1]));
    }
    if (hashList.size() % 2 == 1) {
        newHashList.push_back(hash2(hashList[hashList.size() - 1], hashList[hashList.size() - 1]));
    }

    return merkle(newHashList);
}

//Changes the hash to be read from big-endian to little-endian
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


