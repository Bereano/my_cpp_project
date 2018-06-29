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

protected:
	const static string HASH_PREFIX;

public:

	const static string GENESIS_HASH_PREVIOUS_BLOCK;

	/**
	 * @brief Costruttore Blockchain
	 * @param genesisBlock
	 */
	Blockchain(Block genesisBlock);

	/**
	 * @brief Aggiunge Blocco alla Blockchain.
	 * @param Blocco
	 */
	virtual void addBlock(Block block);

	/**
	 * @brief Crea nuovo blocco.
	 * @param Vettore di Transazioni
	 * @result Nuovo Blocco
	 */
	virtual Block getNextBlock(vector<Transaction> transactions);

	/**
	 * @brief Restituisce Blocco precedente.
	 * @result Blocco precedente
	 */
	virtual Block getPreviousBlock();

	/**
	 * @brief Genera Hash in base al Blocco passato in input.
	 * @param Blocco
	 * @result Hash
	 */
	virtual string generateHash(Block block);

private:
	std::vector<Block> blocks;
};


#endif /* SRC_INCLUDE_HEADER_BLOCKCHAIN_H_ */
