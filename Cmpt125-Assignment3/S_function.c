// S_function.c
//Student name - Sahaj Karan
//Student number- 301386551
#include <stdio.h>   // these are the only permitted #includes
#include <stdlib.h>  // for this assignment.
#include <assert.h>  // Don't add any other #includes!

//
// ... add all code for question 1 here ... 
//

int S1(int n, int a, int b){	//uses recursion (and no loops) to calculate S(n,a,b).
	
	if(n==1){	//case S(1,a,b)=a given so when n(size=1) return a(value1)
		return a;
	}
	else{	//case S(n,a,b)=S(n-1)+b when n(size) is not equal to one.
	  return S1((n-1),a,b)+b;	//using recusrion to calculate.
	}
}

int S2(int n, int a, int b){   //uses one or more loops (and no recursion) to calculate S(n,a,b).
	
	int recurse=0;//this could store our value. which has initial value of 0.
	
	for(int i=1;i<=n;i++){
		
		if(i==1){
			recurse+=a; //if i=1 which is the smallest case we add a. 
		}		
		else{
			recurse+=b;	//other wise we keep adding the value b
		}
	}
	return recurse;
}

int S3(int n, int a, int b){  //calculates S(n,a,b). without using loops or recursion. It should be much more efficient than both S1 and S2.
	
	int recurse=0;
	
	if(n==1){
		return a;	//When n is equal to 1 we just return a we are given this condition.
	}
	else{
		recurse= a + b*(n-1); //Algorithm since we add (a)value1 once when n=1 and and we repeatedly add value2(b) upto n-1 times
							 //hence value2 gets add b times n-1 and then we just add both.
	}
	
	return recurse;
}

int S_test(){	//Helping tester function to make sure all our functions(S1 S2 S3) return the same value.
	
	int size,value1,value2;// n ,a ,b respectively
	
	for(int i=1;i<=10000;i++){	//For loop uptil 10000 to test all cases with multiple different sizes and random values.

		size=i;	//Size is equal to n in s1 s2 s3
		value1=rand()%100000+1;//Generating random number 1-100000	value1 is a in s1 s2 s3
		value2=rand()%100000+1;// value2 is b in s1 s2 s3

		int s1=S1(size,value1,value2);	//Passing the values to all the 3 functions.
		int s2=S2(size,value1,value2);
		int s3=S3(size,value1,value2);

		assert(s1==s2);		//Using assert to make sure all the functions give the same values.
		assert(s2==s3);
		assert(s3==s1);
	}
	
	return 1;
}

int main() {
	
	int test=S_test();	//Calling our assert funtion.
	if(test==1){
		printf("All the test passed. All functions return the same values\n");	//Passed if all the functions return the same values.
	}
	//If assertion fails it will automatically print an error message.
	
	return 0;
}
