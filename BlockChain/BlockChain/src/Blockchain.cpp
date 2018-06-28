/*
 * Blockchain.cpp
 *
 *  Created on: 27 giu 2018
 *      Author: ae25711
 */

#include <iostream>
#include "include/header/sha256.h";
#include "include/header/Block.h";
#include "include/header/Blockchain.h";

using namespace std;

Blockchain::Blockchain(Block genesisBlock) {
	this->blocks.push_back(genesisBlock);
}

void Blockchain::addBlock(Block block) {

    if(this->blocks.size() == 0) {
      block.setPreviousHash("0000000000000000");
      block.setHash(this->generateHash(block));
    }

	this->blocks.push_back(block);
}

Block Blockchain::getNextBlock(vector<Transaction> transactions) {
    Block block;

    for (Transaction &transaction : transactions) {
    	block.addTransaction(transaction);
    }

    Block previousBlock = this->getPreviousBlock();
    block.setIndex(this->blocks.size());
    block.setPreviousHash(previousBlock.getHash());
    block.setHash(this->generateHash(block));

    return block;
}

Block Blockchain::getPreviousBlock() {
	return this->blocks.at(this->blocks.size() - 1);
}

string Blockchain::generateHash(Block block) {

    string hash = sha256(block.getKey());

    while(hash.substr(0, 3) != "000") {
      block.setNonce(block.getNonce() + 1);
      hash = sha256(block.getKey());

      cout << hash << endl;
    }

    return hash;
}
