# Byzantine Cryptocurrency Simulator

This simple program was developed to understand blockchain, cryptocurrency, and general cryptography.
The program allows a user to develop a blockchain via the terminal window using the Byzantine mock cryptocurrency to make transactions 
between other users. After registration, each user is given a unique address from which currency can be sent and recieved.  
The user can also "mine" the Byzantine currency via proof of work protocol similar to Bitcoin.  

##How To Run
The best way to run the program is to clone the repository and run the `SHA.exe` executable file in the `cmake-build-debug` folder.

## Structure
Byzantine's blockchain is a simple dynamically allocated linked list that is created when the first block is "mined"
and destroyed when the program is closed. Therefore, the Byzantine economy only exists for as long as the program is running. 
Each block contains a list of transactions made between various users along with 
a header giving the block size and the block's hash ID. 

## Generating the Byzantine currency
The Byzantine cryptocurrency is generated when a users "mines" a block of transactions. That is, the user must use the computer to find a SHA256 hash 
that matches the given difficulty. This is done in a similar fashion to Bitcoin's Hashcash proof of work system explained [here](https://en.wikipedia.org/wiki/Hashcash#Bitcoin_mining).
The user that successfully mines the block is given a flat amount of currency that may be sent to other users. The only way to add Byzantine to it's blockchain economy is 
to mine these blocks. The blockchain allows for every 

## Exchanging currency 
Each time a user makes a transactions, the user's balance is verified via the traversal of the entire linked list. The user's balance
is calculated through the sum of their transactions backtraced to when the address was first created. Thus, every user has the same ledger of transactions
to determine their balance ensuring it's validity. 
