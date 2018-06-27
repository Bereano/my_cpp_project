/*
 * Transaction.cpp
 *
 *  Created on: 18 giu 2018
 *      Author: emanuel
 */

#include "include/Header/Transaction.h";

Transaction::Transaction(string from, string to, int amount) {
	this->from = from;
	this->to = to;
	this->amount = amount;
}

Transaction::~Transaction() {
	//
}

