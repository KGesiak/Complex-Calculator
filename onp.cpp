#include <stdio.h>
#include <math.h>
#include <float.h>
#include "onp.h"
#include "DStack.h"
#include "Stack.h"
#define DOT '.'
void skipSpaces()
{
	char c;
	while ( ( c = getchar() ) == ' ' );
	ungetc( c, stdin );
}
int isDigit( char c )
{
	return (c >= '0' && c <= '9');
}
double getNum()
{
	char c;
	double res = 0;
	int sign = 0;
	skipSpaces();

	if ( ( c = getchar() ) == '-' ) sign = 1;
	else if ( c != '+' ) ungetc( c, stdin );
	while ( isDigit( c = getchar() ) )
		res = res * 10 + ( c - '0' );
	if ( c == DOT )
	{
		double coef = 0.1;
		while ( isDigit( c = getchar() ) )
		{
			res += coef * ( c - '0' );
			coef *= 0.1;
		}
	}
	ungetc( c, stdin );
	if ( sign ) res = -res;
	return res;
}
char getOper()
{
	skipSpaces();
	return getchar();
}
char isOper( char c )
{
	switch (c)
	{
	case '+':
	case '-':
	case '/':
	case '*':
	case '^': return 1;
	}
	return 0;
}
int prior( char cOper )
{
	switch ( cOper )
	{
	case '+':
	case '-':return 1;
	case '/':
	case '*':return 2;
	case '^':return 3;
	}
	return 0;
}
double Eval( char cOper, double arg1, double arg2 )
{
	switch ( cOper )
	{
	case '+':return arg1 + arg2;
	case '-':return arg1 - arg2;
	case '*':return arg1 * arg2;
	case '/':if ( fabs( arg2 ) > 1e-15 ) // Checking if the result is in the limits of type double
		return arg1 / arg2;
		perror( "ERROR arg2 = 0!" );
		return DBL_MIN;
	case '^': return pow( arg1, arg2 );
	}
	return 0;
}
double ONP()
{
	char c;
	double temp;

	Stack* pStack = InitStack();
	DStack* pdStack = InitDStack();

	dpush( getNum(), &pdStack );
	while ( isOper(c = getchar()) )
	{
		if ( top(pStack) )
		{
			while ( prior(top(pStack)) >= prior(c) )
			{
				temp = dpop(&pdStack);
				dpush( Eval( pop(&pStack), dpop(&pdStack), temp ) , &pdStack );	// Taking two elements off the stack and carring out given operation

			}
		}

		push( c, &pStack );
		dpush( getNum(), &pdStack );
	}
	while ( !isEmpty(pStack) ) // Executing operations until there are no more left in the stack
	{
		temp = dpop( &pdStack );
		dpush( Eval( pop(&pStack), dpop(&pdStack), temp ), &pdStack );
	}

	return dpop(&pdStack);
}