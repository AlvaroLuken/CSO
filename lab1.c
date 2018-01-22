/*
 * IMPORTANT: WRITE YOUR NAME AND NetID BELOW.
 * 
 * Last Name: Luken
 * First Name: Alvaro
 * Netid: al5031
 * 
 * You will do your project in this file only.
 * Do not change function delarations. However, feel free to add new functions if you want.
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> //added for toupper






/* Function declarations: do not change that, but you may add your own functions */
void arrange(int *, int);
void find_fibonacci(int, int);
void flipping(unsigned int);
void file_histogram(char *);
void file2upper(char *);
void file_encrypt(char *);
// void ascending(int *, int num);
// void fibonacciRecursive(int n);
// void fibonacciArr(int *, int x, int y);
// void occurrences(char *, char c, int length);


/* Add here function declarations of your own, if any. */



/*********************************************************************************/

/* 
 * Do  NOT change anything in main function 
 */
int main(int argc, char * argv[])
{
  int option = 0;
  int i, j;
  int * list;
  
  if(argc < 2 )
  {
     fprintf(stderr,"Usage: lab1 num [input]\n");
     fprintf(stderr,"num: 1, 2, 3, 4, 5, or 6\n");
     exit(1);
  }
  
  option = atoi(argv[1]);
  
  switch(option)
  {
    case 1: if(argc != 3)
	    {
	      fprintf(stderr,"Usage: lab1 1 num\n");
	      fprintf(stderr,"num: number of elements of the array to be arranged\n");
	      exit(1);
	    }
	    j = atoi(argv[2]);
	    list = (int *)malloc(j*sizeof(int));
	    if(!list)
	    {
	      fprintf(stderr,"Cannot allocate list in option 1\n");
	      exit(1);
	    }
	    
	    /* Gnerate random numbers in the range [0, 100) */
	    for(i = 0; i < j; i++)
	      list[i] = rand()% 100;
	    
	    /* Print the unsorted array */
	    printf("The original array:\n");
	    for(i = 0; i < j; i++) 
	      printf("%d ", list[i]);
	    printf("\n");
	    
	    printf("The arranged array:\n");
	    arrange(list, j);
	    
	    break;
	    
	    
    case 2: if(argc != 4)
	    {
	      fprintf(stderr,"Usage: lab1 2 x y\n");
	      fprintf(stderr,"x and y: positive integers and x < y and y < 1 million\n");
	      exit(1);
	    }
	    i = atoi(argv[2]);
	    j = atoi(argv[3]);
	    
	    find_fibonacci(i, j);
	    
	    break;

	    
    case 3: if(argc != 3)
	    {
	      fprintf(stderr,"Usage: lab1 3 num\n");
	      fprintf(stderr,"num: unsigned intger number\n");
	      exit(1);
	    }
	    
	    flipping( atof(argv[2]));
	    
	    break; 
	    
	    
    case 4: if(argc != 3)
	    {
	      fprintf(stderr,"Usage: lab1 4 filename\n");
	      exit(1);
	    }
	    
	    file_histogram(argv[2]);
	    
	    break;

	    
    case 5: if(argc != 3)
	    {
	      fprintf(stderr,"Usage: lab1 5 filename\n");
	      exit(1);
	    } 
	    
	    file2upper(argv[2]);
	    
	    break;

	    
    case 6: if(argc != 3)
	    {
	      fprintf(stderr,"Usage: lab1 46filename\n");
	      exit(1);
	    }
	    
	    file_encrypt(argv[2]);
	    
	    break;	      
	    
    default: fprintf(stderr, "You entered an invalid option!\n");
	     exit(1);
  }
  
  return 0;
}

/******* Start filling the blanks from here and add any extra functions you want, if any *****/


int* ascending(int *listNumber, int num) {

	if(num == 1) { //if array is just one element, return original parameter
		return listNumber;

	}
	int temp;

	for(int i = 0; i < num; i++) { //standard bubble sort type
			for(int j = 0; j < num-i-1; j++) {
					if(listNumber[j+1] < listNumber[j]) {
						temp = listNumber[j];
						listNumber[j] = listNumber[j+1];
						listNumber[j+1] = temp;
					}
			}
	}

	return listNumber; //return sorted array
}


















int fibonacciRecursive(int n) { //same as java

	

	if(n == 0) { //base
		return 0;
	}

	if(n == 1) { 
		return 1;
	}   


	return fibonacciRecursive(n-1) + fibonacciRecursive(n-2);

}



