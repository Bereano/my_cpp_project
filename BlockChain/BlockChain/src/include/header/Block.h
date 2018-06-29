/**
 * @Class: Block
 * @Author: Manuel Galiotto <manuel.galiotto@hotmail.com>
 * @Date: 18/06/2018
 * @Description: Classe Blocco della Blockchain.
 *
 */

#ifndef BLOCK_H
#define BLOCK_H

#include <string>
#include <vector>
#include "Transaction.h"

using std::string;
using std::vector;

class Block {

public:

	/**
	 * @brief Restituisce la "chiave" del Blocco
	 * @return Hash
	 */
	virtual string getKey();

	/**
	 * @brief Accoda una nuova transazione al Blocco.
	 * @parameter Oggetto "Transaction"
	 */
	virtual void addTransaction(Transaction transaction);

	/**
	 * @brief Valorizza l'attributo del puntatore(Hash) all'oggetto Block precedente.
	 * @string Hash dell'oggetto Block precedente
	 */
	virtual void setPreviousHash(string previousHash);

	/**
	 * @brief Valorizza l'attributo "Hash" del Blocco.
	 * @param Hash
	 */
	virtual void setHash(string hash);

	/**
	 * @brief Valorizza l'attributo "Index" del Blocco.
	 * @param index
	 */
	virtual void setIndex(int index);

	/**
	 * @brief Valorizza l'attributo "Nonce" del Blocco.
	 * @param Nonce
	 */
	virtual void setNonce(int nonce);

	/**
	 * @brief Restituisce Hash del Blocco.
	 * @param Hash
	 */
	virtual string getHash();

	/**
	 * @brief Restituisce "Nonce" del Blocco.
	 * @param Nonce
	 */
	virtual int getNonce();

private:

	int index = 0;
	string previousHash = "";
	string hash = "";
	int nonce = 0;
	vector<Transaction> transactions;

};

#endif

