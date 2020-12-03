#include<iostream>
#include<string>
#include"Entry.h"
using namespace std;

void swap (Entry* i, Entry * j){
  Entry  temp = *i;
  *i = *j;
  *j = temp;
}

class Heap{
    private:
    //Objects of Class Entry
      Entry *array; //Entry object
      int cSize;//Current size
      int cap;//Capacity

    public:
      Heap(int size = 10): cap(size), cSize(0), array(new Entry[size]) {}; // constructor
      int size() const {return cSize;}
      bool empty() const {return cSize <= 0;}
      int parent(int i) const {int a = i <= 0 ? -1 : (i-1)/2;
        return a;
      }
      int lChild(int i) const {return 2*i+1;}  //Left child
      int rChild(int i) const {return 2*(i+1);}  //Right child

      void sizeIncrease(){  //doubles the capacity of the array if it reaches max size
        cap = 2*cap;
        Entry *newArr = new Entry[cap];
        for(int i=0; i<cap; i++)
          newArr[i] = array[i];
        delete []array;
        array = newArr;
        delete [] newArr;
      }
      int maxOutOf3(int i,int j,int k){
        if(array[i].getKey()>=array[j].getKey() && array[i].getKey()>=array[k].getKey())
          return i;
        else if(array[j].getKey()>array[i].getKey() && array[j].getKey()>array[k].getKey())
          return j;
        else return k;
      }
      int maxOutOf2(int i,int j){
        if(array[i].getKey()>=array[j].getKey())
          return i;
        else return j;
      }
      void heapDown(int i){
        if (empty() || i < 0) return;
        while (i < cSize){
          int left = lChild(i);
          int right = rChild(i);
          int max;
          if (right < cSize && left < cSize){
            max = maxOutOf3(i,left,right);
          }
          else if (left < cSize) {
            max = maxOutOf2(i,left);
          }
          else return;

          if (max == i) return;
          swap (& array[max], & array[i]);
          i = max;
        }
      }
      int minOutOf2(int i, int j){
        if (array[i].getKey()< array[j].getKey()) return i;
        else return j;
      }
      void heapUp(int i){
        if (i <= 0 || i >= cSize) return;
        while (i > 0){
          int smallest = array[parent(i)].getKey() > array[i].getKey() ? i : parent(i);
          if (smallest == i) return;
          swap (&array[i], &array[parent(i)]);
          i = parent(i);
        }
      }

      Entry removeMax(){
        Entry temp = array[0];
        cSize--;
        heapDown(0);
        return temp;
      }; // returns the maximum entry in the heap, and deletes it.

      Entry* heapSort(){
        for (int k = cSize-1; k>0; k--){
          swap(&array[0], &array[k]);
          //heapDown(0);
          cSize--;
          heapDown(0);
        }
        return array;
      }

      void insert(Entry& e){
        if(size()==cap){sizeIncrease();}
        array[cSize]=e;
        cSize++;
        heapUp(cSize-1);
      } // inserts the entry e into the heap.

      int size(){ return cSize; } // number of elements in Heap

      bool empty(){ return cSize<=0; } // is size = 0?

      void make(Entry entries[], int n){
        for(int i=0;i<n;i++){array[i]=entries[i];}
        cSize=n;
        for(int i=n-1;i>=0;i--){heapDown(i);}
      }; // does the linear bottom-up makeHeap operation
                                      // to make the heap have all of the n entries in the
                                      // array. Throws away anything already in the heap

    ~Heap(){ delete [] array; }
};
