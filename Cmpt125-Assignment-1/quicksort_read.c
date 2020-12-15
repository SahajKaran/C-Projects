// quicksort_read.c
// File by -> Sahaj Karan
// Student number -> 301386551
// Cmpt125-Assignment1
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<time.h>
// 1. Cut-and-paste a copy of the quicksort_messy (from quicksort_messy.c) and
//    put it below. Don't modify quicksort_messy in any way!
// quicksort_messy.c

void quicksort_messy(int number[5],int first,int last){
   int i, j, pivot, temp;

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j)
      {
         while(number[i]<=number[pivot]&&i<last)
            i++;
         while(number[j]>number[pivot])
         {
            j--;
         }
            if(i<j){
               temp=number[i];
               number[i]=number[j];
               number[j]=temp;
            }
      }

      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
      quicksort_messy(number,first,j-1);
      quicksort_messy(number,j+1,last);
   }
}

// 2. Create a testing function called test_quicksort_messy that runs tests on
//    quicksort_messy to ensure that it has no errors. There should be at
//    least 5 tests cases.

//The following is a helper function to use to test is the array is sorted or not.
int isItSorted(int number[5],int first,int last){
   
   int counter=0; /*This will be our counter if the arrray is in increaing order the counter should remain zero
                  if the counter increases from zero that means there exists a number that that is not sorted */
   
   int fcounter=0; //This is value that we can increase just in case if the array is sorted like a false counter
   
   quicksort_messy(number,first,last); //This is where we function call our quicksort so it sorts the array.
   
   for(int i=first;i<last;i++)
   {
      if(number[i]<=number[i+1])//This condition checks if the first number less than the following number.
         fcounter++;    // if the fist number is less than the following number increase the falsecounter.
      
      else
         counter++;//If number[0] is greater than number[1] that means the array is not sorted which is enough for us to return false//
         
   }

   if(counter>0) 
      return 0; 
   else
      return 1;
}

void test_quicksort_messy()
{
   int first=0,last=5;
   
   int a[5]={2,5,1,6,4};         //Case 1 ->Entirely positive array.
   assert(isItSorted(a,first,last));// Calling the helper function to check if the array is sorted or not. 
   
   int b[5]={-10,-24,-5,-2,-12};    //Case2 -> Entirely negative array.
   assert(isItSorted(b,first,last));
   
   int c[5]={6, -6, 5, -5, 5}; //Case3 -> Duplicates of positive and negative numbers.
   assert(isItSorted(c,first,last));
   
   int d[5]={-14, -12, 52, -1, 2}; //Case4 -> Mix of positive and negative number array.
   assert(isItSorted(d,first,last));
   
   int e[5]={1,0};  //Case5 -> The array is half empty.
   assert(isItSorted(e,first,last));

   int f[5]={}; //Case6 -> The array is completely empty.
   assert(isItSorted(f,first,last));

   int g[5]={1241241,8141151,62341,951245,222414};//Case7 -> Vey large integer valuse.
   assert(isItSorted(g,first,last));

   int h[5]={-1241425,-215521,-634155,-424352,-900024};//Case8 -> Very large negative integer values.
   assert(isItSorted(h,first,last));

   int i[5]={-1241425,8274911,-514155,-624352,100024};//Case9 -> Mix of very large positive and negative values.
   assert(isItSorted(i,first,last));

   srand(time(NULL)); // Seed generator for random numbers

   int j[last];
   for(int z=0;z<last;z++){
    	j[z]=rand()%10000; //Populate array with random numbers.
   }
    assert(isItSorted(j,first,last)); //Case10->Array with all random values ranging from 1-9999. 

}

// 3. Also, put your quicksort_improved and test_quicksort_improved functions
//    here.

//Quicksort_improved can take an array of any length and sort it.
void quicksort_improved(int *number,const int first, const int last){
   
   int i,j,temp,pivot;

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){

         while(number[i]<=number[pivot]&&i<last)
            i++;
         while(number[j]>number[pivot])
            j--;
         
         if(i<j){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }

      }
      
      temp=number[pivot];
      number[pivot]=number[j]; //Task for swapping variables.
      number[j]=temp;

      quicksort_improved(number,first,j-1); //Recalling the same function to repeat the steps..This function is a Recursive function. 
      quicksort_improved(number,j+1,last);
   }
}

