#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isPrime(int num); //Check if number is a prime
void mSort(int *array, const int array_size); //Sorts array(ints)
void printIntArray(int *array, const int array_size); //prints arrays with enclosing {}

int main(int argc, char **argv){
  const int iArray[11] = {2,19,77,3,4,16,8,66,1,-333,0};
  const int ARRAY_LENGTH = sizeof(iArray) / sizeof(int);
  
  int *iArrayDyn;
  int *iArrayPrimes;
  int *iArraySorted;

  //Allocating & copying over values to dynamic array
  iArrayDyn = (int *)malloc(ARRAY_LENGTH * sizeof(int));
  if(!iArrayDyn){
    printf("Failure to allocate array\n");
    exit(EXIT_FAILURE);
  }

  for(int i = 0; i < ARRAY_LENGTH; i++){
    iArrayDyn[i] = iArray[i];
  }

  //Printing initial values
  printf("Input:\n");
  printIntArray(iArrayDyn, ARRAY_LENGTH);
  
  //Sorting array
  iArraySorted = (int *)malloc(ARRAY_LENGTH * sizeof(int));
  if(!iArraySorted){
    printf("Failed to allocate sorted array\n");
    exit(EXIT_FAILURE);
  }
  memcpy(iArraySorted, iArrayDyn, ARRAY_LENGTH * sizeof(int));
  mSort(iArraySorted, ARRAY_LENGTH);
  printf("\nSorted(ASC):\n");
  printIntArray(iArraySorted, ARRAY_LENGTH);
  
  //Getting prime elements in sorted array
  iArrayPrimes = (int *)malloc(ARRAY_LENGTH * sizeof(int));
  if(!iArrayPrimes){
    printf("Failed to allocated sorted primes array\n");
    exit(EXIT_FAILURE);
  }
  
  int iArrayPrimesPos = 0;
  for(int i = 0; i < ARRAY_LENGTH; i++){
    if(isPrime(iArraySorted[i])){
      iArrayPrimes[iArrayPrimesPos] = iArraySorted[i];

      iArrayPrimesPos++;
    }
  }

  //Resizing memory for actual size(primes)
  iArrayPrimes = (int *)realloc(iArrayPrimes, iArrayPrimesPos * sizeof(int));
  if(!iArrayPrimes){
    printf("Failed to resize sorted primes array\n");
    exit(EXIT_FAILURE);
  }


  printf("\n");
  printf("Primes - Sorted(ASC)\n");
  printIntArray(iArrayPrimes, iArrayPrimesPos);
  
  free(iArrayDyn);
  free(iArrayPrimes);
  free(iArraySorted);

  return EXIT_SUCCESS;
}

/**
 *
 * Prints arrays with enclosed {}
 *
 **/
void printIntArray(int *array, const int array_size){
  printf("{");

  for(int i = 0; i < array_size; i++){
    printf("%d", array[i]);
    if(i < array_size - 1){
      printf(",");
    }
  }

  printf("}\n");
}

/**
 *
 * Sorts int array(asc)
 *
 **/
void mSort(int *array, const int array_length){
  int temp;
  int temp2;
  
  for(int i = 0; i < array_length; i++){
    for(int j = 0; j < array_length; j++){
      if(i != j && array[i] < array[j]){
	temp = array[j];
	temp2 = array[i];

	array[i] = temp;
	array[j] = temp2;
      }
    }
  }
}

/**
 *
 * Determines if number is prime(int)
 *
 **/
bool isPrime(int num){
  bool result = true;
  bool divisorFound = false;

  if(num < 1){
    result = false;
  } else {
    for(int i = num / 2; i > 1 && !divisorFound; i--){
      if(num % i == 0){
	divisorFound = true;

	break;
      }
    }

    if(divisorFound){
      result = false;
    }
  }

  return result;
}
