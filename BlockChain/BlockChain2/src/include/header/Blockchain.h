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
	const static string POF_HASH_PREFIX;
	const static int POF_HASH_LENGTH;

public:

	const static string GENESIS_HASH_PREVIOUS_BLOCK;

	/**
	 * @brief Costruttore Blockchain
	 * @param genesisBlock
	 */
	Blockchain();

	/**
	 * @brief Aggiunge Blocco alla Blockchain.
	 * @param Blocco
	 * @result Nuovo Blocco
	 */
	virtual Block createNewBlock(int nonce, string previousBlockHash, string hash);

	/**
	 * @brief Restituisce Blocco precedente.
	 * @param Nonce
	 * @param Hash Blocco precedente
	 * @param Hash Blocco corrente
	 * @result Blocco precedente
	 */
	virtual Block getLastBlock();

	/**
	 * @brief genera Hash del Blocco
	 * @param Hash blocco precedente
	 * @param Blocco corrente
	 * @param Nonce
	 * @result Hash
	 */
	virtual string getHashBlock(string previousBlockHash, Block currentBlock, int nonce);

	/**
	 * @brief genera Hash del Blocco
	 * @param Hash blocco precedente
	 * @param Blocco corrente
	 * @result Nonce
	 */
	virtual int getProofOfWork(string  previousBlockHash, Block currentBlock);

	/**
	 * @brief Aggiunge transazione alla lista delle transazioni pendenti.
	 * @param Transazione
	 * @result Indice Blockchain
	 */
	virtual int addTransactionToPendingTransactions(Transaction transaction);

	/**
	 * @brief Restituisce transazioni pendenti.
	 * @result Vettore Transaction
	 */
	virtual vector<Transaction> getPendingTransactions();

private:
	std::vector<Transaction> pendingTransactions;
	std::vector<Block> chain;
};


#endif /* SRC_INCLUDE_HEADER_BLOCKCHAIN_H_ */
