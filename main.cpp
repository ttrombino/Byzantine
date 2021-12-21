#include <iostream>
#include "sha256.h"
#include "Merkle.h"
#include "DateTime.h"
#include "Transaction.h"
#include "Block.h"
#include "Blockchain.h"
#include "runBlockchain.h"

using std::string;
using std::cout;
using std::endl;


int main(int argc, char *argv[])
{
    runBlockchain rb;
    rb.run();

    return 0;
}