/*
 * Name: ParenMatch.c
 * Add code to this file to implement the ParenMatch algorithm as required for Assignment #2, Part A #2
 *
 * Group Memebers:  Alina Kozhamberdina
 * Date: 10/17/2019
 * Description: This program uses stack functions defined in stack.h and determines if the brackets in the expression are properly paired.  
 */
#include "C:/Users/Oscar Li/Desktop/stack.h"  //You may need to provide the full path to stack.h
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


bool ParenMatch(char * input);

int main()
{
    char input[100];

    printf("Enter a string with parentheses\n");
    fgets(input, sizeof(input), stdin);
    if (ParenMatch(input))
        printf("The brackets are CORRECTLY paired\n");
    else printf("The brackets are INCORRECTLY paired\n");
}

//Name of Function: ParenMatch
//Input: String i
//Ouput: boolean
//Description: Returns true if the brackets in string i are properly paired; false otherwise

bool ParenMatch(char * i)
{
    //Stack s = initStack();
    //Add your code here

 int count=0;
 
  if((*i == '}') && (count == 0))  //
  {

   return false;
  }
  else if((*i == '}') && (count !=0))
  {
  return false;
  }
  else if(*i == '{')
  {
   return false;
  }
 
 if(count == 0)
 	 return true;
 

  
}
