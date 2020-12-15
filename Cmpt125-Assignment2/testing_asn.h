// testing_asn.hd
// Submitted by - Sahaj Karan 
// Student number - 301386551 
#include <assert.h>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>
//
// IMPORTANT: All the implementations of "ok" functions are dummy
// implementations. Change them to properly test the corresponding function.
// 

////////////////////////////////////////////////////////////////////////////
//
// Declarations of sum_arr functions.
//
// Each of the following functions has this specification:
//
//    Pre-condition:
//       0 <= n, n is the length of arr
//    Post-condition:
//       Returns the sum of the integers in arr,
//       i.e. arr[0] + arr[1] + arr[2] + ... + arr[n]. 
//       The sum of an array of length 0 is 0.
//
// The implementations for these functions are in the file
// secret_asn_functions.h. Do NOT implement them here!
//
// The corresponding "ok" function should return true (1) if all tests for
// that function pass, and false (0) if 1, or more, fail.
//
////////////////////////////////////////////////////////////////////////////
// void printArray(int *arr, int n) 	//Helper function that prints the array 
// { 
//     int i; 
//     for (i = 0; i < n; i++) 
//         printf("%d ", arr[i]); 
//     printf("\n"); 
// }

int sum_arr1(int* arr, int n);

int sum_arr1_ok() {
   int counter=0; //This counter keeps track of how many test cases we get right
   
   int arr[]={1,2,3,4,5,6};	//testCase1-all positive and sorted.
   int size=sizeof arr/ sizeof arr[0];	//to find size of the arrays.
   if(sum_arr1(arr,size)==21){
   		counter++;
   }

   int arr2[] = {-1,-2,-3,-4,-5,-6}; //testCase2-all negative numbers
   int size2=sizeof arr2/ sizeof arr2[0];
   if(sum_arr1(arr2,size2)==-21){
   		counter++;
   }

   int arr3[] = {1}; //testCase3-one element only
   int size3=sizeof arr3/ sizeof arr3[0];
   if(sum_arr1(arr3,size3)==1){
   		counter++;
   }

   int arr4[] = {}; //testCase4-empty array
   int size4=sizeof arr4/ sizeof arr4[0];
   if(sum_arr1(arr4,size4)==0){
   		counter++;
   }

   int arr5[] = {2,2,2,2,2}; //testCase5-all the same numbers
   int size5=sizeof arr5/ sizeof arr5[0];
   if(sum_arr1(arr5,size5)==10){
   		counter++;
   }

   int arr6[] = {1,-2,3,-1,-5,-1,4}; //testCase6-mix of negative and positive numbers.
   int size6=sizeof arr6/ sizeof arr6[0];
   if(sum_arr1(arr6,size6)==-1){
   		counter++;
   }
   if(counter==6){//If the counter equals to 6 that means that all the test cases passes and we can return true
   		return 1; //If the sum of all of the test cases returns the right value return true.
   }
   else{
   		return 0;
   }

}

int sum_arr2(int* arr, int n);

int sum_arr2_ok() {
   int counter=0; //This counter keeps track of how many test cases we get right
   
   int arr[]={1,2,3,4,5,6};	//testCase1-all positive and sorted.
   int size=sizeof arr/ sizeof arr[0];	//to find size of the arrays.
   if(sum_arr2(arr,size)==21){
   		counter++;
   }

   int arr2[] = {-1,-2,-3,-4,-5,-6}; //testCase2-all negative numbers
   int size2=sizeof arr2/ sizeof arr2[0];
   if(sum_arr2(arr2,size2)==-21){
   		counter++;
   }

   int arr3[] = {1}; //testCase3-one element only
   int size3=sizeof arr3/ sizeof arr3[0];
   if(sum_arr2(arr3,size3)==1){
   		counter++;
   }

   int arr4[] = {}; //testCase4-empty array
   int size4=sizeof arr4/ sizeof arr4[0];
   if(sum_arr2(arr4,size4)==0){
   		counter++;
   }

   int arr5[] = {2,2,2,2,2}; //testCase5-all the same numbers
   int size5=sizeof arr5/ sizeof arr5[0];
   if(sum_arr2(arr5,size5)==10){
   		counter++;
   }

   int arr6[] = {1,-2,3,-1,-5,-1,4}; //testCase6-mix of negative and positive numbers.
   int size6=sizeof arr6/ sizeof arr6[0];
   if(sum_arr2(arr6,size6)==-1){
   		counter++;
   }
   if(counter==6){//If the counter equals to 6 that means that all the test cases passes and we can return true
   		return 1; //If the sum of all of the test cases returns the right value return true.
   }
   else{
   		return 0;
   }
    
}

