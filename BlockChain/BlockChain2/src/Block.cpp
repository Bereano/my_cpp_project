/**
 *
 */

#include <string>
#include <vector>
#include <ctime>
#include "include/Header/Block.h"

using namespace std;

Block::Block(int index, vector<Transaction> transactions, int nonce, string hash, string previousBlockHash) {
	time_t timestamp;
	this->index = index;
	this->timestamp = time(&timestamp);
	this->transactions = transactions;
	this->nonce = nonce;
	this->hash = hash;
	this->previousHash = previousBlockHash;
}

Block::Block(int index, int nonce, string hash, string previousBlockHash) {
	time_t timestamp;
	this->index = index;
	this->timestamp = time(&timestamp);
	this->nonce = nonce;
	this->hash = hash;
	this->previousHash = previousBlockHash;
}

Block::Block(int index, vector<Transaction> transactions) {
	time_t timestamp;
	this->index = index;
	this->timestamp = time(&timestamp);
	this->transactions = transactions;
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

int Block::getIndex() {
	return this->index;
}

string Block::toString() {

	string dataAsString;
	vector<Transaction>::iterator it;
	Transaction curr;

	dataAsString = std::to_string(this->index) + std::to_string(this->timestamp) + std::to_string(this->nonce) + this->hash + this->previousHash;

	for (it = this->transactions.begin(); it != this->transactions.end(); it++) {
		curr = *it;
		dataAsString += curr.toString();
	}

	return dataAsString;
}
