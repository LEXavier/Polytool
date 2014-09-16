#include <stdio.h>
#include <math.h>

float peval(Polynome p , float x){

/*
	Descrição: retorna o valor de p(x)
	Entrada: O polinômio p, e o valor de x;
	Saída: p(x), que também será impresso na saída padrão;
	Autor: Luiz Eduardo Xavier
	Data: 15/09/2014
*/

	//Dicionário de dados
	float resp
	resp = (p.a9)*pow(x,9) + (p.a8)*pow(x,8) + (p.a7)*pow(x,7) + (p.a6)*pow(x,6) + (p.a5)*pow(x,5) + (p.a4)*pow(x,4) + (p.a3)*pow(x,3);
	resp += (p.a2)*pow(x,2) + (p.a1)*x + (p.a0); 
	return resp;
}

void printP(Polynome p){
	if (p.a9 != 0) printf("%.2fx^9 ",p.a9);
	if (p.a8 < 0) printf("%.2fx^8 ",p.a8)
	else printf("+%.2fx^8 ",p.a8);
	if (p.a7 < 0) printf("%.2fx^7 ",p.a7)
	else printf("+%.2fx^7 ",p.a7);
	if (p.a6 < 0) printf("%.2fx^6 ",p.a6)
	else printf("+%.2fx^6 ",p.a6);
	if (p.a5 < 0) printf("%.2fx^5 ",p.a5)
	else printf("+%.2fx^5 ",p.a5);
	if (p.a4 < 0) printf("%.2fx^4 ",p.a4)
	else printf("+%.2fx^4 ",p.a4);
	if (p.a3 < 0) printf("%.2fx^3 ",p.a3)
	else printf("+%.2fx^3 ",p.a3);
	if (p.a2 < 0) printf("%.2fx^2 ",p.a2)
	else printf("+%.2fx^2 ",p.a2);
	if (p.a1 < 0) printf("%.2fx ",p.a1)
	else printf("+%.2fx ",p.a1);
	if (p.a0 < 0) printf("%.2f\n",p.a0)
	else printf("+%.2f\n",p.a0);
}