int sum_arr3(int* arr, int n);

int sum_arr3_ok() {
   int counter=0; //This counter keeps track of how many test cases we get right
   
   int arr[]={1,2,3,4,5,6};	//testCase1-all positive and sorted.
   int size=sizeof arr/ sizeof arr[0];	//to find size of the arrays.
   if(sum_arr3(arr,size)==21){
   		counter++;
   }

   int arr2[] = {-1,-2,-3,-4,-5,-6}; //testCase2-all negative numbers
   int size2=sizeof arr2/ sizeof arr2[0];
   if(sum_arr3(arr2,size2)==-21){
   		counter++;
   }

   int arr3[] = {1}; //testCase3-one element only
   int size3=sizeof arr3/ sizeof arr3[0];
   if(sum_arr3(arr3,size3)==1){
   		counter++;
   }

   int arr4[] = {}; //testCase4-empty array
   int size4=sizeof arr4/ sizeof arr4[0];
   if(sum_arr3(arr4,size4)==0){
   		counter++;
   }

   int arr5[] = {2,2,2,2,2}; //testCase5-all the same numbers
   int size5=sizeof arr5/ sizeof arr5[0];
   if(sum_arr3(arr5,size5)==10){
   		counter++;
   }

   int arr6[] = {1,-2,3,-1,-5,-1,4}; //testCase6-mix of negative and positive numbers.
   int size6=sizeof arr6/ sizeof arr6[0];
   if(sum_arr3(arr6,size6)==-1){
   		counter++;
   }
   if(counter==6){//If the counter equals to 6 that means that all the test cases passes and we can return true
   		return 1; //If the sum of all of the test cases returns the right value return true.
   }
   else{
   		return 0;
   }
    
}

int sum_arr4(int* arr, int n);

int sum_arr4_ok() {
   int counter=0; //This counter keeps track of how many test cases we get right
   
   int arr[]={1,2,3,4,5,6};	//testCase1-all positive and sorted.
   int size=sizeof arr/ sizeof arr[0];	//to find size of the arrays.
   if(sum_arr4(arr,size)==21){
   		counter++;
   }

   int arr2[] = {-1,-2,-3,-4,-5,-6}; //testCase2-all negative numbers
   int size2=sizeof arr2/ sizeof arr2[0];
   if(sum_arr4(arr2,size2)==-21){
   		counter++;
   }

   int arr3[] = {1}; //testCase3-one element only
   int size3=sizeof arr3/ sizeof arr3[0];
   if(sum_arr4(arr3,size3)==1){
   		counter++;
   }

   int arr4[] = {}; //testCase4-empty array
   int size4=sizeof arr4/ sizeof arr4[0];
   if(sum_arr4(arr4,size4)==0){
   		counter++;
   }

   int arr5[] = {2,2,2,2,2}; //testCase5-all the same numbers
   int size5=sizeof arr5/ sizeof arr5[0];
   if(sum_arr4(arr5,size5)==10){
   		counter++;
   }

   int arr6[] = {1,-2,3,-1,-5,-1,4}; //testCase6-mix of negative and positive numbers.
   int size6=sizeof arr6/ sizeof arr6[0];
   if(sum_arr4(arr6,size6)==-1){
   		counter++;
   }
   if(counter==6){//If the counter equals to 6 that means that all the test cases passes and we can return true
   		return 1; //If the sum of all of the test cases returns the right value return true.
   }
   else{
   		return 0;
   }

}


////////////////////////////////////////////////////////////////////////////
//
// Declarations of binary search functions.
//
// Each of the following functions has this specification:
//
//    Pre-condition:
//       v has n elements and is in ascending sorted order, i.e.
//       v[0] <= v[1] <= ... <= v[n-1]
//    Post-condition:
//       returns an index i such that v[i] == x; if x is not in
//       v, -1 is returned
//
// The implementations for these functions are in the file
// secret_asn_functions.h.
//
// The corresponding "ok" function should return true (1) if all tests for
// that function pass, and false (0) if 1, or more, fail.
//
////////////////////////////////////////////////////////////////////////////

int binary_search1(int* v, int n, int x);

