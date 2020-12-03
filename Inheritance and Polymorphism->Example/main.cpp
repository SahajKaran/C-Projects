/*Author-> Sahaj Karan 
  Student#301386551	
  Cmpt225 D2 
  Assignment#1
*/

#include"animalClass.h"	//User defined library
using namespace std;

int main(){
	//array of 10 pointers to Animals with all different subclasses and an instance
	//of an superclass itself.
	Animal* animals[10];
	animals[0]=new Cat(3); 
	animals[1]=new Dog(7);
	animals[2]=new Animal(8);
	animals[3]=new Sheep(12);
	animals[4]=new Dog(1);
	animals[5]=new Cat(5);
	animals[6]=new Cow(20);
	animals[7]=new Cow(9);
	animals[8]=new Dog(14);
	animals[9]=new Animal(10);
	for(int i=0;i<10;i++){
		animals[i]->print();
	}
	for(int i=0;i<10;i++){
		delete animals[i];
	}	
	return 0;
}

