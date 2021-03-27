//
// Created by Z on 3/22/2021.
//

#ifndef SHA_MERKLE_H
#define SHA_MERKLE_H
#include <string>
#include <vector>
std::string hash2(std::string &a, std::string &b);
std::string merkle(std::vector<std::string> &hashList);
std::string flipEndian(std::string &str);

#endif //SHA_MERKLE_H
