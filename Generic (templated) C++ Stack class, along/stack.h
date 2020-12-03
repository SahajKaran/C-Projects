//
//Name-> Sahaj Karan
//Student number-> 301386551
//CMPT225 Assignment 2
//
#include<iostream>
#include<string>
using namespace std;

class EmptyStackException {
	private:	//Private member
		string error;
	public:		//Publuc members.
		EmptyStackException(const string& e)
		: error(e){};
		string getError() const { return error; }
};

template<typename T> //creating template
class Stack{
    private:      //public members
        T* array;
        int index; //index
        int cap; //stack capacity

    public:
        Stack(int capa = 4 )
        :array(new T[capa]), cap(capa)
       
        { index = -1 ;}
        T& pop()
            throw(EmptyStackException);

        void push(const T& element);
        
        bool empty() const {return( index < 0 );};
        
        int size() const { return (index + 1); } //size of the stack
        
        int capacity() const { return cap; } 	  //capacity of the stack

        ~Stack() { //destructor
            index = -1;
            delete [] array;
        }

};

template<typename T>
T& Stack<T>::pop()throw(EmptyStackException){
	if(empty()) throw(EmptyStackException("pop"));	//pop

	T& element = array[index];
	index--;
	return element;	//return element popped.
}

//Code from Book
template<typename T>
void Stack<T> :: push(const T& element){//push items onto stack
	
    if(size() == capacity()) {
		
        cap = 2* cap;					//doubles the size if size tends to exceed capacity
		T* newArr = new T[cap];
		
        for(int i = 0; i < size(); i++) {
			newArr[i] = array[i];
            }

        delete[]array;
		array =  new T[cap];	//reinitializing the array to get the elements back to it
                                //array with 2*cap
		for(int i = 0; i< size(); i++){
			array[i] = newArr[i];
            }
		delete[]newArr;
        }

    index++;
    array[index]=element;
}




