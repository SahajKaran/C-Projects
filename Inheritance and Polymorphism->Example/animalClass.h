/*Author-> Sahaj Karan 

#include<string>
#include<iostream>
using namespace std;

class Animal{	//Principal class.
	private:
		int Age; //Storing age for Animal in months.
	public:
		Animal(int age);//Animal class Constructor.
		
		const int ageInMonths();	//Member functions.
		static int repeats();		//repeats is statically bounded.	
		const virtual string noise();	//noise is dynamically bounded.
		
		void print();
		~Animal();
};

//Start for member definitions of Animal.
Animal::Animal(int age)
:Age(age){};//Initializing age.

const int Animal::ageInMonths()	{return Age;}	//Definitions of member functions.
int Animal::repeats()		{return 4;}
const string Animal::noise()	{return "grunt";}

void Animal::print(){	//Printing values.
	cout<<ageInMonths()<<" ";

	for(int i=0;i<repeats();i++){	//Printing age in months and
		cout<<noise()<<" ";			// number of times the animals noise is repeated on same line.
	}

	cout<<"\n"<<endl;//New line
}
//End for member definitions of Animal.

//Subclass #1 Cow.
class Cow: public Animal{
	public:
		Cow(int age);
		static int repeats();
		const virtual string noise();
		~Cow();
};
Cow::Cow(int age)
:Animal(age){};	//Passing age to Animal class via constructor arguement.
const string Cow::noise(){return "mooo";}
int Cow::repeats(){return 4;}


//Subclass #2 Dog.
class Dog: public Animal{
	public:
		Dog(int age);
		static int repeats();
	    const virtual string noise();
		~Dog();
};
Dog::Dog(int age)
:Animal(age){};	//Passing age to Animal class via constructor arguement.
const string Dog::noise(){return "woof";}
int Dog::repeats(){return 2;}


//Subclass #3 Cat.
class Cat: public Animal{
	public:
		Cat(int age);
		static int repeats();
		const virtual string noise();
		~Cat();
};
Cat::Cat(int age)
:Animal(age){};	//Passing age to Animal class via constructor arguement.
const string Cat::noise(){return "meow";}
int Cat::repeats(){return 1;}


//Subclass #4 Sheep.
class Sheep: public Animal{
	public:
		Sheep(int age);
		static int repeats();
		const virtual string noise();
		~Sheep();
};
Sheep::Sheep(int age)
:Animal(age){};	//Passing age to Animal class via constructor arguement.
const string Sheep::noise(){return "bahh";}
int Sheep::repeats(){return 5;}

	//Deconstructors
Animal:: ~Animal(){};	
Cow:: ~Cow(){};
Dog:: ~Dog(){};
Cat:: ~Cat(){};
Sheep:: ~Sheep(){};

