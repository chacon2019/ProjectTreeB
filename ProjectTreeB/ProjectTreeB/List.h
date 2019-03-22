#ifndef PROYECTO2_LIST_H
#define PROYECTO2_LIST_H

#include<stdio.h>
#include<iostream>

using namespace std;

struct node
{
	int codigo;
	int year;
	int mes;
	int dia;
	int posarchivo;
	node *next;
	node *otralista;

};

class List
{
public:
	List();
	node *create(int x, int y, int z, int cod);
	void traverse(int i);

};
#endif //PROYECTO2_LIST_H