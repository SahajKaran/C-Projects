//Sahaj Karan
//301386551
#include<iostream>
#include "Quadnode.h"
using namespace std;
class SkipList {
private:
   QuadNode *head;
   int count;
   int level;
   const int MAXLVL = 20;//Keeping max level 20 can be increased if we need to add more elments
   const float probability = 0.5;//keepeing P so we can take half random elements from ith level to i+1 level

public:
    SkipList(){
    Entry* e = new Entry(-1,"---");   // create head node and initialize key to -1
    head = new QuadNode(e, MAXLVL);
    level = 0;
    count = 0;
    }

    int size(){ return count;}
    bool empty(){return size()==0;}

    QuadNode* createNode(Entry *E, int level){
        QuadNode *n = new QuadNode(E, level);
        count++;
        return n;
    }
    int randomLevel() { //Getting random level
        float val = (float)rand()/RAND_MAX;
        int level = 0;
        while (val < probability && level < MAXLVL){
            level++;
            val = (float)rand()/RAND_MAX;
        }
        return level;
    }
    void insert(Entry *E){
        QuadNode *current = head;
        int key = E->getKey();
        // create update array and initialize it
        QuadNode *update[MAXLVL+1];
        //memset ->Converts the value ch to unsigned char and copies it into each of the first n characters of the object pointed to by str[].
        memset(update, 0, sizeof(QuadNode*)*(MAXLVL+1));

        for (int i = level; i >= 0; i--){ //   start from highest level of skip list
            while (current->forward[i] != NULL && current->forward[i]->key < key) //move the current pointer forward while key
                                                                                //is greater than key of node next to current
            current = current->forward[i];  //   Otherwise inserted current in update and

            update[i] = current; //   move one level down and continue search
            }
        current = current->forward[0];
        if (current == NULL || current->key != key){
          // Generate a random level for node
            int rlevel = randomLevel();
            if (rlevel > level)  {
                for (int i=level+1;i<rlevel+1;i++)
                    update[i] = head;
                    // Update the list current level
                    level = rlevel;
                    }
            // create new node with random level generated
            QuadNode* node = createNode(E, rlevel);  //rlevel= random level
            // insert node by rearranging pointers
            for (int i=0;i<=rlevel;i++) {
                node->forward[i] = update[i]->forward[i];
                update[i]->forward[i] = node;
                }
            }
        }
    void put(int k,string v){
        Entry *entry=new Entry(k,v);
        insert(entry);
    }

    Entry* greaterEntry(int key){
        QuadNode *current = head;
        for(int i = level; i >= 0; i--){
            while(current->forward[i] && current->forward[i]->key < key)
              current = current->forward[i];
            }
        current = current->forward[0]->forward[0];
        if(current and current->key > key) // If current node have key equal to search key, we have found our greater entry node
            return current->entry;
        return head->entry;
    }

    Entry* lesserEntry(int key){
        QuadNode *current = head;
        for(int i = level; i >= 0; i--) {
            while(current->forward[i] && current->forward[i]->key < key)
                current = current->forward[i];
        }
        if(current and current->key < key)  // If current node have key equal to search key, we have found our lesser entry node
            return current->entry;
        return head->entry;
    }

    Entry* find(int key){
        QuadNode *current = head;
        for(int i = level; i >= 0; i--) {
            //start from highest level of skip list
            //move the current pointer forward
            while(current->forward[i] && current->forward[i]->key < key)
                current = current->forward[i];
        }
        current = current->forward[0];
        // If current node have key equal to search key, we have found our node
        if(current and current->key == key) return current->entry;

        return head->entry;
    }

    void erase(int key){
        QuadNode *current = head;
        // create update array and initialize it
        QuadNode *update[MAXLVL+1];
        memset(update, 0, sizeof(QuadNode*)*(MAXLVL+1));
        for(int i = level; i >= 0; i--){
            while(current->forward[i] != NULL  && current->forward[i]->key < key)
                current = current->forward[i];
            update[i] = current;
        }
        current = current->forward[0];

        if(current != NULL and current->key == key) { // If current node is target node

            for(int i=0;i<=level;i++){
                if(update[i]->forward[i] != current)  //If at level i, next node is not target
                    break; //node, break the loop, no need to move further level
                update[i]->forward[i] = current->forward[i];
            }
            while(level>0 && head->forward[level] == 0)
                level--;
            count--;  // Remove levels having no elements
            cout<<"Successfully deleted key "<<key<<"\n";
        }
    }

    void print(){
        if(empty()){
            cout<<"Empty list"<<endl;
                return;
        }
        cout<<"\n--------------------Skip List--------------------"<<"\n";
        cout<<endl;
        for (int i=level;i>=0;i--){
            QuadNode *node = head->forward[i];
            QuadNode *current = head->forward[0];
            cout << "-inf--";
            while (current != NULL) {
                if(current == node){
                  cout << node->key<<"--";
                  node = node->forward[i];
                }
                else{
                  if(current->key > 9)
                    cout<<"----";
                  else
                    cout<<"---";
                }
                current = current->forward[0];
            }
            cout << "inf-\n";
        }
    }
    virtual ~SkipList(){}//Destructor
};
