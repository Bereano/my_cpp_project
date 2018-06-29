/*
 * Transaction.h
 *
 *  Created on: 18 giu 2018
 *      Author: emanuel
 */

#ifndef SRC_INCLUDE_HEADER_TRANSACTION_H_
#define SRC_INCLUDE_HEADER_TRANSACTION_H_

#include <string>;
using std::string;

class Transaction {

public:

	/**
	 * @brief Costruttore
	 */
	Transaction();

	/**
	 * @brief Construttore
	 * @param From
	 * @param To
	 * @param Amount
	 */
	Transaction(string from, string to, int amount);

	/**
	 * @brief Concatena le stringe degli attributi dell'istanza in un'unica stringa,
	 * @result from + to + amount
	 */
	virtual string toString();

private:

	string from;
	string to;
	int amount;

};

#endif /* SRC_INCLUDE_HEADER_TRANSACTION_H_ */