int isItSorted_improved(int *number,int first,int last){		//Almost same to the previous function IsItSorted major difference being that it
   																// takes an array of any size and checks it if it is sorted or not . 
   int counter=0;   
   int fcounter=0;
   
   quicksort_improved(number,first,last); 						//Another diffrece is it checks if it the array is sorted or not by calling our quicksort_improved function
   
   for(int i=first;i<last;i++)
   {
      if(number[i]<=number[i+1])
         fcounter++;    
      
      else
         counter++;
   }

   if(counter>0) 
      return 0; 
   else
      return 1;
}

void test_quicksort_improved(){

    int first=0;   //First index always has to be zero.
    srand(time(NULL)); // Seed generator for random numbers

    int length=rand()%1000;
    int arr1[length];
    for(int i=0;i<length;i++){
    	arr1[i]=rand()%1000; //Populate array with random numbers.
    }
    assert(isItSorted_improved(arr1,first,length)); //Case1->Random array of random size and randome values.

    int arr2[] = {12,51,52,31,732,151,251,235,124};	//Case2->All positive numbers but small length of array.
	int length_arr2 = sizeof arr2/ sizeof arr2[0];		// length is calucated because we need the last index of the array. And to send it to our isItSorted function as the last index.
    assert(isItSorted_improved(arr2,first,length_arr2));

    int arr3[]={-15,-12,-41,-24,-23,-61,-9,-15,-31}; //Case3->All negative numbers but small length of array.
    int length_arr3 = sizeof arr3/ sizeof arr3[0];
    assert(isItSorted_improved(arr3,first,length_arr3));	

    int arr4[]={124,415,25,1,52,51,23,5423,42,3,5,12,523,56,7,2,5,754,32,5,14,51,521,562,332,3,123,234,151,6,834,1093}; //Case5->All positive numbers but large length of array.
    int length_arr4 = sizeof arr4/ sizeof arr4[0];
    assert(isItSorted_improved(arr4,first,length_arr4));

    int arr5[]={-151,-125,-251,-512,-314,-51,-512,-167,-1485,-385,-632,-518,-312,-133,-15,-4151,-512,-5125,-231,-442,-415,-900,-1234}; //Case5->All negative numbers but large length of array.
    int length_arr5 = sizeof arr5/ sizeof arr5[0];
    assert(isItSorted_improved(arr5,first,length_arr5));

    int arr6[]={-124,126,-4251,523,421,-415,-674,12,42,-415,-51,100,-10}; //Case6->Mix of positive and negative numbers but small length of array.
    int length_arr6 = sizeof arr6/ sizeof arr6[0];
    assert(isItSorted_improved(arr6,first,length_arr6));	

    int arr7[]={-412,142,-521,52,-235,-512,-16,353,-632,14521,5125,-2314,-51,-52,-612,-51,61,-51,61,23,-8713,-521,-216,612,-646,-612}; //Case7->Mix of positive and negative numbers but a large length of array.
    int length_arr7 = sizeof arr7/ sizeof arr7[0];
    assert(isItSorted_improved(arr7,first,length_arr7));

    int arr8[]={9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9}; //Case8->All the numbers are equal in a huge array.
    int length_arr8 = sizeof arr8/ sizeof arr8[0];
    assert(isItSorted_improved(arr8,first,length_arr8));	

   	int arr9[]={}; //Case8->All the numbers are equal in a huge array.
    int length_arr9 = sizeof arr9/ sizeof arr9[0];
    assert(isItSorted_improved(arr9,first,length_arr9));	
}

// 4. In the main() function for this file, call both test_quicksort_messy and
//    test_quicksort_improved.

int main(){
	
	test_quicksort_messy();
	printf("test_quicksort_messy passed all test cases\n");	//Prints this message if all assert cases pass testing.

	test_quicksort_improved();
	printf("test_quicksort_improved passed all test cases\n");
	
	return 0;
}
