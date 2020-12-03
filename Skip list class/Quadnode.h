//Sahaj Karan
//301386551
#include "Entry.h"
class QuadNode {

  public:
    Entry * entry;
    int key;
    //Four pointers
    QuadNode * prev;
    QuadNode * next;
    QuadNode **forward;
    QuadNode **backward;

    Entry * getEntry() {return entry;}
    void setEntry(Entry * entry) { this -> entry = entry;}

    QuadNode * getNext() {return next;}
    QuadNode * getPrevious() {return prev;}

    void setNext(QuadNode * next) { this -> next = next;}
    void setPrevious(QuadNode * prev) { this -> prev = prev;}

    QuadNode(Entry * entry,int level) {
        this -> entry = entry;
        forward = new QuadNode*[level+1];
        backward = new QuadNode*[level+1];
        this->key = entry->getKey();
        // Fill forward array with 0(NULL)
        //memset ->Converts the value ch to unsigned char and copies it into each of the first n characters of the object pointed to by str[].
        memset(forward, 0, sizeof(QuadNode*)*(level+1));
        memset(backward, 0, sizeof(QuadNode*)*(level+1));

    }
    virtual~QuadNode() {}
};
