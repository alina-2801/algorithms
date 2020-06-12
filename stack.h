/*
 * Name: stack.h
 * This file contains singly-linked list implementation of the Stack ADT
 * Follow the comments to complete the code as required for Assignment #2, Part A #1
 *
 * Group Memebers:Oscar Li, Alina Kozhamberdina
 * Date:10/17/2019
 */

#include <stdlib.h>
#include<stdio.h>
#include<stdbool.h>



typedef char StackData;     //The stack here will hold characters

//A typical implementation of a node in a singly-linked list
//Note that NodePtr is a pointer to a node.
typedef struct node {
    StackData data;
    struct node *next;
} Node, *NodePtr;

//Defining the StackType
//Note that Stack is a pointer to a StackType
typedef struct {
    NodePtr top;        //the node containing the element at the top of stack
    NodePtr top1; 
    int size;           //the number of elements in a stack
} StackType, * Stack;
int count = 0;
//Name of Function: initStack
//Input: void
//Ouput: a Stack
//Description: Initializes an empty stack
Stack initStack() {
    Stack sp;
    sp = (Stack) malloc(sizeof (StackType));

    sp->top = NULL;
    sp->size = 0;
    return sp;
}

//Name of Function: isEmpty
//Input: Stack s
//Ouput: boolean
//Description: Returns true if the Stack s is empty and false otherwise
bool isEmpty(Stack s)
{
    //Write your code here
if (s==NULL)
    return true;
else
    return false;
}

//Name of Function: size
//Input: Stack s
//Ouput: the number of elements in s
//Description: Returns the number of elements stored in s

int size(Stack s)
{
    //Write your code here
   struct node *head;
   int count = 0;  // Initialize count 
   struct node* current = head;  // Initialize current 
    while (current != NULL) 
    { 
        count++; 
        current = current->next; 
    } 
    return count; 
}


//Name of Function: push
//Input: Stack s and an element of type StackData
//Ouput: void
//Description:  pushes the new element n to the top of the Stack s,
//               and increments the size of the stack
void push(Stack s, StackData n)
{
    //First we must allocate space for a singly-linked list node
     NodePtr top; 
     struct node *temp;    
     if (top == NULL)
    {
        top =(struct node *)malloc(1*sizeof(struct node));
        top->next = NULL;
        top->data = n;
    }
    else
    {
        temp = (struct node *)malloc(1*sizeof(struct node));
        temp->next = top;
        temp->data = n;
        top = temp;
    }
    count++;
}




//Name of Function: pop
//Input: Stack s
//Ouput: an element of type StackData
//Description: Checks if the Stack is empty before popping. If empty, print an error message and
//          exit the program. If s is not empty, remove the node from the top of the stack and return
//          the element stored.  Don't forget to deallocate the memory and decrement the size of the stack.

StackData pop(Stack s)
{
 //Write your code here
    NodePtr top;
    NodePtr top1;
    top1 = top;
    if (top1 ==NULL){
         printf("\n Error : Trying to pop from empty stack");
        exit(0);
    }else{
    top1 = top1->next;
    printf("\n Popped value : %d", top->data);
    free(top);
    top = top1;
    count--;
    }
}

//Name of Function: peek
//Input: Stack s
//Ouput: an element of type StackData
//Description: Checks if the Stack is empty before popping. If empty, print an error message and
//          exit the program. If s is not empty,  return the element stored at the top of the stack
//          without popping the stack.

StackData peek(Stack s)
{
    //Write your code here:
     struct node* head;
   //  StackData data;
     if (head == NULL){ 
        printf("Stack is empty");
        exit(0);}
    else
        return head-> data; 
}