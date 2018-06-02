/*
 * Dog.cpp
 *
 *  Created on: 26 mag 2018
 *      Author: ae25711
 */

#include "../Header/include/Dog.h"
#include <iostream>

using namespace std;

Dog::Dog(string name, int age): name(name), age(age) {
	cout << "Un nuovo cane è stato creato: " << name << ", di " << age << " anni." << endl;

}

void Dog::speak() {
	cout << name << " dice: \"Bau!\"" << endl;
}


