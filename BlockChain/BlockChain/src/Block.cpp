/**
 *
 */

#include <string>
#include <vector>
#include "include/Header/Block.h"

using namespace std;

string Block::getKey() {

	string transact_to_str;
	vector<Transaction>::iterator it;
	Transaction curr;

	for (it = this->transactions.begin(); it != this->transactions.end(); it++) {
		curr = *it;
		transact_to_str += curr.toString();
	}

	return transact_to_str + std::to_string(this->index) + this->previousHash + std::to_string(this->nonce);
}

void Block::addTransaction(Transaction transaction) {
	this->transactions.push_back(transaction);
}

void Block::setPreviousHash(string previousHash) {
	this->previousHash = previousHash;
}

void Block::setHash(string hash) {
	this->hash = hash;
}

void Block::setIndex(int index) {
	this->index = index;
}

void Block::setNonce(int nonce) {
	this->nonce = nonce;
}

int Block::getNonce() {
	return this->nonce;
}

string Block::getHash() {
	return this->hash;
}
