//
// Created by ASUS on 3/12/2019.
//

#ifndef ARBOLBPROYECTO_ARBOLB_H
#define ARBOLBPROYECTO_ARBOLB_H


#include "List.h"
#include<stdio.h>
#include<conio.h>
#include <iostream>
#define  MAX 3
#define MIN 2

using namespace std;


class BTreeNode {

	int t;     // Grado mínimo (define el rango para el número de teclas)
	BTreeNode **C; // Una matriz de punteros secundarios
	node ** keys;
	//int * keys2;// Una matriz de claves
	bool leaf; // Es cierto cuando el nodo es hoja. De lo contrario falso
public:
	int contador = 0;
	List * listados = nullptr ;
	int n;     // Número actual de llaves
    BTreeNode(int _t, bool _leaf, List *);   // Constructor
    // Una función de utilidad para insertar una nueva clave en el subárbol arraigado con
    // este nodo. El supuesto es que el nodo no debe estar lleno cuando esto
    // la función se llama
    void insertNonFull(int k, int mont, int dia,int codigo);
    // Una función de utilidad para dividir el hijo y de este nodo. i es el índice de y en
    // matriz hijo C []. El niño y debe estar lleno cuando se llama esta función
    void splitChild(int i, BTreeNode *y);
    // Una función para atravesar todos los nodos en un subárbol arraigado con este nodo
    void traverse();
    // Una función para buscar una clave en un subárbol arraigado con este nodo.
    BTreeNode *search(int k);   // returns NULL if k is not present.
	

// Haz que BTree sea amigo de esto para que podamos acceder a los miembros privados de este
// clase en funciones BTree
    friend class BTree;
};

// A BTree
class BTree
{
    BTreeNode *root; // Puntero al nodo raíz
	
    int t;  // grado mínimo
public:
    // Constructor (Inicializa el árbol como vacío)
    BTree(int _t)
    {  root = nullptr;  t = _t; }

    // función para atravesar el árbol
    void traverse()
    {  if (root != nullptr) root->traverse(); }

    // función para buscar una clave en este árbol
    BTreeNode* search(int k)
    {  return (root == nullptr)? NULL : root->search(k); }

    // La función principal que inserta una nueva clave en este B-Tree
    void insert(int k,int mes,int dia, int codigo);
	
	
};

#endif //ARBOLBPROYECTO_ARBOLB_H