int binary_search1_ok() {
   int counter=0; //This will keep counting if our test case passes or no.

   int arr[]={};	//testCase1-An empty array 
   //Finding -> 1 should return false
   int size=sizeof arr/ sizeof arr[0];	//to find size of the arrays.
   if(binary_search1(arr,size,3)==-1){
   		counter++;
   }
   
   int arr2[] = {2,2,3,4,5,6,2}; //testCase2-Positive array but repeating numbers
   //Finding -> 2  should return 1
   int size2=sizeof arr2/ sizeof arr2[0];
   if(binary_search1(arr2,size2,2)==1){
   		counter++;
   }

   int arr3[] = {1,2,3,4,5,6,7}; //testCase3-Best case for comparisions
   //Finding -> 4 should return 3
   int size3=sizeof arr3/ sizeof arr3[0];
   if(binary_search1(arr3,size3,4)==3){
   		counter++;
   }

   int arr4[] = {1}; //testCase4-only one element in array
   //Finding -> 4 should return -1
   int size4=sizeof arr4/ sizeof arr4[0];
   if(binary_search1(arr4,size4,4)==-1){
   		counter++;
   }

   int arr5[] = {-10,-8,-6,-4,-3,-2,-2,-2,-1}; //testCase5-all negative numbers
   //Finding -> -1 should return 8
   int size5=sizeof arr5/ sizeof arr5[0];
   if(binary_search1(arr5,size5,-1)==8){
   		counter++;
   }

   int arr6[] = {10023,314341,516126,623431,777777}; //testCase6-Extremly large values
   //Finding -> 623431 should return 3
   int size6=sizeof arr6/ sizeof arr6[0];
   if(binary_search1(arr6,size6,623431)==3){
   		counter++;
   }

   if(counter==6){//If the counter equals to the amount of our test cases it will return True
   		return 1; //Return true if all test cases pass
   }
   
   else{
   		return 0; //If any case fails it will fail
   }

}

int binary_search2(int* v, int n, int x);

int binary_search2_ok() {
   int counter=0; //This will keep counting if our test case passes or no.

   int arr[]={};  //testCase1-An empty array 
   //Finding -> 1 should return false
   int size=sizeof arr/ sizeof arr[0]; //to find size of the arrays.
   if(binary_search2(arr,size,3)==-1){
         counter++;
   }
   
   int arr2[] = {2,2,3,4,5,6,2}; //testCase2-Positive array but repeating numbers
   //Finding -> 2  should return 1
   int size2=sizeof arr2/ sizeof arr2[0];
   if(binary_search2(arr2,size2,2)==1){
         counter++;
   }

   int arr3[] = {1,2,3,4,5,6,7}; //testCase3-Best case 
   //Finding -> 4 should return 3
   int size3=sizeof arr3/ sizeof arr3[0];
   if(binary_search2(arr3,size3,4)==3){
         counter++;
   }

   int arr4[] = {1}; //testCase4-only one element in array
   //Finding -> 4 should return -1
   int size4=sizeof arr4/ sizeof arr4[0];
   if(binary_search2(arr4,size4,4)==-1){
         counter++;
   }

   int arr5[] = {-10,-8,-6,-4,-3,-2,-2,-2,-1}; //testCase5-all negative numbers
   //Finding -> -1 should return 8
   int size5=sizeof arr5/ sizeof arr5[0];
   if(binary_search2(arr5,size5,-1)==8){
         counter++;
   }

   int arr6[] = {10023,314341,516126,623431,777777}; //testCase6-Extremly large values
   //Finding -> 623431 should return 3
   int size6=sizeof arr6/ sizeof arr6[0];
   if(binary_search2(arr6,size6,623431)==3){
         counter++;
   }

   if(counter==6){//If the counter equals to the amount of our test cases it will return True
         return 1; //Return true if all test cases pass
   }
   
   else{
         return 0; //If any case fails it will fail
   }

}

////////////////////////////////////////////////////////////////////////////
//
// Declarations of sorting functions.
//
// Each of the following functions has this specification:
//
//    Pre-condition:
//       none
//    Post-condition:
//       modifies v so it is in ascending sorted order, i.e.
//       v[0] <= v[1] <= ... <= v[n-1]
//
// The implementations for these functions are in the file
// secret_asn_functions.h.
//
// The corresponding "ok" function should return true (1) if all tests for
// that function pass, and false (0) if 1, or more, fail.
//
////////////////////////////////////////////////////////////////////////////