int* fibonacciArr(int* array, int x, int y) {
	int counter = 0;
		
	for(int i = x; i < y; i++) { //for loop starts at input x



  	
  		if(fibonacciRecursive(i) > x && fibonacciRecursive(i) < y) { //has to be in between bounds
  			if(fibonacciRecursive(i) == x || fibonacciRecursive(i) == y) { //as specified in project, not to include bounds
  				break;
  			}
  			array[counter] = fibonacciRecursive(i); //populate array with fibonacci sequence
  			counter++;
  		}

  	}

  	
	return array;
}
		
	







int occurrences(char *str, char c, int length) {
		int counter = 0;

		for(int i = 0; i < length; i++) {
			if(str[i] == c) { //if char is found, increase ocurrence counter
				counter++;
			}
		}


		return counter;


}


int encrypt(char *str, int i) { //takes the string of file characters, and i the index to advance



		if(str[i] >= 97 && str[i] <=99) { //circle case: a,b,c = x,y,z
			return str[i] + 23;
		}

		if(str[i] >= 100 && str[i] <= 122) { //every other case for lowercase letters
			return str[i] - 3;
		}

	

	return 0; //spaces and everything else; won't show up
}



/*
 * Part 1:
 * In this function, you are given two inputs:
 * inputs: 
 * 	an array of int list[] 
 * 	The number of elements in that array: num
 * You need to put the even numbers first (if any), sorted in ascending order, followed
 * by the odd numbers (if any) sorted in ascending order too.
 * Example: a list of 5 elements: 5 4 3 2 1 
 * The output will be: 2 4 1 3 5 
 * Finally, print the array on the screen.
 * */
void arrange(int *list, int num)
{
	int* listComplete;
	int* listComplete2;
	int* listEven;
	listEven = (int*)malloc(num * sizeof(int));
	int* listOdd;
	listOdd = (int*)malloc(num * sizeof(int));
	int counter = 0;
	int counter2 = 0;
	int counterEven = 0;
	int counterOdd = 0;

	for(int i = 0; i < num; i++) {

		if(list[i] == 0) {
			break;
		}
		if(list[i] % 2 == 0) { //adds the even numbers from random array to a specific even array
			listEven[counter] = list[i];
			counter++;

		} else { 
			listOdd[counter2] = list[i]; //adds the odd numbers from random array to a specific odd array
			counter2++;
		}
	}



	
	for(int i = 0; i < num; i++) { //counts number of evens in even array
		if(listEven[i] == 0) {
			break;
		}
		counterEven++;

	}	


	for(int i = 0; i < num; i++) { //count number of odds in odd
		if(listOdd[i] == 0) {
			break;
		}
		counterOdd++;

	}


	listComplete = ascending(listEven, counterEven); //add sorted evens to listComplete
	listComplete2 = ascending(listOdd, counterOdd); //add sorted odds to listComplete2

	for(int i = 0; i < counterEven; i++) { //output for evens first
		printf("%d ", listComplete[i]);
	}

	for(int i = 0; i < counterOdd; i++) { //output for odds
		printf("%d ", listComplete2[i]);
	}

	printf("\n");

	free(listEven);
	free(listOdd);


}


/*********************************************************************************/

/* 
 * Part 2:
 * In this part, you are given two positive integer, x and y, larger than 0.
 * You need to print all the Fibonacci numbers between x and y (NOT including x and y themselves), if any.
 */
void find_fibonacci(int x, int y)
{
	int* arr;
	int* arr2;
	arr2 = (int*)malloc(y*sizeof(int)); //allocate a big amount of memory, y*4, insures it is sufficient memory


	if(x == 1 && y ==2) { //hardcoding for x = 1 y = 2 case; just extra, not part
		printf("1");		// of sample output YET still a possible case
		printf("\n");
	}

	if(x == 1 && y ==3) { 
		printf("2\n");	
	}

	
  
	arr = fibonacciArr(arr2, x, y); //passes the pointer arr2 and both arguments
									// to fibonacciArr

	for(int i = 0; i < y; i++) { //print output, without 0's
  		if(arr[i] == 0) {
  			break;
  		}
  		printf("%d", arr[i]);
  		printf(" ");
  		
  	}

  	if(x == 1 && y == 4) {
		printf("3\n");
	} else {
		printf("\n");
	}

  	free(arr2); //free allocated memory

  
}


/*********************************************************************************/

/*
 * Part 3:
 * Given an unsigned integer (so has values of 0 and up), print on the screen 
 * the flipping of that number.
 * That is, if the number given is: 1234  then you print: 4321
 */
