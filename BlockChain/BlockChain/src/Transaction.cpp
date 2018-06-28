/*
 * Transaction.cpp
 *
 *  Created on: 18 giu 2018
 *      Author: emanuel
 */

#include <string>
#include "include/header/Transaction.h";

Transaction::Transaction() {
	this->from = "";
	this->to = "";
	this->amount = 0;
}

Transaction::Transaction(string from, string to, int amount) {
	this->from = from;
	this->to = to;
	this->amount = amount;
}

string Transaction::toString() {
	return this->from + this->to + std::to_string(this->amount);
}
