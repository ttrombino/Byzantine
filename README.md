# Byzantine Cryptocurrency Simulator

This simple program was developed to understand blockchain, cryptocurrency, and general cryptography.
The program allows a user to develop a blockchain via the terminal window using the Byzantine mock cryptocurrency (BYZ) to make transactions 
between other users. After registration, each user is given a unique address from which currency can be sent and recieved.  
The user can also "mine" the Byzantine currency via proof of work protocol similar to Bitcoin.  

## How To Run
Simply clone the repository and run the `SHA.exe` executable file in the `cmake-build-debug` folder.

## Structure
Byzantine's blockchain is a simple dynamically allocated linked list that is created when the first block is "mined"
and destroyed when the program is closed. Therefore, the Byzantine economy only exists for as long as the program is running. 
Each block contains a list of transactions made between various users along with a header giving the block size and the block's hash ID. 

## Generating Currency
The Byzantine cryptocurrency (BYZ) is generated when a user "mines" a block of transactions. That is, the user must run the mine command until a [SHA256](https://en.wikipedia.org/wiki/SHA-2) hash 
that matches the given difficulty (i.e. the set leading 0's of the hash) is found. This is very similar to Bitcoin's Hashcash-based proof of work system explained [here](https://en.wikipedia.org/wiki/Hashcash#Bitcoin_mining).
The user that successfully mines the block is given a flat amount of currency that may be sent to other users. The only way to add BYZ to the blockchain economy is by mining these blocks. 

## Exchanging BYZ
Each time a user makes a transaction, the user's balance is verified via the traversal of the entire linked list. The user's balance
is calculated through the sum of their transactions backtraced to when the address was first created. Thus, every user has the same ledger of transactions
to determine their balance ensuring it's validity. 
