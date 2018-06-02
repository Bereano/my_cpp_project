/*
 * Animal.cpp
 *
 *  Created on: 26 mag 2018
 *      Author: ae25711
 */

#include "../Header/include/Animal.h"

#include <iostream>


Animal::Animal() {
	// TODO Auto-generated constructor stub

}

void Animal::move(string from, string to) {
	std::cout << "Sto camminando da: " << from << " a " << to << std::endl;
}

void Animal::stay() {
	std::cout << "Sto qui." << std::endl;
}

Animal::~Animal() {
	std::cout << "Chiamata a Distruttore Classe Animal" << std::endl;
}

