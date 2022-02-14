#include <memory>
#include "DStack.h"


DStack* InitDStack()
{
	return NULL;
}
int disEmpty( DStack* pdStack )
{
	return !pdStack;
}
void dpush( double f, DStack** pdStack )
{
	DStack* tempDStack = (DStack*)malloc( sizeof(DStack) ); // Allocation memory for a new element
	if (!tempDStack)
	{
		perror( "ERROR dpush: Allocation error" );
		return;
	}
	tempDStack->value = f;
	tempDStack->next = *pdStack;	// Connecting the new element with the former one
	*pdStack = tempDStack;	// Moving the pointer to the new element
}
void ddel( DStack** pdStack )
{
	if ( disEmpty(*pdStack) )
	{
		perror("ERROR ddel: Stack underflow!");
		return;
	}
	DStack* temp = *pdStack;
	*pdStack = (*pdStack)->next;
	free(temp); // Freeing the memory previously used by the deleted element
}
void demptyStack( DStack** pdStack )
{
	while ( !disEmpty(*pdStack) )
		ddel(pdStack);
}
double dtop( DStack* pdStack )
{
	if ( disEmpty(pdStack) )
	{
		perror( "ERROR dtop: Stack underflow!" );
		return DBL_MIN;
	}
	return pdStack->value;
}
double dpop( DStack** pdStack )
{
	if ( !disEmpty(*pdStack) )
	{
		double f = dtop(*pdStack);
		ddel(pdStack);
		return f;
	}
	perror( "ERROR dpop: Stack underflow!" );
	return DBL_MIN;
}
