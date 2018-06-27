/*============================================================================
 Name        : main.cpp
 Author      : Manuello
 Version     :
 Copyright   : Your copyright notice
 Description : Main Test Class Animal
============================================================================*/

#include <iostream>
#include <Exception>
#include "../Header/include/Dog.h"

using std;

/**
 * Main
 */
int main() {

    //
	cout << "============================================================================" << endl;
	cout << "==                                 INIZIO                                 ==" << endl;
	cout << "============================================================================" << endl;

	cout << endl;
	cout << endl;
	cout << endl;

    Dog my_dog("Fuffy");

    my_dog.move("Stazione", "Casa mia");
    my_dog.speak();
    my_dog.stay();


	cout << endl;
	cout << endl;
	cout << endl;

	cout << "============================================================================" << endl;
	cout << "==                                  FINE                                  ==" << endl;
	cout << "============================================================================" << endl;

	return 0;
}
