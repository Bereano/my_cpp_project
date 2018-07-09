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
#include <ctime>
#include "Transaction.h"

using std::string;
using std::vector;
using std::time;

class Block {

public:

	/**
	 * @brief Costruttore Blocco
	 * @param Indice
	 * @param Vettore transazioni
	 * @param Nonce
	 * @param Hash Blocco corrente
	 * @param Hash Blocco precedente
	 */
	Block(int index, vector<Transaction> transactions, int nonce, string hash, string previousBlockHash);

	/**
	 * @brief Costruttore Blocco
	 * @param Indice
	 * @param Hash Blocco precedente
	 * @param Hash Blocco corrente
	 */
	Block(int index, int nonce, string hash, string previousBlockHash);

	/**
	 * @brief Costruttore Blocco
	 * @param Indice
	 * @param Vettore transazioni pendenti
	 */
	Block(int index, vector<Transaction> transactions);

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

	/**
	 * @brief Restituisce Indice della Blockchain.
	 * @result Indice
	 */
	virtual int getIndex();

	/**
	 * @brief "Stringify" Block.
	 * @param Stringa del Blocco
	 */
	virtual string toString();

private:

	int index = 0;
	time_t timestamp;
	string previousHash = "";
	string hash = "";
	int nonce = 0;
	vector<Transaction> transactions;

};

#endif

