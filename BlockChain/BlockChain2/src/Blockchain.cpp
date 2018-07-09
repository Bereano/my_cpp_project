/*
 * Blockchain.cpp
 *
 *  Created on: 27 giu 2018
 *      Author: ae25711
 */

#include <iostream>
#include "include/header/Sha256.h";
#include "include/header/Block.h";
#include "include/header/Blockchain.h";

using namespace std;

const string Blockchain::POF_HASH_PREFIX = "00000";
const int Blockchain::POF_HASH_LENGTH = 5;
const string Blockchain::GENESIS_HASH_PREVIOUS_BLOCK = "0";

Blockchain::Blockchain() {
	Block genesisBlock(0, 100, "0", "0");
	this->chain.push_back(genesisBlock);
}

Block Blockchain::createNewBlock(int nonce, string previousBlockHash, string hash) {
	Block lastBlock = this->getLastBlock();
	Block newBlock(lastBlock.getIndex() + 1, this->pendingTransactions, nonce, hash, previousBlockHash);
	this->pendingTransactions = *new vector<Transaction>();
	this->chain.push_back(newBlock);
	return newBlock;
}

Block Blockchain::getLastBlock() {
	return this->chain.at(this->chain.size() - 1);
}

string Blockchain::getHashBlock(string previousBlockHash, Block currentBlock, int nonce) {

	string hash;
	hash = sha256(previousBlockHash + std::to_string(nonce) + currentBlock.toString()); // @suppress("Invalid arguments")
    return hash;
}

int Blockchain::getProofOfWork(string previousBlockHash, Block currentBlock) {

	int nonce = 0;
	string hash = this->getHashBlock(previousBlockHash, currentBlock, nonce);

	while (hash.substr(0, POF_HASH_LENGTH) != POF_HASH_PREFIX) {
		hash = this->getHashBlock(previousBlockHash, currentBlock, ++nonce);
		//cout << hash << endl;
	}

	return nonce;
}

int Blockchain::addTransactionToPendingTransactions(Transaction transaction) {
	this->pendingTransactions.push_back(transaction);
	Block lastBlock = this->getLastBlock();
	return lastBlock.getIndex();
}

vector<Transaction> Blockchain::getPendingTransactions() {
	return this->pendingTransactions;
}
