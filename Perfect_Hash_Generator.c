#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//--------------------------------creates a perfect hash function for any set of numbers------------------------

int * getArray(void); //prompt user for numbers first number in returnd array it's length

int findK(int, int *, int); // k the number that avoides collisions
int isK(int, int, int *, int); //test a number
int isCollision(int *, int); //check if given k has collisions

int findBiggerPrime(int);// finds a prime bigger than a given number
int biggestNum(int *, int);// finds biggest number in aan array
int isPrime(int);// primality test...



void main(){
	
	int * array = getArray();
	int len = array[0];
	int * set = array+1;
	
	int p = findBiggerPrime(biggestNum(set,len)); // finds the prime for the function 
	int k = findK(p, set, len);
	
	printf("for the number you provided the hash function is:\n((%d*X)%%%d)%%%d\n",k,p,len);
	for(int i=0; i<len; i++)
		printf("((%d*%d)%%%d)%%%d = %d\n",k,set[i],p,len,((k*set[i])%p)%len);
	
}

// prompt user for more inputs
//creates an array during run time, length of the array is saved i
//first number in array is length
int * getArray(){
	int length = 1;
	int * array = (int *) malloc(2*sizeof(int));
	printf("enter numbers set (character will terminate):\n%d>>>",length);
	while(scanf("%d",&array[length])){
		array = (int *) realloc((void *) array,(++length+1)*sizeof(int));
		printf("\n%d>>>",length);
	}
	free((void *)array[length--]);
	array[0] = length;
}
		
	
	

//find k 
int findK(int prime, int * set, int length ){ 

	int k; 
	for(k=0;k <= length && !isK(k, prime, set, length);k++){
		//---------------printf("maybe %d ...\n",k);
	}
	if (k == length)
		return -1;
	return k;
}

//  k -> x = k*set[i]%p%length while p is a prime bigger than any number in the set so that for any x[i] and x[j] (i!= j) x[i] != x[j]
int isK(int k, int prime, int * set, int length){
	for (int i = 0; i < length; i++) //populate x
		for (int j = 0; j < length; j++)
			if (i!=j && ((k*set[j])%prime)%length == ((k*set[i])%prime)%length){ // a collision
				//----------printf("collision...\n");
				return 0;
			}
	return 1;
}

// find the biggest number ib the set
int biggestNum(int * array, int length){
	int biggest = array[0];
	for (int i = 1; i < length; i++)
		if (array[i] > biggest)
			biggest = array[i];
	return biggest;
}

// finds a prime bigger than a given number
int findBiggerPrime(int n){
	n = n; //for a significantly bigger prime 
	while(!isPrime(++n));
	return n;
}

// not so efficient primality test from stackoverflow ;)
int isPrime(int n){
    int i,root;
    if (n%2 == 0 || n%3 == 0)
        return 0;
    root = (int)sqrt(n);
    for (i=5; i<=root; i+=6){
        if (n%i == 0)
           return 0;
    }
    for (i=7; i<=root; i+=6){
        if (n%i == 0)
           return 0;
    }
    return 1;
}

















