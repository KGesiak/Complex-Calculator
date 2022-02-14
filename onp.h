#ifndef onp_H
#define onp_H
double getNum();
void skipSpaces();
char getOper();
char isOper( char c );
int prior( char cOper );
int isDigit( char c );
double Eval( char cOper, double arg1, double arg2 );
double ONP();
#endif