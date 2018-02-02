//TEMPERATURE CONVERTER

#include <stdio.h>
#include <stdlib.h>

double celtofah(double tin);
double celtokel(double tin);
double fahtocel(double tin);
double fahtokel(double tin);
double keltocel(double tin);
double keltofah(double tin);

int main(){
	int to, from, op;
	double tin, tfin;
	char temp[3][10] = {"Celsius", "Fahrenheit", "Kelvin"};
	system("cls");
	printf("Please inform the temperature: ");
	scanf("%lf", &tin);
	do{
		printf("Convert from:\n");
		printf("[1]. Celsius\n");
		printf("[2]. Fahrenheit \n");
		printf("[3]. Kelvin\n");
		scanf("%d", &from);
	}while(from < 0 || from > 3);
	do{
		printf("Convert to:\n");
		printf("[1]. Celsius\n");
		printf("[2]. Fahrenheit \n");
		printf("[3]. Kelvin\n");
		scanf("%d", &to);
	}while(to < 0 || to > 3);
	if(from == 1 && to == 2) tfin = celtofah(tin);
	else if(from == 1 && to == 3) tfin = celtokel(tin);
	else if(from == 2 && to == 1) tfin = fahtocel(tin);
	else if(from == 2 && to == 3) tfin = fahtokel(tin);
	else if(from == 3 && to == 1) tfin = keltocel(tin);
	else if(from == 3 && to == 2) tfin = keltofah(tin);
	else if(from == to) tfin = tin;
	printf("%.2lf ", tin);
	from == 1 ? printf("%cC", 248) : from == 2 ? printf("%cF", 248) : printf("K");
	printf(" is equal to %.2lf ", tfin);
	to == 1 ? printf("%cC.\n", 248) : to == 2 ? printf("%cF.\n", 248) : printf("K.\n");
	system("pause");
	printf("Repeat?\n");
	printf("[0]. No.\n");
	printf("[1]. Yes.\n");
	scanf("%d", &op);
	if(op == 1) main();
	return 0;
}

//Celtofah.
//Funtion converts Celsius to Fahrenheit.

double celtofah(double tin){
	double fah;
	fah = (tin*1.8) + 32;
	return fah;
}

//Celtokel.
//Funtion converts Celsius to Kelvin.

double celtokel(double tin){
	double kel;
	kel = tin + 273.15;
	return kel;
}

//Fahtocel.
//Function converts Fahrenheit to Celsius.

double fahtocel(double tin){
	double cel;
	cel = ((tin - 32)*5)/9;
	return cel;
}

//Fahtokel.
//Function converts Fahrenheit to Kelvin.

double fahtokel(double tin){
	double kel;
	kel = (((tin - 32)*5)/9) + 273.15;
	return kel;
}

//Keltocel.
//Function converts Kelvin to Celsius.

double keltocel(double tin){
	double cel;
	cel = tin - 273.15;
	return cel;
}

//Keltofah.
//Function converts Kelvin to Fahrenheit.

double keltofah(double tin){
	double fah;
	fah = (1.8*(tin - 273.15)) + 32;
	return fah;
}
