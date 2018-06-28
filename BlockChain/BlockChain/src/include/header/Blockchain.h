/*
 * Blockchain.h
 *
 *  Created on: 27 giu 2018
 *      Author: ae25711
 */

#ifndef SRC_INCLUDE_HEADER_BLOCKCHAIN_H_
#define SRC_INCLUDE_HEADER_BLOCKCHAIN_H_

#include <vector>;
#include "Block.h";

class Blockchain {

public:
	Blockchain(Block genesisBlock);
	virtual void addBlock(Block block);
	virtual Block getNextBlock(vector<Transaction> transactions);
	virtual Block getPreviousBlock();
	virtual string generateHash(Block block);

private:
	std::vector<Block> blocks;
};


#endif /* SRC_INCLUDE_HEADER_BLOCKCHAIN_H_ */
