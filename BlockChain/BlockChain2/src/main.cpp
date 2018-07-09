/**
 * @author Manuel G.
 * @date 13/06/2018
 * @brief Programma principale.
 */

// Boost Library
#include <boost/uuid/uuid.hpp>            // uuid class
#include <boost/uuid/uuid_generators.hpp> // generators
#include <boost/uuid/uuid_io.hpp>         // streaming operators etc.

// C++ Library
#include <string>;
#include <iostream>;

// Blockchain Header
#include "include/header/Transaction.h";
#include "include/header/Block.h";
#include "include/header/Blockchain.h";

using namespace std;

// Main
int main() {

	string cmd;

	cout << "=======================================================================================" << endl;
	cout << "                                        <BlockChain>                                   " << endl;
	cout << "=======================================================================================" << endl;

	boost::uuids::uuid uuid = boost::uuids::random_generator()();

	std::cout << uuid << std::endl;

	cout << endl;
	cout << endl;

	cout << "Continuare? [Y/n] ";
	cin >> cmd;

	if (cmd != "Y") {
		return -1;
	}

	cout << "{Init: BlockChain}" << endl;
	Blockchain blockchain;

	cout << "{Load: Transaction}" << endl;
	cout << "Continuare [Y/n]? : ";
	cin >> cmd;
	if (cmd != "Y") {
		return -1;
	}

	cout << "{Load: Transaction}" << endl;
	Transaction transaction("Jijio", "Jijia", 100);
	//vector<Transaction> transactions;
	//transactions.push_back(transaction);
	blockchain.addTransactionToPendingTransactions(transaction);

	cout << "{Load: Block}" << endl;
	Block lastBlock = blockchain.getLastBlock();
	string previousBlockHash = lastBlock.getHash();
	Block currentBlock(lastBlock.getIndex(), blockchain.getPendingTransactions());

	// Proof Of Work
	time_t rawtime;
	struct tm * timeinfo;
	char buffer[80];

	time (&rawtime);
	timeinfo = localtime(&rawtime);

	strftime(buffer,sizeof(buffer),"%d-%m-%Y %I:%M:%S",timeinfo);
	std::string str(buffer);

    clock_t begin = clock();
    cout << "{Start Mining... <Start time: " + str + ">}" << endl;

	int nonce = blockchain.getProofOfWork(previousBlockHash, currentBlock);

	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

	cout << "{Finish <Nonce: " + std::to_string(nonce) + " Time elapsed: " + std::to_string(elapsed_secs) + " sec.>" << endl;


	string blockHash = blockchain.getHashBlock(previousBlockHash, currentBlock, nonce);
	Block newBlock = blockchain.createNewBlock(nonce, previousBlockHash, blockHash);

	cout << "{End: BlockChain}" << endl;
	return 0;
}
