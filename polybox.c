#include <stdio.h>
#include <math.h>

typedef struct {
/*
	Descrição: Novo tipo nomeado "Polynome" que será trabalhado com a presente biblioteca;
	Data: 15/09/2014
*/
	float a9,a8,a7,a6,a5,a4,a3,a2,a1,a0; //coeficientes do polinômio
	int grau;
} Polynome;

Polynome somaPoly(Polynome p, Polynome p2){
/*
	Descrição: retonar a soma dos polinômios;
	Entrada: O polinômio p e p2 ;
	Saída: soma dos polinômio;
	Data: 24/09/2014
*/
		Polynome pCalc;
		pCalc.a0 = p.a0 + p2.a0;
		pCalc.a1 = p.a1 + p2.a1;
		pCalc.a2 = p.a2 + p2.a2;
		pCalc.a3 = p.a3 + p2.a3;
		pCalc.a4 = p.a4 + p2.a4;
		pCalc.a5 = p.a5 + p2.a5;
		pCalc.a6 = p.a6 + p2.a6;
		pCalc.a7 = p.a7 + p2.a7;
		pCalc.a8 = p.a8 + p2.a8;
		pCalc.a9 = p.a9 + p2.a9;
		return pCalc;
}
float peval(Polynome p , float x){
/*
	Descrição: retorna o valor de p(x)
	Entrada: O polinômio p, e o valor de x;
	Saída: p(x);
	Data: 15/09/2014
*/

	//Dicionário de dados
	float resp;
	resp = (p.a9)*pow(x,9) + (p.a8)*pow(x,8) + (p.a7)*pow(x,7) + (p.a6)*pow(x,6) + (p.a5)*pow(x,5) + (p.a4)*pow(x,4) + (p.a3)*pow(x,3);
	resp += (p.a2)*pow(x,2) + (p.a1)*x + (p.a0); 
	printf("p(%.2f)= %f\n",x,resp);
	return resp;
}

void printP(Polynome p){
/*
	Descrição: imprime p(x) na saída padrão;
	Entrada: O polinômio p;
	Saída: a impressão de p(x);
	Data: 15/09/2014
*/
	printf("p(x) = ");
	if (p.a9 + 1 != 1) {
		printf("%.2fx^9 ",p.a9);
	} 
	if (p.a8 < 0) { 
		printf("%.2fx^8 ",p.a8);
	}
	else if (p.a8 + 1 != 1) {
	printf("+ %.2fx^8 ",p.a8);
	}
	if (p.a7 < 0) {
		printf("%.2fx^7 ",p.a7);
	}
	else if (p.a7!=0.0) {
		printf("+ %.2fx^7 ",p.a7);
	}
	if (p.a6 < 0) {
		printf("%.2fx^6 ",p.a6);
	}
	else if (p.a6!=0.0) {
		printf("+ %.2fx^6 ",p.a6);
	}
	if (p.a5 < 0) {
		printf("%.2fx^5 ",p.a5);
	}
	else if (p.a5!=0.0) {
		printf("+ %.2fx^5 ",p.a5);
	}
	if (p.a4 < 0) {
		printf("%.2fx^4 ",p.a4);
	}
	else if (p.a4!=0.0) {
		printf("+ %.2fx^4 ",p.a4);
	}
	if (p.a3 < 0) {
		printf("%.2fx^3 ",p.a3);
	}
	else if (p.a3!=0.0) {
		printf("+ %.2fx^3 ",p.a3);
	}
	if (p.a2 < 0) {
		printf("%.2fx^2 ",p.a2);
	}
	else if (p.a2!=0.0) {
		printf("+ %.2fx^2 ",p.a2);
	}
	if (p.a1 < 0) {
		printf("%.2fx ",p.a1);
	}
	else if (p.a1!=0.0) {
		printf("+ %.2fx ",p.a1);
	}
	if (p.a0 < 0) {
		printf("%.2f\n",p.a0);
	}
	else if (p.a0!=0.0) {
		printf("+ %.2f\n",p.a0);
	}
}

float calculaDelta(float a , float b , float c){
/*
	Descrição: Calcula o delta de uma equação do segundo grau;
	Entrada: Os coeficientes a, b e c do polinômio;
	Saída: o delta;
	Data: 15/09/2014
*/
	return (b*b -4*a*c);
}

void roots(Polynome p){
/*
	Descrição: Calcula as raízes de um polinômio;
	Entrada: O polinômio p(x);
	Saída: A impressão da(s) raíze(s) na saída padrão;
	;
	Data: 20/09/2014;
*/
	float root,root1;
	float delta;
	if (p.grau == 1) {
		if (p.a1 != 0){
			root = -(p.a0/p.a1);
			printf(":/> %.2f\n",root);
		}
		else puts("Raiz indeterminada\n");
		return;
	}
	if (p.grau == 2) {
		delta = calculaDelta(p.a2,p.a1,p.a0);
		if (delta >= 0){
			root = (sqrt(delta)-p.a1)/(2*p.a2);
			root1 = -(sqrt(delta)+p.a1)/(2*p.a2);
			printf(":/> {%.2f,%.2f}\n",root,root1);
		} else puts("Não possui raízes reais");
		return;
	} else 	puts("O grau do polinômio deve ser igual a 1 ou 2\n");
}

