#include "List.h"
#include "Archivo.h"


using namespace std;

node *p = nullptr, *head = nullptr, *q = nullptr, *np = nullptr;
int c = 0;

List::List() {}

node *List::create(int x, int y, int z, int cod)
{
	np = new node;
	np->year = x;
	np->mes = y;
	np->dia = z;
	np->posarchivo = getbytes(cod);
	np->next = nullptr;
	np->otralista = nullptr;

	if (c == 0)
	{
		head = np;
		p = head;
		p->next = head;
		c++;
	}
	else if (c == 1)
	{
		p = head;
		q = p;
		if (np->dia < p->dia)
		{
			np->next = p;
			head = np;
			p->next = np;
		}
		else if (np->dia > p->dia)
		{
			p->next = np;
			np->next = head;
		}
		c++;
	}
	else
	{
		p = head;
		q = p;
		if (np->dia < p->dia)
		{
			np->next = p;
			head = np;
			do
			{
				p = p->next;
			} while (p->next != q);
			p->next = head;
		}
		else if (np->dia > p->dia)
		{
			while (p->next != head && q->dia < np->dia)
			{
				q = p;
				p = p->next;
				if (p->next == head && (p->dia < np->dia))
				{
					p->next = np;
					np->next = head;
				}
				else if (np->dia < p->dia)
				{
					q->next = np;
					np->next = p;
					break;
				}
			}
		}
	}
	return np;
}

void List::traverse(int i)
{
	node *t = head;
	int c = 0;
	while (c <= i - 1)
	{
		cout << t->dia << "\t";
		t = t->next;
		c++;

		imprimirposicion(t->posarchivo);
	}

}