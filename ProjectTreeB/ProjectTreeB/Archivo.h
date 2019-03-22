#ifndef ARCHIVO_H
#define ARCHIVO_H

#include "arbolB.h"

struct invoice {

	int code;
	char name[25];
	char invoice_code[12];
	char date[12];
	short int month;
	short int day;
	short int year;
	char payment_type[12];
	double total;
	char business_type[20];
	char business_name[60];
};

BTree * Registro(int, BTree*, int) ;
void imprimirposicion(int pos);

int getbytes(int code);


#endif // !ARBOL_H


