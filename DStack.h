#ifndef DStack_H
#define DStack_H

typedef struct DStack
{

	double value;
	DStack* next;

}DStack;

DStack* InitDStack();
void dpush( double f, DStack** pdStack );
void demptyStack( DStack** pdStack );
void ddel( DStack** pdStack );
double dtop( DStack* pdStack );
double dpop( DStack** pdStack );
int disEmpty( DStack* pdStack );

#endif