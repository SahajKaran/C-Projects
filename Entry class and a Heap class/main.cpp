#include<iostream>
#include<string>
#include"Heap.h"
using namespace std;
void print(Entry A[], int n) {
      for (int i=0; i<n; i++) {
          cout << A[i].toString() << " ";
      }
      cout <<endl;
}
void heapsort1(Entry array[],int n){ //Returns array from smallest key to largest
      Heap entry1(n);
      for(int i=0;i<n;i++){entry1.insert(array[i]);}  //Using insert to build the heap
      array=entry1.heapSort();
      print(array,n);
}
void heapsort2(Entry arr[],int n){ //Returns array from smallest key to largest
      Heap entry2(n);
      entry2.make(arr,n);     //Using Make to build the heap
      arr=entry2.heapSort();
      print(arr,n);
}

int main(){
      srand(time(0));

      Entry arr1[15];
      cout<<"=================== Test 1 ===================\n\n"<<endl;
      cout<<"Array 1 before sorting is as follows.. "<<endl;
      print(arr1,15);
      cout<<endl;
      cout<<"Array 1 after sorting is as follows.. "<<endl;
      heapsort1(arr1,15);
      cout<<endl;
      cout<<"\n\n"<<endl;


      Entry arr2[15];
      cout<<"\n=================== Test 2 ===================\n\n"<<endl;
      cout<<"Array 2 before sorting is as follows.. "<<endl;
      print(arr1,15);
      cout<<endl;
      cout<<"Array 2 after sorting is as follows.. "<<endl;
      heapsort2(arr1,15);
      cout<<endl;
      cout<<"\n\n"<<endl;

      Entry arr3[31];
      cout<<"\n=================== Test 3 ===================\n\n"<<endl;
      cout<<"Array 3 before sorting is as follows.. "<<endl;
      print(arr3,31);
      cout<<endl;
      cout<<"Array 3 after sorting is as follows.. "<<endl;
      heapsort1(arr3,31);
      cout<<"\n\n"<<endl;

      Entry arr4[31];
      cout<<"\n=================== Test 4 ===================\n\n"<<endl;
      cout<<"Array 4 before sorting is as follows.. "<<endl;
      print(arr4,31);
      cout<<endl;
      cout<<"Array 4 after sorting is as follows.. "<<endl;
      heapsort2(arr4,31);
      cout<<endl;
      cout<<"\n\n"<<endl;
}
