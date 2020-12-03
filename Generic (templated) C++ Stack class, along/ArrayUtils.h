//
//Name-> Sahaj Karan
//Student number-> 301386551
//CMPT225 Assignment 2
//
#include<iostream>
#include<string>
using namespace std;

template <typename T>
class ArrayUtils{
public:	//Public members.
	static T* reverse(T* array, int size);
};
template <typename T>
T* ArrayUtils<T>::reverse(T* arr, int length) {
    Stack<T> rev_arr;//Initialising reverse. 
    for ( int i=0; i < length; i++){
        rev_arr.push(arr[i]);//Pushing to insert elements in the array.
    }
    for ( int i=0; i < length; i++) {
        arr[i] = rev_arr.pop();//Using pop to reverse.
    }
    return arr;
}


