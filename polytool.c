#include "polybox.h"
#include <stdio.h>

int main(void){
	Polynome polinomio;
	polinomio = newPoly(0,0,0,0,0,0,0,0,0,0);
	optionMenu(polinomio);
	printf(".");
	return 0;
}
