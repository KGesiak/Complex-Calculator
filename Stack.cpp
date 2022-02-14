#include <memory>
#include "Stack.h"
Stack* InitStack()
{
	return NULL;
}
int isEmpty( Stack* pStack )
{
	return !pStack;
}
void push( char c, Stack** pStack )
{
	Stack* tempStack = (Stack*)malloc( sizeof(Stack) );
	if (!tempStack)
	{
		perror( "ERROR push: Allocation error" );
		return;
	}
	tempStack->value = c;
	tempStack->next = *pStack;
	*pStack = tempStack;
}
void del( Stack** pStack )
{
	if ( isEmpty(*pStack) )
	{
		perror( "ERROR del: Stack underflow!" );
		return;
	}
	Stack* temp = *pStack;
	*pStack = (*pStack)->next;
	free(temp);

}
void emptyStack( Stack** pStack )
{
	while ( !isEmpty(*pStack) )
		del(pStack);
}
char top( Stack* pStack )
{
	if ( isEmpty(pStack) )
	{
		return 0;
	}
	return pStack->value;
}
char pop( Stack** pStack )
{

	if ( !isEmpty(*pStack) )
	{
		char c = top(*pStack);
		del(pStack);
		return c;
	}
	perror( "ERROR pop: Stack underflow" );
	return 0;
}

