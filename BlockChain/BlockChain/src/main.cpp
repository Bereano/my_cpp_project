/**
 * @Author: Manuel G.
 * @Date: 13/06/2018
 */


#include "include/header/Transaction.h";
#include "include/header/Block.h";
#include "include/header/Blockchain.h";

// Main
int main() {
	Block genesisBlock;
	Blockchain blockchain(genesisBlock);

	Transaction transaction("Jijio", "Jijia", 100);
	vector<Transaction> transactions;
	transactions.push_back(transaction);

	Block block;

	block = blockchain.getNextBlock(transactions);
	blockchain.addBlock(block);

	return 0;
}
