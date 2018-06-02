/*
 * Animal.h
 *
 *  Created on: 26 mag 2018
 *      Author: ae25711
 */

#ifndef ANIMAL_H_
#define ANIMAL_H_

#include<string>

using std::string;

class Animal {
public:
	Animal();
	virtual ~Animal();

	virtual void speak() = 0;

	/*
	 * Muove Animale da un posto "from" ad un altro "to"
	 * @param[in] from Posizione Iniziale
	 * @param[in] to   Posizione Finale
	 * @return    void
	 */
	virtual void move(string from, string to);

	void stay();
};

#endif /* ANIMAL_H_ */
