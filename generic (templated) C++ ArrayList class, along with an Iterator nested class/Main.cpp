//
//Name-> Sahaj Karan

#include<iostream>
#include"Arraylist.h"
using namespace std;
void testArrayListUnderflow(){
	int size=4;
	try{
		Arraylist<int> array;

		array.insert(0,1);
		array.removeFront();
		array.removeFront();
		cout<<"did not catch exception"<<endl;
		}
	catch(EmptyListException){
		cout<<"caught EmptyStackException"<<endl;
	}
	try{
		Arraylist<int> array;

		array.insert(1,2);
		array.removeBack();
		array.removeBack();
		cout<<"did not catch exception"<<endl;
		}
	catch(EmptyListException){
		cout<<"caught EmptyStackException"<<endl;
	}

	try{
		Arraylist<int> array;

		array.insert(2,3);
		// P is the iterator begin()
		array.remove(2);
		array.remove(2);
		cout<<"did not catch exception"<<endl;
		}
	catch(EmptyListException){
		cout<<"caught EmptyStackException"<<endl;
	}
	
	cout<<"\n=======================End===============================\n"<<endl;
}

void testIntergerIterator(){
	Arraylist<int> array;
	
	array.insertBack(1);
	array.insertBack(2);
	array.insertBack(3);
	array.insertBack(4);
	array.insertBack(5);
	array.insertBack(6);
	
	// for(ArrayList<int>::Iterator iter = array.begin(); iter != array.end(); iter++) {
	// cout << *iter <<" ";
	// }
	// cout<<endl;
	
	array.removeFront();
	array.removeFront();
	array.removeFront();
	array.insertBack(4);
	array.insertBack(5);
	array.insertBack(6);
	
	// for(ArrayList<int>::Iterator iter = array.begin(); iter != array.end(); iter++) {
	// 	cout << *iter << " ";
	// }
	cout<<endl;
	cout<<"\n=======================End===============================\n"<<endl;
}

void testStringIterator(){
	Arraylist<string> array;
	array.insertBack("Hi");
	array.insertBack("Cmpt");
	array.insertBack("225");
	array.insertBack("Assignment");
	array.insertBack("Number-3");
	array.insertBack("Bye");
	
	// for(ArrayList<string>::Iterator iter = array.begin(); iter != array.end(); iter++) {
	// 	cout << *iter << " ";
	// }
	cout << endl;

	array.removeFront();
	array.removeFront();
	array.removeFront();
	array.insertBack("Assignment");
	array.insertBack("Number-3");
	array.insertBack("Bye");
	
	// for(ArrayList<string>::Iterator iter = array.begin(); iter != array.end(); iter++) {
	// 	cout << *iter << " ";
	// }	
	// cout<<endl;

	cout<<"\n=======================End===============================\n"<<endl;
}

int main(){
	cout<<"Testing functions created"<<endl;
	testArrayListUnderflow();
	testIntergerIterator();
	testStringIterator();
	return 0;
}
