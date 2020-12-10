
#include<iostream>
#include"AvlTree.h"
using namespace std;
int main(){
    AVLTree tree; //instance of AVLTree
    cout << "Inserting 7 entries: " << endl; 
    tree.put(10);
    tree.put(20);
    tree.put(30);
    tree.put(40);
    tree.put(50);
    tree.put(60);
    tree.put(70);

    cout << endl <<"Printing the Tree: " << endl;
    tree.display();

    cout << endl << "Deleting entry 10 from the tree: " << endl;
    tree.erase(10);

    cout << endl << "Printing the Tree after deleting entry 10: " << endl;
    tree.display();

    cout << endl << "Finding existing entry 50: " << endl;
    if (tree.findKey(50)==false)
        cout << "Entry is found" << endl;
    else
        cout << " Entry not found" << endl;
    
    cout << endl << "Finding non-existing entry 10 : " << endl;  
    if (tree.findKey(10)==true)   //finding deleted entry
        cout << "Entry is found" << endl;
    else
        cout << "Entry not found" << endl;

    cout << endl << "Deleting five entries from 20 to 70 from the tree" << endl;
    tree.erase(20);
    tree.erase(30);
    tree.erase(40);
    tree.erase(50);
    tree.erase(60);
    tree.erase(70);
    cout << endl << "Printing the Tree after deleting entries 20 to 70" << endl;
    tree.display();

    cout <<endl<< "Inserting 15 entries from 80 to 220 from the tree" << endl;
    cout << endl << "Printing the Tree after insertion of 15 entries in the tree " << endl;
    tree.put(80);
    tree.put(90);
    tree.put(100);
    tree.put(110);
    tree.put(120);
    tree.put(130);
    tree.put(140);
    tree.put(150);
    tree.put(160);
    tree.put(170);
    tree.put(180);
    tree.put(190);
    tree.put(200);
    tree.put(210);
    tree.put(220);
    tree.display();

    cout << endl << "Deleting five entries from 170 to 220 : " << endl;
    tree.erase(220);
    tree.erase(210);
    tree.erase(200);
    tree.erase(190);
    tree.erase(180);
    tree.erase(170);
    cout << endl << "Printing the Tree after removal of entries 170 to 220" << endl;
    tree.display();

}