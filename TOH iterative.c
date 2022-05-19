/*problem statement :-Write a C program to simulate the  problem of towers of hanoi and Perform the algorithmic complexity analysis for the solution you propose.

problem description :-
                      Tower of Hanoi is a mathematical puzzle where we have three rods and n disks. 
					  The objective of the puzzle is to move the entire stack to another rod, obeying the following simple rules:
    
                      1.Only one disk can be moved at a time.
                      2.Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack
                        i.e. a disk can only be moved if it is the uppermost disk on a stack.
                      3.No disk may be placed on top of a smaller disk.
 
                      You can choose to use the function move (4, 1, 3, 2), where 4 represents the number of disks. 1 represents disks on source shaft, 
                       3 represents the destination shaft which holds the disks after the move and finally 2 represents the intermediate 
					   support shaft – temporary storage.
  
Aim                 : -The aim of the project is to demonstrate the solution to problem of towers of hanoi.
                       It is necessary to write a modular program with a scope of reusability and easier debug.
	                  The variable names should be defined in such a way that it conveys a significant meaning to debugger.
 
	    
Objectives          : -The following objectives is set for solving the stated problem.
                        
                       A) A driver program to control all modules of the program-->prototype
                          int main () {};
                       B)	Checks whether the Stack is full or not
                            isFull()
                       C)	Checks whether the Stack is empty or not
                          isEmpty()
                       D)	Inserting the elements in the stack
                          Push()
                      E)	Deleting the elements from the stack
                         Pop()
                      F)	Function to show the movement of discs
                         movedisc()

                      G)	Function to implement legal movement between two poles
                         movedisksBetweenTwoPoles()
                      H)	Function to implement the solution of towers of Hanoi based on the number of discs
                         Move()
    Algorithm :-
                step 1: START
                step 2: Define a structure to represent a stack 
                step 3: Define a function for creating a stack of given capacity.
                        *It stores the no of discs that are assigned.
               step 4: Define a function to check whether the given stack is Full or not .
                       this function checks whether the given function is full or not.
              step 5: Define a function to check whether the given stack is empty or not
                     this function checks whether the given function is empty or not.
              step 6: Define a function to add elements in to the stack using push       
                      function
                     *this function uses push function to add discs to the stack.
              step 7: Define a function to delete an element from the stack using pop 
                      function
                      this function uses pop function to remove the disc from the stack
              step 8: Define a function to show the movements of the discs
                       this function shows the movement of discs from one rod to another.
             step 9: Define a function which checks the conditions of tower of hanoi and 
             implement possible moves
             this function implement the moves if the conditions are passed
             step 10: Assign the number of discs to be shifted from starting rod to 
                     destination rod
                     accepts the data of number of discs to be shifted from starting rod            
                   to destination rod
                step 11: STOP
 */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

// A structure to represent a stack
struct Stack
  {
   unsigned capacity;
   int top;
   int *array;
  };

// function to create a stack of given capacity.
struct Stack* createStack(unsigned capacity)
     {
       struct Stack* stack =(struct Stack*) malloc(sizeof(struct Stack));
	   stack -> capacity = capacity;
	   stack -> top = -1;
	   stack -> array =(int*) malloc(stack -> capacity * sizeof(int));
	   return stack;
     }

// Stack is full when top is equal to the last index
int isFull(struct Stack* stack)
  {
    return (stack->top == stack->capacity - 1);
  }

// Stack is empty when top is equal to -1
int isEmpty(struct Stack* stack)
  {
    return (stack->top == -1);
  }

// Function to add an item to stack. It increases
// top by 1
void push(struct Stack *stack, int item)
  {
	if (isFull(stack))
		 return;
	stack -> array[++stack -> top] = item;
  }

// Function to remove an item from stack. It
// decreases top by 1
int pop(struct Stack* stack)
   {
	if (isEmpty(stack))
		return INT_MIN;
	return stack -> array[stack -> top--];
   }

//Function to show the movement of disks
void movedisc(char source, char destination, int n)
   {
	printf("Move the disk %d from \'%d\' to \'%d\'\n",n, source, destination);
   }

// Function to implement legal movement between
// two poles
void moveDisksBetweenTwoPoles(struct Stack *src,struct Stack *dest, char s, char d)
  {
	int pole1TopDisk = pop(src);
	int pole2TopDisk = pop(dest);

	// When pole 1 is empty
	   if (pole1TopDisk == INT_MIN)
	     {
	    	push(src, pole2TopDisk);
	    	movedisc(d, s, pole2TopDisk);
	     }

	// When pole2 pole is empty
    	else if (pole2TopDisk == INT_MIN)
	     {
	    	push(dest, pole1TopDisk);
	    	movedisc(s, d, pole1TopDisk);
	     }

	// When top disk of pole1 > top disk of pole2
	    else if (pole1TopDisk > pole2TopDisk)
	     {
		    push(src, pole1TopDisk);
		    push(src, pole2TopDisk);
		    movedisc(d, s, pole2TopDisk);
	     }

	// When top disk of pole1 < top disk of pole2
	    else
	     {
	    	push(dest, pole2TopDisk);
	    	push(dest, pole1TopDisk);
	    	movedisc(s, d, pole1TopDisk);
	     }
  }

//Function to implement TOH puzzle
void move(int num_of_disks, struct Stack *src, struct Stack *aux,struct Stack *dest)
 {
	int i, total_num_of_moves;
	int s = 1, d = 3, a = 2;

	//If number of disks is even, then interchange
	//destination pole and auxiliary pole
	  if (num_of_disks % 2 == 0)
	   {
		int temp = d;
	    d = a;
		a = temp;
	   }
	total_num_of_moves = pow(2, num_of_disks) - 1;

	//Larger disks will be pushed first
	for (i = num_of_disks; i >= 1; i--)
		 push(src, i);

	for (i = 1; i <= total_num_of_moves; i++)
	  {
		if (i % 3 == 1)
	    	moveDisksBetweenTwoPoles(src, dest, s, d);

		else if (i % 3 == 2)
	    	moveDisksBetweenTwoPoles(src, aux, s, a);
      
		else if (i % 3 == 0)
		    moveDisksBetweenTwoPoles(aux, dest, a, d);
	  }
 } 

// Driver Program
int main()
  {
	// Input: number of disks
	int num_of_disks;
	printf("enter total number of disc : ");
	scanf("%d",&num_of_disks);

	struct Stack *src, *dest, *aux;

	// Create three stacks of size 'num_of_disks'
	// to hold the disks
	src = createStack(num_of_disks);
	aux = createStack(num_of_disks);
	dest = createStack(num_of_disks);

	move(num_of_disks, src, aux, dest);
	return 0;
  }

