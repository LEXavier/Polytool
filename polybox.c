#include <stdio.h>
#include <math.h>

float peval(Polynome p , float x){

/*
	Descrição: retorna o valor de p(x)
	Entrada: O polinômio p, e o valor de x;
	Saída: p(x);
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
/*
	Descrição: imprime p(x) na saída padrão;
	Entrada: O polinômio p;
	Saída: a impressão de p(x);
	Autor: Luiz Eduardo Xavier
	Data: 15/09/2014
*/
	printf("p(x) = ");
	if (p.a9 != 0) printf("%.2fx^9 ",p.a9);
	if (p.a8 < 0) printf("%.2fx^8 ",p.a8)
	else if (p.a8!=0) printf("+%.2fx^8 ",p.a8);
	if (p.a7 < 0) printf("%.2fx^7 ",p.a7)
	else if (p.a7!=0) printf("+%.2fx^7 ",p.a7);
	if (p.a6 < 0) printf("%.2fx^6 ",p.a6)
	else if (p.a6!=0) printf("+%.2fx^6 ",p.a6);
	if (p.a5 < 0) printf("%.2fx^5 ",p.a5)
	else if (p.a5!=0) printf("+%.2fx^5 ",p.a5);
	if (p.a4 < 0) printf("%.2fx^4 ",p.a4)
	else if (p.a4!=0) printf("+%.2fx^4 ",p.a4);
	if (p.a3 < 0) printf("%.2fx^3 ",p.a3)
	else if (p.a3!=0) printf("+%.2fx^3 ",p.a3);
	if (p.a2 < 0) printf("%.2fx^2 ",p.a2)
	else if (p.a2!=0) printf("+%.2fx^2 ",p.a2);
	if (p.a1 < 0) printf("%.2fx ",p.a1)
	else if (p.a1!=0) printf("+%.2fx ",p.a1);
	if (p.a0 < 0) printf("%.2f\n",p.a0)
	else if (p.a0!=0) printf("+%.2f\n",p.a0);
}

float calculaDelta(float a , float b , float c){
	return (b*b -4*a*c);
}

void roots(Polynome p){
/*
	Descrição: Calcula as raízes de um polinômio;
	Entrada: O polinômio p(x);
	Saída: A impressão da(s) raíze(s) na saída padrão;
	Autor: Luiz Eduardo Xavier;
	Data: 20/09/2014;
*/
	float root,root1;
	float delta;
	if (p.grau == 1) {
		if (p.a1 != 0){
			root = -(p.a0/p.a1);
			printf(":/> %.2f\n",root);
		}
		else puts("Raiz indeterminada");
		return;
	}
	if (p.grau == 2)
		delta = calculaDelta(p.a2,p.a1,p.a0);
		if (delta >= 0){
			root = (sqrt(delta)-p.a1)/(2*p.a2);
			root1 = -(sqrt(delta)+p.a1)/(2*p.a2);
			printf(":/> {%.2f,%.2f}\n",root,root1);
		}
		else puts("Não possui raízes reais");
		return;
	} else 
		puts("O grau do polinômio deve ser inferior a (1 ou 2)");
}

void optionMenu(Polynome p){
/*
	Descrição: Menu de opções para trabalhar com um polinômio;
	Entrada: O polinômio p que será trabalhado;
	Saída: ---
	Autor: Luiz Eduardo Xavier;
	Data: 20/09/2014;
*/
	int resp = 0;
	while (resp != 0){
		printf("O que deseja fazer agora?\n");
		printf("(1) Mostra polinômio;\n");
		printf("(2) Modificar polinômio;\n");
		printf("(3) Calcular p(x);\n");
		printf("(4) Calcular raízes (o grau deve ser menor ou igual a 2);\n");
		printf("(5) Derivar polinômio;\n");
		printf("(6) Somar com outro polinômio;\n");
		printf("(7) Sair\n"); 
		printf(":/>");
		scanf("%d",&resp);
		switch (resp) {
			case 1:
				printP(p);
			break;
			case 2:
				modPoly(p);
			break;
			case 3:
				peval(p);
			break;
			case 4:
				roots(p);
			break;
			case 5:
				diff(p);
			break;
			case 6:
				sumP(p);
			break;
			default:
				if (resp != 7) printf("Opção inválida!");
			break;
		}
	}
}

Polynome newPoly(){
/*
	Descrição: Realiza a leitura de um polinômio;
	Entrada: void;
	Saída: O polinômio desejado pelo usuário;
	Autor: Luiz Eduardo Xavier;
	Data: 21/09/2014;
*/
	float coef;
	int grau = 0;
	Polynome p;
	printf("Leitura do Polinômio\nCaso queira parar digite um grau negativo\nCaso escreva dois coeficientes o último sobrecreverá o anterior\n");
	while (grau >= 0){
		printf("Digite um coeficiente do polinômio\n:~$ ");
		scanf("%f",&coef);
		printf("Digite seu grau [max 9]\n:~$ ");
		scanf("%d",&grau);
		switch (grau) {
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
		}
	}				
	return p;
}
