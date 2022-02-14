#pragma once
#ifndef STACK_H
#define STACK_H

typedef struct Stack
{
	char value;
	Stack* next;
}Stack;

Stack* InitStack();
void push( char c, Stack** pStack );
void emptyStack( Stack** pStack );
void del( Stack** pStack );
char top( Stack* pStack );
char pop( Stack** pStack );
int isEmpty( Stack* pStack );

#endif