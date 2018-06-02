/*
 * Dog.h
 *
 *  Created on: 26 mag 2018
 *      Author: ae25711
 */

#ifndef DOG_H_
#define DOG_H_

#include <string>
#include "Animal.h"

using namespace std;

class Dog: public Animal {
public:

	string name; // Nome del cane
	int age;     // Età del cane


	/*
	 * Constructor
	 * @param[in] Name of the dog
	 * @param[in] Age of the dog
	 */
	Dog(string name, int age = 10);



	/*
	 * Make a sound
	 */
	void speak();


};

#endif /* DOG_H_ */
