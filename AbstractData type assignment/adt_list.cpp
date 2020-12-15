
//Assignment5-Sahaj Karan
//Std number-301386551

#include "Stack.h"
#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

class List_stack : public Stack 
{
private:  //firstly creating a linked list.
    class Node {
    public:
        string val;
        Node* next;
        };
    Node* head = nullptr;

public:
    List_stack() {}
    ~List_stack() {
        pop_all();
    }

    // Pre-condition:
    //    none
    // Post-condition:
    //    returns true if the stack is empty, and false otherwise
    bool is_empty() const {
        if (head == nullptr){
            return 1;
        }

        return 0;
    }

    // Pre-condition:
    //    none
    // Post-condition:
    //    returns the number of elements in this stack
    int size() const  {
        int track = 0;
        Node* p = head;
        while (p!= nullptr){
            track++;
            p = p-> next;
        }
        return track;
    }

    // Pre-condition:
    //    none
    // Post-condition:
    //    puts x on the top of the stack
    void push(const string& x){
        head = new Node{x, head};
    }

    // Pre-condition:
    //    none
    // Post-condition:
    //    pushes all the elements of v onto the stack; first v[0] is pushed,
    //    then v[1], etc.
    void push(const vector<string>& v){
        for (int i = 0; i<v.size(); i++){
            string s = v[i];
            head = new Node{s, head };
        }
    }

    // Pre-condition:
    //    none
    // Post-condition:
    //    if x occurs anywhere on the stack, then does nothing; otherwise,
    //    pushes x onto the stack
    void push_new(const string& s){
        bool ans = 0;
        Node*p = head;
        while(p != nullptr){
            if(p->val == s)
                ans = 1;
            p = p->next;
        }
        if(!ans)
            head = new Node{s, head};
    }

    // Pre-condition:
    //    !is_empty()
    // Post-condition: 
    //    removes and returns the top element of the stack
    string pop(){
    	//given condition
        if(!is_empty()) {	
            string result = head->val;
            Node* p = head;
            head = head->next;
            delete p;
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
        if(n > 0 && n <= size()){
            for(int i = 0; i < n; i++){
                string s = pop();
                last.push_back(s);
            }
            return last;
        }
        else if(n > size()) {
            while(!is_empty())
                pop();
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
        return head->val;
    }
};

//TEST FUNCTION 1
void list_stack_test1()
{	
	List_stack x;
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

    cout<<"All list_stack test cases-1 passed\n";
}

//TEST FUNCTION 2
void list_stack_test2()
{
    List_stack s;                                //initialization
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

    cout<<"All list_stack test cases-2 passed\n";
}

int main()
{
    list_stack_test1();
    list_stack_test2();

}