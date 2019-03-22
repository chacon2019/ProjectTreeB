
#include "Archivo.h"

//#include  "Node.h"
#include <fstream>
#include "arbolB.h"

#include  <iostream>

using namespace std;



BTree * Registro(int cantidad, BTree * t , int llaves) {

	t = new BTree(llaves);

	ifstream archivoPos("data.dat", ios::in | ios::binary);

	if (!archivoPos)
	{
		cout << " Error al intentar abrir archivo data.dat";
		return NULL;
	}

	archivoPos.seekg(0, ios::beg);
	invoice nuevo;

	archivoPos.read(reinterpret_cast <char *>(&nuevo), sizeof(invoice)); //la cantidad que voy a leer 

	for (int i = 0; i < cantidad; i++)
	{
		
		if (nuevo.year == 2004 && nuevo.month == 11)
		{
			t->insert(nuevo.year, nuevo.month, nuevo.day, nuevo.code);

			cout << "Codifo  : " << nuevo.code << endl;
			cout << "Nombre  : " << nuevo.name << endl;
			cout << "Invoice Codigo  : " << nuevo.invoice_code << endl;
			cout << "Fecha : " << nuevo.date << endl;
			cout << "Mes  : " << nuevo.month << endl;
			cout << "Dia  : " << nuevo.day << endl;
			cout << "Year : " << nuevo.year << endl;
			cout << "payment_type  : " << nuevo.payment_type << endl;
			cout << " total : " << nuevo.total << endl;
			cout << " business_type : " << nuevo.business_type << endl;
			cout << " business_name : " << nuevo.business_name << endl;

			cout << "----------------------------------------------------------------------------" << endl;
		}
			
		
		





		archivoPos.read(reinterpret_cast <char *>(&nuevo), sizeof(invoice)); //la cantidad que voy a leer 

		
	}

	
	

	archivoPos.close();
	
	return t;



}

void imprimirposicion(int pos) {
	


		fstream archivoModef("data.dat", ios::in | ios::binary);

		if (!archivoModef)
		{
			cout << " Error al intentar abrir archivo data.dat";
			return;
		}


		invoice nuevo;

		archivoModef.seekp(pos * sizeof(invoice), ios::beg);
		archivoModef.read(reinterpret_cast < char *>(&nuevo), sizeof(invoice));

		



		cout << "Codigo  : " << nuevo.code << endl;
		cout << "Nombre  : " << nuevo.name << endl;
		cout << "Invoice Codigo  : " << nuevo.invoice_code << endl;
		cout << "Fecha : " << nuevo.date << endl;
		cout << "Mes  : " << nuevo.month << endl;
		cout << "Dia  : " << nuevo.day << endl;
		cout << "Year : " << nuevo.year << endl;
		cout << "payment_type  : " << nuevo.payment_type << endl;
		cout << " total : " << nuevo.total << endl;
		cout << " business_type : " << nuevo.business_type << endl;
		cout << " business_name : " << nuevo.business_name << endl;



		


		archivoModef.read(reinterpret_cast < char *>(&nuevo), sizeof(invoice));


		cout << "Registro! \n\n";



		archivoModef.close();







	}

int getbytes(int codigo) {

	ifstream archivoPos("data.dat", ios::in | ios::binary);

	if (!archivoPos)
	{
		cout << " Error al intentar abrir archivo data.dat";
		return -1;
	}

	archivoPos.seekg(0, ios::beg);
	invoice nuevo;

	archivoPos.read(reinterpret_cast <char *>(&nuevo), sizeof(invoice)); //la cantidad que voy a leer 
	int pos = 0;

	while (!archivoPos.eof())
	{

		if (nuevo.code == codigo)
		{


			
			archivoPos.read(reinterpret_cast <char *>(&nuevo), sizeof(invoice));
			

			archivoPos.close();

			return pos;
		}

		pos++;
		archivoPos.read(reinterpret_cast <char *>(&nuevo), sizeof(invoice)); //la cantidad que voy a leer 

	}

	archivoPos.close();
	return -1;



}