Polynome newPoly(float a9,float a8,float a7,float a6,float a5,float a4,float a3,float a2,float a1,float a0){
/*
	Descrição: Instancia novo polinômio;
	Entrada: Os 9 coeficientes do polinomio;
	Saída: O polinômio desejado pelo usuário;
	Data: 23/09/2014;
*/
	Polynome r;
	r.a0 = a0;
	r.a1 = a1;
	r.a2 = a2;
	r.a3 = a3;
	r.a4 = a4;
	r.a5 = a5;
	r.a6 = a6;
	r.a7 = a7;
	r.a8 = a8;
	r.a9 = a9;
	return r;
}

Polynome getNewPoly(){
/*
	Descrição: Realiza a leitura de um polinômio;
	Entrada: void;
	Saída: O polinômio desejado pelo usuário;
	Data: 21/09/2014;
*/
	float coef;
	int grau = 0;
	float 	a0 = 0,
		a1 = 0,
		a2 = 0,
		a3 = 0,
		a4 = 0,
		a5 = 0,
		a6 = 0,
		a7 = 0,
		a8 = 0,
		a9 = 0;
	Polynome p;
	printf("Leitura do Polinômio\nCaso queira parar digite um grau negativo\nCaso escreva dois coeficientes o último sobrecreverá o anterior\n");
	while (grau >= 0){
		printf("Digite um coeficiente do polinômio\n:~$ ");
		scanf("%f",&coef);
		printf("Digite seu grau [max 9]\n:~$ ");
		scanf("%d",&grau);
		switch (grau) {
			case 0:
				a0 = coef;
			break;
			case 1:
				a1 = coef;
			break;
			case 2:
				a2 = coef;
			break;
			case 3:
				a3 = coef;
			break;
			case 4:
				a4 = coef;
			break;
			case 5:
				a5 = coef;
			break;
			case 6:
				a6 = coef;
			break;
			case 7:
				a7 = coef;
			break;
			case 8:
				a8 = coef;
			break;
			case 9:
				a9 = coef;
			break;
		}
	}
	p = newPoly(a9,a8,a7,a6,a5,a4,a3,a2,a1,a0);
	return p;
}
Polynome diffPoly(Polynome p){
	/*
	Descrição: Deriva um polinômio e printa na tela;
	Entrada: Um polinômio;
	Saída: A derivada do polinômio, e sua impressão em tela;
	Data: 23/09/2014;
*/
	Polynome diff;
	diff.a9 = 0;
	diff.a8 = 9*(p.a9);
	diff.a7 = 8*(p.a8);
	diff.a6 = 7*(p.a7);
	diff.a5 = 6*(p.a6);
	diff.a4 = 5*(p.a7);
	diff.a3 = 4*(p.a4);
	diff.a2 = 3*(p.a3);
	diff.a1 = 2*(p.a2);
	diff.a0 = p.a1;
	printP(diff);
	return diff;
}
Polynome sumP(Polynome p){
	printf("Entre com o polinômio a ser somado com o original\n");
	Polynome q = getNewPoly();
	q = somaPoly(p,q);
	printP(q);
	return q;
}
Polynome subsPoly(Polynome p){
	char resp;
	puts("Entre com o polinômio que SUBSTITUIRÁ o antigo polinômio");
	printf("Deseja continuar? (y/n)\n:/>");
	scanf("%c",&resp);
	switch (resp){
		case 'y':
			p = getNewPoly();
		break;
		default:
			puts("Opção inválida!");
		case 'n':
			puts("Modificação abortada!");
		break;
	}
	return p;
}
Polynome modPoly(Polynome p){
	int grau;
	float coef;
	while (grau >= 0){
		printf("Digite o grau do coeficiente  ser mudado\n:/>");
		scanf("%d",&grau);
		if (grau >= 0) {
			printf("Digite o novo coeficiente\n:/>");
			scanf("%f",&coef);
			switch (grau){
				case 0:
					p.a0 = coef;
				break;
				case 1:
					p.a1 = coef;
				break;
				case 2:
					p.a2 = coef;
				break;
				case 3:
					p.a3 = coef;
				break;
				case 4:
					p.a4 = coef;
				break;
				case 5:
					p.a5 = coef;
				break;
				case 6:
					p.a6 = coef;
				break;
				case 7:
					p.a7 = coef;
				break;
				case 8:
					p.a8 = coef;
				break;
				case 9:
					p.a9 = coef;
				break;
				default:
					printf("O grau deve ser menor ou igual a 9!\n");
				break;
			}
		}
	}
	return p;
} 

void optionMenu(Polynome p){
/*
	Descrição: Menu de opções para trabalhar com um polinômio;
	Entrada: O polinômio p que será trabalhado;
	Saída: ---
	Data: 20/09/2014;
*/
	int resp = 10;
	float aux;
	while (resp != 0){
		printf("\nO que deseja fazer agora?\n");
		printf("(1) Mostrar polinômio;\n");
		printf("(2) Modificar polinômio;\n");
		printf("(3) Trocar polinômio\n");
		printf("(4) Calcular p(x);\n");
		printf("(5) Calcular raízes (o grau deve ser menor ou igual a 2);\n");
		printf("(6) Derivar polinômio;\n");
		printf("(7) Somar com outro polinômio;\n");
		printf("(0) Sair\n"); 
		printf(":/>");
		scanf("%d",&resp);
		switch (resp) {
			case 1:
				printP(p);
			break;
			case 2:
				p = modPoly(p);
			break;
			case 3:
				p = subsPoly(p);
			break;
			case 4:
				printf("Digite o valor de x desejado\n:~$ ");
				scanf("%f",&aux);
				peval(p,aux);
			break;
			case 5:
				roots(p);
			break;
			case 6:
				diffPoly(p);
			break;
			case 7:
				sumP(p);
			break;
			default:
				if (resp != 0) printf("Opção inválida!\n");
			break;
		}
	}
}