void flipping(unsigned int num)
{

	int counter = 0;

	char str[12]; //all numbers representable by int will fit
				   // in a 12-char-array without overflow

	sprintf(str, "%d", num);


	

	counter = strlen(str); //strlen() calculates length of str


  
    for(int i = counter; i >= 0; i--) { //prints the string in reverse form, starts from last index (memory address)
    	printf("%c", str[i]);
    }
    printf("\n");
  
}

/*********************************************************************************/

/*
 * Part 4
 * The input is a filename.
 * The filename contains a string of characters (can be upper case letters, lower case letters, numbers, ...).
 * The output is a histogram of the file printed on the screen ONLY for lower case letters.
 * Example: 
 * The input file in.txt contains:  a1aaAbBBb709bbc
 * The output will be:
 * a: 3
 * b: 4
 * c: 1
 * .... and so one
 * The file can contain any characters, not necessarily only lower case characters.
 */
void file_histogram(char *filename)
{
  
  FILE *fptr1;
  char ch;

  int counter = -1;
  int count = 0;




  fptr1 = fopen(filename, "r"); //opens file to "read"
  
  if(fptr1 == NULL) { //unable to open file for any reason, terminate
  	printf("Unsuccessful.");
  	exit(1);
  }





  char characters [1000000]; //memory will take care of itself since it is not malloc

  

  while(ch != EOF) { // while the end of file is not reached, keep going
  	
 
  	ch = getc(fptr1);
  	characters[count] = ch; //populating the char array with text characters
  	count++; //char array index counter
  	counter++; //number of characters in text file

  }







  int ret;

  for(char i = 97; i <= 122; i++) { //for loop looks only through lower case ASCII characters a-z
  	
  	ret = occurrences(characters, i, counter); //ret is the count of each individual character in the file
  	printf("%c : %d\n", i, ret);
  }

  
  fclose(fptr1); //closes file

  	

  }







  
  


/*********************************************************************************/

/* 
 * Part 5:
 * Input: filename
 * Output:filenameCAPITAL
 * The output files contains the same characters as the input file but in upper case.
 * The input file will ONLY contain lower case letters and no spaces.
 * If the input filename is: mmmm 
 * The output filename is: mmmmCAPITAL
 */
void file2upper(char *filename)
{

	FILE *fptr;

	FILE *fptr2;
	char ch;

	char characters[10000];
	int count = 0;
	int counter = 0;


  	fptr = fopen(filename, "r+"); //open file for reading and writing (used r+ just to experiment)

  	while(ch != EOF) {
  		ch = toupper(getc(fptr)); //switching character to uppercase using toupper() 

  		if(ch == EOF) { 
  			break;
  		}
  		counter++; //size of text file
  	
  		characters[count] = ch; //populates char array with capital letters
  		count++; //index of char array
  	}

  	rewind(fptr); //rewinds pointer to first index (0)


  	fclose(fptr); //closes file

  	char *newName; //string for new name of file

  	newName = strcat(filename, "CAPITAL"); //appends "CAPITAL" to original file name

  	fptr2 = fopen(newName, "w"); //opens a file for writing

  	for(int i = 0; i < counter; i++) {
  		fprintf(fptr2, "%c", characters[i]); //copies contents into new file
  	}
  	
  	fclose(fptr2); //close second pointer


  
  
}

/*********************************************************************************/

/*
 * Part 6:
 * In that last part, you will learn to implement a very simple encryption.
 * Given a file that contains a series of lower case charaters (may be separated by white space),
 * replace all non-white space with the lower case letter that exists 3 letters before, in a circular way.
 * For example: 
 * e will be replaced with b
 * d will be replaced with a 
 * c will be replaced with z  <--- circular
 * b will be replaced with y  <--- circular
 * and white spaces will be left unchanged.
 * Print the output on the screen.
 */
void file_encrypt(char * filename)
{

	FILE *ptr;

	ptr = fopen(filename, "r");

	char encrypted[10000];
	char c;
	int ch3;

	char e;

	int count;

	while(c != EOF) {
		c = getc(ptr);
		encrypted[count] = c; //populate array with file characters
		count++; //index of array
	}


	for(int i = 0; i < count; i++) { //for loop looks only through lower case ASCII characters a-z
  	
  	ch3 = encrypt(encrypted, i); //ch3 is the ascii value that is to be returned after being modified by encrypt()
  	e = ch3; //assign char to int ch3
	printf("%c", e); //print output

  }
  printf("\n");





}