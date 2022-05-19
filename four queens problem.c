/*
problem statement   :-Write a C program to simulate the given problem  4 queens and perform the algorithmic complexity analysis for the
                      solution you propose

problem description :-The “4-Queens Problem” consists of placing four queens on a 4 x 4 chessboard so that no two queens can capture each other.
                      That is, no two queens are allowed to be placed on the same row, the same column or the same diagonal
					   (both primary and secondary diagonals).  
		
Aim                 : -The aim of the assignment is to demonstrate the solution to the problem of
                        4 queens. It is necessary to write a modular program
                       with a scope of reusability and easier debug. The variable names should
                       be defined in such a way that it conveys a significant meaning to
                       debugger.

objective           :-The following objectives is set for solving the stated  problem.
 
                    A) A driver program to control all modules of the program-->prototype
                       int main () {};
                    
                    B)condition to place a queen at certain position is done by subprogram-->prototype
                      int problem (int i,int j) {};

Algorithm for  problem (int i,intj) function :-
                    Step 1 : start 
                    Step 2: if ((j-i)%4==0)
                    Step 3 : return 1
                    Step 4 : end if
                    Step 5 : if (j-i ==3)
                    Step 6 : return 1
                    Step 7 : end if
                    Step 8 : if(j-i==5)
                    Step 9 : return 1
                    Step 10: end if
                    Step 11 : return 0
                    Step 12: end of problem (int i,int j) function.

Algorithm  for driver program :-
                   step 1:- start
                   step 2:- declare varibles x,y,z,w,q1,q2,q3,q4.
				            // q1,q2,q3,q4 are the four queens and later they are equated with x,y,z,w respectively.
				   step 2.1:-print the overview of 4*4 chess board.
				    
				   step 3:- start of for loop 1 and set q1=1 to q1<=4.
				             // for(q1=1;q1<=4;q1++)
				   step 4:- set x=q1
				   step 5:- start of for loop 2 and set q2=5 to q2<=8.
				             // for(q2=5;q2<=8;q2++)
				   step 6:- start of if (!problem(x,q2))
				   step 7:- set y=q2
				   step 8:- start of for loop 3 and set q3=9 to q3<=12
				            // for(q3=9;q3<=12;q3++)
				   step 9:- start of if(!problem(x,q3) && !problem(y,q3))
				   step 10:-set z=q3
				   step 11:-start of for loop 4 and set  q4=14 to q4<=16
				            //for( q4=14;q4<=16;q4++)
				   step 12:-start of if(!problem(x,q4) && !problem(y,q4) && !problem(z,q4))
				   step 13:- set w = q4
                   step 14:-  print the positions of the queens.
				              //printf("%d %d %d %d",x,y,z,w)
                   step 15:- return 0
                   step 16:- end if(!problem(x,q4) && !problem(y,q4) && !problem(z,q4))
                   step 17:- end of for loop 4
                   step 18:- end of if(!problem(x,q3) && !problem(y,q3))
                   step 19:- end of for loop 3.
                   step 20:- end of if(!problem(x,q2))
                   step 21:-end of for loop 2
                   step 22:- end of for loop 1
                   step 23:- stop.
				    
*/
#include <stdio.h>

int problem(int i,int j)
{//start of problem(int i,int j) function
    if((j-i)%4==0)
        return 1;
    if(j-i == 3)
        return 1;
    if(j-i == 5)
        return 1;
    return 0;
}//end of problem(int i,int j) function.
int main() 
 {//start of main();
 int x,y,z,w,q1,q2,q3,q4;
 printf("The overview of 4*4 chess board :\n 1  2  3  4\n 5  6  7  8\n 9  10 11 12\n 13 14 15 16\n\n");
       for( q1=1;q1<=4;q1++)
	   {//start of for loop 1
         x = q1;
          for( q2=5;q2<=8;q2++)
		  {//start of for loop 2
            if(!problem(x,q2))
		    {//start of if statement 1
              y = q2;
              for( q3=9;q3<=12;q3++)
			   {//start of for loop 3
                 if(!problem(x,q3) && !problem(y,q3))
				   {//start of if statement 2
                     z = q3;
                     for( q4=14;q4<=16;q4++)
					   {//start of for loop 4
                         if(!problem(x,q4) && !problem(y,q4) && !problem(z,q4))
                           {//start of if statement 3
                             w = q4;
                             printf("The positons of the queens is q1=%d q2=%d q3=%d q4=%d",x,y,z,w);//statement to print positions of the queens.
                             return 0;
                           }//end of if statement 3
                       }//end of for loop 4
                   } //end of if statement  2
               }//end of for loop 3
            }//end of  if statement 1
         }//end of for loop 2
       }//end of for loop1

 }//end of mani()
