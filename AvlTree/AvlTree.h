
#include<iostream>
using namespace std;
class AVLTree{ 

    class node{ //nested class node start
    public:
        int info;
        node* llink;    //left node
        node* rlink;    //right node
        int peek; 
    };
    node* root;//root node

    node* singlerlinkRotate(node*& t){ //single rotation
        node* u = t->llink;
        t->llink = u->rlink;
        u->rlink = t;
        t->peek = max(peek(t->llink), peek(t->rlink)) + 1;
        u->peek = max(peek(u->llink), t->peek) + 1;
        return u;
    }
    node* singleleftlinkRotate(node*& t){ // single left rotataion
        node* u = t->rlink;
        t->rlink = u->llink;
        u->llink = t;
        t->peek = max(peek(t->llink), peek(t->rlink)) + 1;
        u->peek = max(peek(t->rlink), t->peek) + 1;
        return u;
    }

    node* doubleleftlinkRotate(node*& t){ // double left rotation
        t->rlink = singlerlinkRotate(t->rlink);
        return singleleftlinkRotate(t);
    }
    node* doublerlinkRotate(node*& t){
        t->llink = singleleftlinkRotate(t->llink);
        return singlerlinkRotate(t);
    }
    
    void empty(node* t) {// delete all the nodes
        if (t == NULL)
            return;
        empty(t->llink);
        empty(t->rlink);
        delete t;
    }

    node* put(int x, node* t){
        if (t == NULL) { //if root node
            t = new node;
            t->info = x;
            t->peek = 0;
            t->llink = t->rlink = NULL;
        }
        else if (x < t->info){//if the data is less than head node move left
            t->llink = put(x, t->llink);
            if (peek(t->llink) - peek(t->rlink) == 2){
                if (x < t->llink->info)
                    t = singlerlinkRotate(t);
                else
                    t = doublerlinkRotate(t);
            }
        }
        else if (x > t->info) { //if the data is greater than head node move right
            t->rlink = put(x, t->rlink);
            if (peek(t->rlink) - peek(t->llink) == 2) {
                if (x > t->rlink->info)
                    t = singleleftlinkRotate(t);
                else
                    t = doubleleftlinkRotate(t);
            }
        }
        t->peek = max(peek(t->llink), peek(t->rlink)) + 1;  //managing height
        return t;
    }

    node* findMinimum(node* t){ 
        if (t == NULL)
            return NULL;
        else if (t->llink == NULL)
            return t;
        else
            return findMinimum(t->llink);
    }
    node* findMaximum(node* t) {
        if (t == NULL)
            return NULL;
        else if (t->rlink == NULL)
            return t;
        else
            return findMaximum(t->rlink);
    }
    bool isLeaf(node* t) { //return true if node is leaf
        if (t == NULL)
            return false;
        if (t->llink == NULL && t->rlink == NULL)
            return true;
        isLeaf(t->llink);
        isLeaf(t->rlink);
    }

    node* erase(int x, node* t) { // delete specific node
        node* temp;
        // Element not found
        if (t == NULL)
            return NULL;

        else if (x < t->info) // Searching for element
            t->llink = erase(x, t->llink);
        else if (x > t->info)
            t->rlink = erase(x, t->rlink);
       
        else if (t->llink && t->rlink){ // Element found with 2 children
            temp = findMinimum(t->rlink);
            t->info = temp->info;
            t->rlink = erase(t->info, t->rlink);
        }
        else {  // In case of zero or one child.
            temp = t;
            if (t->llink == NULL)
                t = t->rlink;
            else if (t->rlink == NULL)
                t = t->llink;
            delete temp;
        }
        if (t == NULL)
            return t;

        t->peek = max(peek(t->llink), peek(t->rlink)) + 1;
        if (peek(t->llink) - peek(t->rlink) == -2) {// If node is unbalanced llink node is deleted, rlink case     
            // rlink rlink case
            if (peek(t->rlink->rlink) - peek(t->rlink->llink) == 1)
                return singleleftlinkRotate(t);
            
            // rlink llink case
            else
                return doubleleftlinkRotate(t);
        }
        // If rlink node is deleted, llink case
        else if (peek(t->rlink) - peek(t->llink) == 2){
            // llink llink case
            if (peek(t->llink->llink) - peek(t->llink->rlink) == 1) {
                return singlerlinkRotate(t);
            }
            // llink rlink case
            else
                return doublerlinkRotate(t);
        }
        return t;
    }

    int peek(node* t) {return (t == NULL ? -1 : t->peek);}// calculate height

    int balanceFactor(node* t){   //manages the balance factor
        if (t == NULL)
            return 0;
        else
            return peek(t->llink) - peek(t->rlink);
    }
    
    void preorder(node* t){
        if (t == NULL)
            return;
        if (isLeaf(t))  //If the node is external, print “L” for the key.
            cout << " L(0) " << endl;
        cout << t->info << "(" << peek(t) << ")" << endl;
        preorder(t->llink);
        preorder(t->rlink);
    }

    bool find(node* t, int data) { 
        if (t == NULL)
            return false;
        find(t->llink, data);
         if (t->info == data)
           return true;
        find(t->rlink, data);
        
    }

    void checkSize(node* l, int& count) { //for counting number of nodes
        if (l == NULL)
            return;
        checkSize(l->llink, count);
        count++;
        checkSize(l->rlink, count);
    }
    
    node* End(node* root, int Level, int max, node*& temp) {//gives end node
        if (root != NULL) {
            End(root->llink, ++Level, max, temp);      
            if (Level > max){
                temp = root;
                max = Level;
            }
            End(root->rlink, Level, max, temp);
        }
    }
public:
    //public fucntion of class AVLTree    
    AVLTree() {root = NULL;}//constructor

    void put(int x){root = put(x, root);}//supporting public function for inserting a node
    void erase(int x){root = erase(x, root);}// supporting public function for deleting specific node
    
    void display(){//printing a tree in preorder
        preorder(root);
        cout << endl;
    } 
    
    bool findKey(int data) { // for searching a node
        bool check = false;
        if (root == NULL) {
            return false;
        }
        else {
             check = find(root, data);
        }
        return check;
    } 
    int totalNodes() {//gives the total nodes
        int count = -1;
        if (root == NULL)
            count = 0;
        else {
            checkSize(root, count);
        }
        return count + 1;
    }
    node* getEnd() {//returns the special End node
        int max = -1;
        node* temp = End(root, 0, max, temp);
        return temp;
    }
};
