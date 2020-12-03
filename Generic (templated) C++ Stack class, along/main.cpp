//
//Name-> Sahaj Karan
//Student number-> 301386551
//CMPT225 Assignment 2
//
#include<iostream>
#include<string>
#include"stack.h"
#include"ArrayUtils.h"
#include"employee.h"

using namespace std;

void testStackGrowth(){
	Stack<int> t;	//Test if capacity changes.

	for(int i = 0; i<10; i++){
	    int el = (2*i)+1;
		t.push(el);
		cout<<"Pushed element: "<<el<<endl;
		if ((i+1)%5 == 0)cout<<"\nCapacity of the stack: "<<t.capacity()<<"\n"<<endl;
	}
	cout<<"\nCapacity of the stack: "<<t.capacity()<<"\n"<<endl;

    while (!t.empty()){
        int el = t.pop();
        cout<<"Pop element: "<<el<<endl;
    }
    cout<<"\n=======================End===============================\n"<<endl;
}

void testStackUnderflow(){	//Testing underflow function.
	try{
		Stack<int> t;
		t.push(10);
		t.pop();
		t.pop();
		cout<<"did not catch exception"<<endl;
		}
	catch(EmptyStackException){
		cout<<"caught EmptyStackException"<<endl;
	}
	cout<<"\n=======================End===============================\n"<<endl;
}

void testReverseIntegers()//To check if arrayUtils works.
{	int arr[12] ={1, 2, 3, 4, 5, 6,7, 8, 9, 10, 11, 12};//Array of size 12 containing integers.

	cout<<"Actual order is as follows: [ ";	//Printing the right order of the array.
	cout<<arr[0];
	for(int i = 1; i < 12; i++){
		cout<<", "<<arr[i];
	}
	cout<<" ]"<<endl;
	ArrayUtils<int>::reverse(arr, 12);
	//Reversing the array.

	cout<<"Reverse order is as follows: [ "; //Printing the reverse order of the array.
	cout<<arr[0];
	for(int i = 1; i < 12; i++){
		cout<<", "<<arr[i];
	}
	cout<<" ]"<<endl;
	cout<<"\n=======================End===============================\n"<<endl;
}

void testReverseStrings()	{
	string arr[12]={"One","two","three","four","five","six","seven",
					"eight","nine","ten","eleven","twelve"};//Array of 12 strings.

	cout<<"Actual order is as follows: [ ";
	cout<<arr[0];
	for(int i = 1; i < 12; i++){
		cout<<", "<<arr[i];
	}
	cout<<" ]"<<endl;
	ArrayUtils<string>::reverse(arr, 12);
	//Reversing the array.

	cout<<"Reverse order is as follows: [ ";
	cout<<arr[0];
	for(int i = 1; i < 12; i++){
		cout<<", "<<arr[i];
	}
	cout<<" ]"<<endl;
	cout<<"\n=======================End===============================\n"<<endl;
}

void testReverseEmployees(){
	/*Employee emp[12] = {{"Ivan","1"}, {"Mindy","2"}, {"Johnson","3"}, {"Gretchen","4"},
		 {"Scottie","5"}, {"Elbert","6"}, {"Laurie","7"},{"Jaun","8"}, {"Lou","9"},
		  {"Dong","10"}, {"Marietta","11"}, {"Dudley","12"}};*/
    Employee emp[12] = {Employee("Ivan","1"), Employee("Mindy","2"), Employee("Johnson","3"), Employee("Gretchen","4"),
		 Employee("Scottie","5"), Employee("Elbert","6"), Employee("Laurie","7"),Employee("Jaun","8"), Employee("Lou","9"),
		  Employee("Dong","10"), Employee("Marietta","11"), Employee("Dudley","12")};
	string arr[12];
	for(int i = 0;i<12 ; i++){
		arr[i] = emp[i].toString();
	}

	cout<<"Actual order is as follows: [ ";
	cout<<arr[0];
	for(int i = 1; i < 12; i++){
		cout<<", "<<arr[i];
	}
	cout<<" ]"<<endl;

	ArrayUtils<string>::reverse(arr, 12);

	cout<<"Reverse order is as follows: [ ";
	cout<<arr[0];
	for(int i = 1; i < 12; i++){
		cout<<", "<<arr[i];
	}
	cout<<" ]"<<endl;
	cout<<"\n=======================End===============================\n"<<endl;
}

int main(){
	//Testing created fucntions.
	cout<<"Testing functions created"<<endl;
	testStackUnderflow();
	testStackGrowth();
	testReverseIntegers();
	testReverseStrings();
	testReverseEmployees();
}
