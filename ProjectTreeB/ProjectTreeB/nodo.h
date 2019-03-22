#ifndef NODO_H

#define NODO_H
#include "arbolB.h"
#include <iostream>

struct nodo {
    int dia;
    int posicionmemo;
    struct nodo *sgte;
    struct nodo *otralista;
};

/*typedef struct nodo *Tlista;

Tlista inicio, fin;

void generarLista(Tlista &inicio, Tlista &fin, int n, int posicion )
{
    Tlista q, t;


    q = new(struct nodo);
    q->dia = n;
    q->posicionmemo = posicion;

    if (inicio == NULL)
    {
        q->sgte = inicio;
        inicio = q;
        fin = q;
    }
    else
    {
        q->sgte = fin->sgte;
        fin->sgte = q;
        fin = q;
    }


    std::cout << "\n\n\tLista de numeros generados... " << std::endl;
}


void reportarLista(Tlista inicio)
{

    while (inicio != NULL)
    {
        std::cout << "  " << inicio->dia;
        inicio = inicio->sgte;
    }

}

void ordenarLista(Tlista lista) {
    Tlista actual, siguiente;
    int t;

    actual = lista;
    while (actual->sgte != NULL) {
        siguiente = actual->sgte;

        while (siguiente != NULL) {
            if (actual->dia > siguiente->dia) {
                t = siguiente->dia;
                siguiente->dia = actual->dia;
                actual->dia = t;
            }
            siguiente = siguiente->sgte;
        }
        actual = actual->sgte;
        siguiente = actual->sgte;

    }

    std::cout << "\n\n\tLista ordenada..." << std::endl;
}*/

#endif // !NODOS_H

