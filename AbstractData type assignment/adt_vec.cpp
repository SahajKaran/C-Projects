//Assignment5-Sahaj Karan
//Std number-301386551

#include "Stack.h"
#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

class Vec_stack : public Stack {
private:
	vector<string>vec;
public:
	Vec_stack(){ }  //default constructor

	// Pre-condition:
    //    none
    // Post-condition:
    //    returns true if the stack is empty, and false otherwise
	bool is_empty() const {
		
		unsigned int a = vec.size();
		if(a!=0)
			return 0;
		return 1;
	}

	// Pre-condition:
    //    none
    // Post-condition:
    //    returns the number of elements in this stack
	int size() const {
		return vec.size();
	}

	// Pre-condition:
    //    none
    // Post-condition:
    //    puts x on the top of the stack
	void push(const string& x){
		vec.push_back(x);
	}

	// Pre-condition:
    //    none
    // Post-condition:
    //    pushes all the elements of v onto the stack; first v[0] is pushed,
    //    then v[1], etc.
	void push(const vector<string>& v){
		for (int i = 0; i<v.size(); i++){
			string s = v[i];
			vec.push_back(s);
		}
	}

	// Pre-condition:
    //    none
    // Post-condition:
    //    if x occurs anywhere on the stack, then does nothing; otherwise,
    //    pushes x onto the stack
	void push_new(const string& s){
		
		bool ans = 0;
		for(int i = 0; i<vec.size(); i++){
			if(s == vec[i])
				ans= 1;
		}

		if(!ans)
			vec.push_back(s);
	}

	// Pre-condition:
    //    !is_empty()
    // Post-condition: 
    //    removes and returns the top element of the stack
	string pop(){		
		if(!is_empty()){
			string result = vec.back();
			vec.pop_back();
			return result;
		}
		return 0;
	}

	// Pre-condition:
    //    none
    // Post-condition: 
    //    if n <= 0, an empty vector is returned; otherwise, pops the first n items 
    //    off the stack and returns them in a vector such that the first item of the vector
    //    is the top of the stack, the second item of the vector is the second item of the
    ///   stack, and so on; if n > size(), then all items are popped and returned
	vector<string> pop(int n){
		
		vector<string>last;
		if(n > 0 && n <= vec.size()){
			
			for(int i = 0; i < n; i++){
				string s = pop();
				last.push_back(s);
			}
			return last;
		}
		else if(n > vec.size()){
			
			while(!is_empty()){
				pop();
			}
		}

		return last;
	}

	// Pre-condition:
    //    none
    // Post-condition: 
    //    pops all elements from the stack
	void pop_all(){
		while(!is_empty())
			pop();
	}

	// Pre-condition:
    //    !is_empty()
    // Post-condition: 
    //    returns a copy of the top element of the stack (without removing it)
	string peek () const{
		return vec.back();
	}

};

int main(){
	
	//initialization, is_empty,size
	Vec_stack s; 
	assert( s.is_empty()); 					
	assert( s.size() == 0); 					

	s.push("Sahaj"); 		//push()
	assert( s.size() == 1); //size()

	vector<string>h = {"finished", "this", "assignment"};
	s.push(h);		//push with vector<string> as parameter
	assert( s.size() == 4);

	s.push_new("Sahaj");		//push_new()
	assert(s.size() == 4);	//size()

	s.push_new("today");   //push_new()
	assert(s.size() == 5);  //size()

	assert( s.pop() == "today");//pop()
	s.pop(2);									
	assert(s.size() == 2);	//size()

	assert(s.peek() == "finished"); //peek()
	s.pop_all();
	assert(s.size() == 0);	//size()
	
	//2nd set of test cases
	Vec_stack x; 								
	assert( x.is_empty()); 						
	assert( x.size() == 0); 					

	x.push("This"); 							
	assert( x.size() == 1); 					

	vector<string>b= {"is", "the", "last","hard"};
	x.push(b);		//push() with vector<string> as parameter
	assert(x.size() == 5);

	x.push_new("assignment");							
	assert(x.size() == 6);						

	x.push_new("last");						
	assert(x.size() == 6);						

	assert(x.pop() == "assignment");				
	x.pop(3);									
	assert(x.size() == 2);						

	assert(x.peek() == "is");					
	x.pop_all();								
	assert(x.size() == 0);						

	//If it reaches this point after all asserts it means all test cases passed.
	cout << "All Vec_stack tests passed\n";

	return 0;
}