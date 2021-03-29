cmake_minimum_required(VERSION 3.17)
project(SHA)

set(CMAKE_CXX_STANDARD 20)

add_executable(SHA main.cpp sha256.cpp Merkle.h Merkle.cpp Block.cpp Block.h Transaction.cpp Transaction.h DateTime.h Blockchain.cpp Blockchain.h)