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
	 * Restituisce la "chiave" del Blocco
	 * @param[in] none
	 * @return void
	 */
	virtual string getKey();

	/**
	 * Aggiunge una transazione al Blocco
	 * @parameter: none
	 * @return: void
	 */
	virtual void addTransaction(Transaction transaction);

	/**
	 * Distruttore
	 */
	virtual ~Block();

private:

	int index = 0;
	string previousHash = "";
	string hash = "";
	int nonce = 0;
	vector<Transaction> transactions;

};

#endif

