/**
 * @author Manuel G.
 * @date 13/06/2018
 * @brief Programma principale.
 */


#include "include/header/Transaction.h";
#include "include/header/Block.h";
#include "include/header/Blockchain.h";

#include <iostream>;

using namespace std;

// Main
int main() {

	string cmd;

	cout << "=======================================================================================" << endl;
	cout << "                                        <BlockChain>                                   " << endl;
	cout << "=======================================================================================" << endl;

	cout << endl;
	cout << endl;

	cout << "Continuare? [Y/n] ";
	cin >> cmd;

	if (cmd != "Y") {
		return -1;
	}

	cout << "{Init: BlockChain}" << endl;
	Block genesisBlock;
	Blockchain blockchain(genesisBlock);

	cout << "{Load: Transaction}" << endl;
	cout << "Continuare [Y/n]? : ";
	cin >> cmd;
	if (cmd != "Y") {
		return -1;
	}

	Transaction transaction("Jijio", "Jijia", 100);
	vector<Transaction> transactions;
	transactions.push_back(transaction);

	cout << "{Load: Block}" << endl;
	Block block;
	block = blockchain.getNextBlock(transactions);
	blockchain.addBlock(block);

	cout << "{End: BlockChain}" << endl;
	return 0;
}
