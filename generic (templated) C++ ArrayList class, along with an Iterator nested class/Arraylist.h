//
//Name-> Sahaj Karan

#include<iostream>
#include<string>
using namespace std;

class InvalidIteratorException { //Iterator exception
	private:
		string errMsg; //error message
	public:
		InvalidIteratorException(const string& err) //constructor
		:errMsg(err){}
		string getError() { return errMsg; } //access error message
};
class EmptyListException {	//List exception
	private:	//Private member
		string error;
	public:		//Public members.
		EmptyListException(const string& e)
		:error(e){};
		string getError() const { return error; }
};

template<typename T>
class Arraylist{
private:
	int cap;//Array is supposed to grow when it reaches its capacity
	T *array;
	int numElm;	//Number of elements in the array ie->length of array
	int fro, rear; //fro stands for the start of the array list and rear is for the end
	
public:
	//Start of Nested class
	//REQUIREMENT->Iterator should be a nested class within ArrayList.
	class Iterator{
    private:
        int pos;
        Arraylist<T> & array1;
    public:
        Iterator(Arraylist<T> & arr,int i): array1(arr),pos(i){};
        T& operator*(){return array1[pos];}
        Iterator& operator++(){
            Iterator* temp = this;
            pos++;
            return temp;
            }
        Iterator& operator--(){
            Iterator* temp = this;
            pos--;
            return temp;
            }
        bool operator==(const Iterator& i) {return *this == *(i.array1);}
        bool operator != (const Iterator i) {return array1 != (i.array1);}
    };
	
// 	class Iterator{
//        			 	 // nested class can access
//                      // private members of ArrayList class
// 	private:
// 		T& value;
// 		int pos;		
// 	public:
// 		Arraylist * const owner;
// 		Iterator(int p){
// 			pos = (owner->fro + p)% owner->cap;
// 			value = owner->array[p];
// 		}//position of iterator

// 		Iterator(Arraylist & owner) : owner(&owner) { }

// 		T& operator*(){ return value;}// gives the reference to the object at the iterator’s position.

// 		Iterator& operator++(){
// 			if (pos == owner->rear) pos = owner->fro;
// 			else if (pos == owner->cap -1) pos = 0;
// 			else pos += 1;
// 			return *this;
// 		} // moves the iterator one forward in the ArrayList

// 		Iterator& operator--(){
// 			if (pos ==owner-> fro) pos = owner->rear;
// 			else if (pos == 0) pos = owner->cap -1;
// 			else pos -= 1;
// 			return *this;
// 		} // moves the iterator one backwards in the ArrayList

// 		bool operator==(const Iterator& i)const{return value == i.value;} // compares this iterator with the iterator i. Works even if i
// 									// is an invalid iterator.
//         bool operator!=(const Iterator& i) const{ return value!= i.value;}

 // declaration Nested class ends here
  
   Arraylist(int initial=4)
   :cap(initial),fro(-1),rear(0),numElm(0),array(new T[initial]){};	//Constructor
	
	T& operator[](int i){
		return array[(fro + i)%numElm];
	} // returns the element at index i of the ArrayList.
	   // note that this is not index i of the underlying array.

	T& front(){
		return array[fro];
	}// returns the element at the front of the ArrayList.

	T& back(){
		return array[rear];
	} // returns the element at the back of the ArrayList.

	void insertFront(const T& e);// insert at the front of the ArrayList.
 	// Grows underlying array if necessary.

	void insertBack(const T& e); // insert at the back of the ArrayList.
 	// Grows underlying array if necessary.

	void insert(Iterator p,const T& e){
	};// insert before the iterator p. This could involve growing
 	// the underlying array and/or copying elements forward in it.

	void removeFront(){
		if(empty()) throw(EmptyListException("Empty"));
		if (fro == rear){ fro = -1; rear = -1;}
		else
			if (fro == cap - 1) fro = 0;
			else fro += 1;
		numElm -= 1;
	};// removes the front element of the ArrayList.
	  // throw an EmptyListException if ArrayList is empty.

	void removeBack(){
		if(empty()) throw(EmptyListException("Empty"));
		if (fro == rear){ fro = -1; rear = -1;}
		else if (rear == 0) rear = cap - 1;
		else rear -= 1;
		numElm -= 1;
	}// removes the back element of the ArrayList.
 	  // throw an EmptyListException if ArrayList is empty.

	void remove(Iterator p){};// removes the element at the iterator p from the ArrayList.
 	// may involve copying of elements.
 	// throw if ArrayList is empty.

	int size()const{
		return (numElm);
	} // number of elements in ArrayList

	int capacity() const{
		 return cap;
	} 	  //capacity of the list

	bool empty()const{
		return(numElm<=0);
	}; // is size = 0?

	void extend(){
		if(size() == capacity()) {
        cap = 2*cap;					//doubles the size if size tends to exceed capacity
		T* newArr = new T[cap];
		for(int i = 0; i < size(); i++) {
			newArr[i] = array[(fro +i)% numElm];
            }
		fro = 0;
		rear = size() - 1 ;
        delete[]array;
		   array =  new T[cap];	//reinitializing the array to get the elements back to it
                        //array with 2*cap
		   for(int i = 0; i< size(); i++){
		   array[i] = newArr[i];
    	}
		delete[]newArr;
	}
	};
	Iterator begin(){
		return Iterator(fro);
	}// an iterator to the first element

	Iterator end(){
		return Iterator(rear);
	} 	// an iterator to the element after the last element.

	~Arraylist(){
		delete[] array;
	}	//Destructor
};

template<typename T>
void Arraylist<T> :: insertFront(const T& e){
		if(numElm==cap){
			extend(); //Grow array if the number of elements is equal to the capacity of the arry.
		}
		if (fro == -1){fro = 0; rear =0;}
		//Inserting an element to start of the array
		else if (fro == 0) fro = cap - 1;
		else fro= fro - 1;
		array[fro] = e;
		numElm += 1;
};
template<typename T>
void Arraylist<T> :: insertBack(const T& e){
		if(numElm==cap){
			extend(); //Grow array if the number of elements is equal to the capacity of the arry.
		}
		if (fro == -1){ fro = 0; rear =0;}
		else if (rear == cap -1) rear = 0;
		else rear += 1;
		array[rear] = e;
		numElm += 1;
}


