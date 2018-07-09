/*
 * Transaction.cpp
 *
 *  Created on: 18 giu 2018
 *      Author: emanuel
 */

#include <string>
#include "include/header/Transaction.h";

Transaction::Transaction() {
	this->sender = "";
	this->recipient = "";
	this->amount = 0;
}

Transaction::Transaction(string sender, string recipient, int amount) {
	this->sender = sender;
	this->recipient = recipient;
	this->amount = amount;
}

string Transaction::toString() {
	return this->sender + this->recipient + std::to_string(this->amount);
}