int isSorted(int*s,int n){ 		
  int c = 1;
   int i = 0;
   while ((c == 1) && i < n - 1){
      if (s[i] > s[i + 1]){
         c = 0;
      }
      i++;
   }
   if (c == 1) {
      return 1;   //return true if the array is sorted
   }

   else{
      return 0;   //return false if the array is not sorted
   }
}

void sort1(int* v, int n);

int sort1_ok() {
   int counter=0; //Counter increases every time a test case passes.

   int arr[]={4,2,5,6,1,4,1,5,1,5,7,8,9};	//testCase1-all positive numbers
   int size=sizeof arr/ sizeof arr[0];	//to find size of the arrays.
   sort1(arr,size);			//Calling the sort function from secret_asn_functions
   if(isSorted(arr,size)==1){
   		counter++;
   }

   int arr2[] = {-1,-3,-20,-10,-23,-56,-12,-24,-5}; //testCase2-all negative numbers
   int size2=sizeof arr2/ sizeof arr2[0];
   sort1(arr2,size2);
   if(isSorted(arr2,size2)==1){
   		counter++;
   }

   int arr3[] = {}; //testCase3-empty array
   int size3=sizeof arr3/ sizeof arr3[0];
   sort1(arr3,size3);		
   if(isSorted(arr3,size3)==1){
   		counter++;
   }

   int arr4[] = {-12,24,-25,-23,-41,65,-24,4,0,-6,-5,12,34,65,-7,8}; //testCase4-mix of positive and negative numbers.
   int size4=sizeof arr4/ sizeof arr4[0];
   sort1(arr4,size4);
   if(isSorted(arr4,size4)==1){
   		counter++;
   }

   int arr5[] = {2}; //testCase5-one element in the array
   int size5=sizeof arr5/ sizeof arr5[0];
   sort1(arr5,size5);
   if(isSorted(arr5,size5)==1){
   		counter++;
   }

   int arr6[] = {15153,124451,6341,41556,-124145,7613,-451245,-61234,5673,31341515,1412515}; //testCase6-Very big values array and very small negative values
   int size6=sizeof arr6/ sizeof arr6[0];
   sort1(arr6,size6);
   if(isSorted(arr6,size6)==1){
   		counter++;
   }

   if(counter==6){
   		return 1; //If the sum of all of the test cases returns the right value return true.
   }
   else{
   		return 0;
   }
}
  

void sort2(int* v, int n);

int sort2_ok() {
   int counter=0; //Counter increases every time a test case passes.

   int arr[]={4,2,5,6,1,4,1,5,1,5,7,8,9};	//testCase1-all positive numbers
   int size=sizeof arr/ sizeof arr[0];	//to find size of the arrays.
   sort2(arr,size);			//Calling the sort function from secret_asn_functions
   if(isSorted(arr,size)==1){
   		counter++;
   }

   int arr2[] = {-1,-3,-20,-10,-23,-56,-12,-24,-5}; //testCase2-all negative numbers
   int size2=sizeof arr2/ sizeof arr2[0];
   sort2(arr2,size2);
   if(isSorted(arr2,size2)==1){
   		counter++;
   }

   int arr3[] = {}; //testCase3-empty array
   int size3=sizeof arr3/ sizeof arr3[0];
   sort2(arr3,size3);		
   if(isSorted(arr3,size3)==1){
   		counter++;
   }

   int arr4[] = {-12,24,-25,-23,-41,65,-24,4,0,-6,-5,12,34,65,-7,8}; //testCase4-mix of positive and negative numbers.
   int size4=sizeof arr4/ sizeof arr4[0];
   sort2(arr4,size4);
   if(isSorted(arr4,size4)==1){
   		counter++;
   }

   int arr5[] = {2}; //testCase5-one element in the array
   int size5=sizeof arr5/ sizeof arr5[0];
   sort2(arr5,size5);
   if(isSorted(arr5,size5)==1){
   		counter++;
   }

   int arr6[] = {15153,124451,6341,41556,-124145,7613,-451245,-61234,5673,31341515,1412515}; //testCase6-Very big values array and very small negative values
   int size6=sizeof arr6/ sizeof arr6[0];
   sort2(arr6,size6);
   if(isSorted(arr6,size6)==1){
   		counter++;
   }

   if(counter==6){
   		return 1; //If the sum of all of the test cases returns the right value return true.
   }
   else{
   		return 0;
   }
   
}
