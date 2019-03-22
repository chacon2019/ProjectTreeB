#include <iostream>
#include "arbolB.h"
#include "Archivo.h"

#include "List.h"

using namespace std;

int main(){



    int val, opt, max;
	int cant;
    cout<<"LLaves por paginas: ";
    cin>>max;

	
	BTree * t = new BTree(max);
    List *l = new List();
	
	cout << "Cuantos registros quiere: ";
	cin >>	cant;
	t= Registro(cant,t,max);
	
	/*for (int i = 1; i < 4; i++)
	{

		t->insert(2006, 4, i+2, i + 1);

		cout << " dia" << i+2 << endl;
	}
*/
	

    while (true) {
        cout<<"[1] Insertar\n[2] Buscar\n";
        cout<<"[3] Impresion (min a max)\n";
        cout<<"[4] Salir\n Opcion: ";
        cin >> opt;
        cout << endl;
        switch (opt) {
            case 1:
              /*  cout<<"Ingrese nodo:";
                cin >> val;
				t->insert(val,);*/

                break;

            case 2:
            {
                cout<<"Elemento a buscar:";
                cin >> val;
                (t->search(val) != NULL)? cout << "\nExiste" : cout << "\nNo Existe";
                cout << endl;
                break;
            }

            case 3:
            {
                int i = 0;
				t->traverse();
				l->traverse(i);
                cout << endl;
                break;
            }

            default:
            {
                exit(0);
            }
        }
        cout << endl;
    }
}