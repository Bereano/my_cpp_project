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

	Transaction(string from, string to, int amount);

	virtual ~Transaction();

private:

	string from;
	string to;
	int amount;

};

#endif /* SRC_INCLUDE_HEADER_TRANSACTION_H_ */
