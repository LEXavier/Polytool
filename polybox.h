/*
	Descrição: Conjunto de ferramentas para trabalhos com polinômios de graus menores ou inferiores a 9;
*/

typedef struct {
	char sinal;
	float val;
	int grau;
} Coeficiente;

typedef struct {
	Coeficiente a9,a8,a7,a6,a5,a4,a3,a2,a1,a0; //coeficientes do polinômio
	int grau;
} Polynome;

float peval(Polynome p, float x);

float roots(Polynome p);

Polynome diffPoly(Polynome p);

Polynome sumP(Polynome p);

Polynome newPoly();

Polynome getNewPoly();

Polynome modPoly(Polynome p);

void printP(Polynome p);
