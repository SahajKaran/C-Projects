//
//Name-> Sahaj Karan
//Student number-> 301386551
//CMPT225 Assignment 2
//
#include<iostream>
#include<string>
using namespace std;
class Employee{
private: //private members.
	string employee;
	string id;

public:	//public members.
	//Constructor
	Employee(string empName,string empId){	
		employee=empName;
		id=empId;
	}
	string getID(){	//Get the employees id.
		return id;
	}
	string getName(){	//Get the employees name.
		return employee;
	}
	
	//Adding the employee name with his id number.
	string toString(){
	string empPlusId =getName()+" "+getID();
	return empPlusId;
	}
};