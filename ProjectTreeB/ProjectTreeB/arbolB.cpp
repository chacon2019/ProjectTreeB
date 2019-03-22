#include <cstdlib>
#include "arbolB.h"
#include "List.h"

using namespace std;

// Constructor para la clase BTreeNode
BTreeNode::BTreeNode(int t1, bool leaf1, List *list) {
	// Copiar el grado mínimo dado y la propiedad de la hoja.
	t = t1;
	leaf = leaf1;
    list = new List();

	// Asignar memoria para el número máximo de claves posibles
	// y punteros de niño
	keys = new node * [2 * t - 1];
	/*keys2 = new int[2 * t - 1];*/
	C = new BTreeNode *[2 * t];
	


    // Inicializar el número de claves como 0
    n = 0;

	listados = list;
}

// Función para atravesar todos los nodos en un subárbol arraigado con este nodo
void BTreeNode::traverse() {
    // Hay n teclas y n 1 hijos, atraviesa n teclas
    // y primeros n hijos
    int i = 0;


    for (i = 0; i < n; i++) {
        // Si esto no es hoja, antes de imprimir la clave [i],
        // atravesar el subárbol enraizado con el hijo C [i].
        if (leaf == false)
            C[i]->traverse();

		cout << "year :  " << keys[i]->year << "   MES : "<< keys[i]->mes << endl;
		cout << "LISTA 1 :" << keys[i] << endl;
		listados->traverse(contador);

		
		
    }

    // Imprimir el subárbol enraizado con el último hijo
    if (leaf == false)
        C[i]->traverse();
}

// Función para buscar la clave k en el subárbol arraigado con este nodo
BTreeNode *BTreeNode::search(int k) {
    // Encuentra la primera clave mayor o igual a k
    int i = 0;
    while (i < n && k > keys[i]->year && k > keys[i]->mes)
        i++;

    // Si la clave encontrada es igual a k, devuelve este nodo
    if ((keys[i]->year == k && keys[i]) && (keys[i]->mes == k && keys[i]))
        return this;

    // Si no se encuentra la clave aquí y este es un nodo hoja
    if (leaf == true)
        return NULL;

    // Ir al hijo apropiado
    return C[i]->search(k);
}

// La función principal que inserta una nueva clave en este B-Tree
void BTree::insert(int k, int mont, int dia, int codigo) {

    List *list = nullptr;
    // Si el árbol está vacío
    if (root == NULL) {
        // Asignar memoria para root
		list = new List();
        root = new BTreeNode(t, true, list);
		//root->keys2[0] = k;  // Insertar LLAVE
		root->keys[0] = new node() ;
		root->keys[0]->year = k;
		root->keys[0]->mes = mont;
		root->keys[0]->dia = dia;
		root->keys[0]->codigo = codigo;

        root->n = 1;  // Actualizar número de claves en root

		
    }

	
	else if (root->keys[0]->year == k && root->keys[0]->mes == mont)
	{
			list->create(k, mont, dia, codigo);

			root->contador++;
	}

		
	
	
	else { // Si el árbol no está vacío
        // Si la raíz está llena, entonces el árbol crece en altura
        if (root->n == 2 * t - 1) {
            // Asignar memoria para la nueva raíz
			root->listados = new List();
            BTreeNode *s = new BTreeNode(t, false, list);

            // Hacer la raíz vieja como hijo de la nueva raíz
            s->C[0] = root;

            // Dividir la raíz antigua y mover 1 tecla a la nueva raíz
            s->splitChild(0, root);

            // La nueva raíz tiene dos hijos ahora. Decidir cuál de los
            // dos hijos van a tener nueva llave
            int i = 0;
            if (s->keys[0]->year < k &&s->keys[0]->mes < mont)
                i++;
            s->C[i]->insertNonFull(k,mont,dia,codigo);

            // Cambiar la raíz
            root = s;
        } else  // Si la raíz no está llena, llame a insertNonFull para la raíz
            root->insertNonFull(k, mont,dia,codigo);
    }


	root->listados = list;
}

// Una función de utilidad para insertar una nueva clave en este nodo
// El supuesto es que el nodo no debe estar lleno cuando esto
// la función se llama
void BTreeNode::insertNonFull(int k, int mont, int dia, int codigo) {
    // Inicializar índice como índice del elemento más a la derecha
	BTreeNode * root =NULL;
    int i = n-1;

    // Si esto es un nodo hoja
	List * list = new List();
	if (keys[i]->year == k && keys[i]->mes == mont)
	{
		 list->create(k, mont, dia, codigo);
		 root->contador++;

	}
	else if (leaf == true) {
        // El siguiente bucle hace dos cosas
        // a) Encuentra la ubicación de la nueva clave a insertar
        // b) Mueve todas las llaves mayores a un lugar adelante    
		keys[i + 1] = new node();
		while (i >= 0 && keys[i]->year > k && keys[i]->mes > mont) { // aqui se va evaluar si dato se repite
			keys[i + 1] = keys[i];
			i--;

		}

	

		keys[i + 1]->year = k;
		keys[i + 1]->mes = mont;
		keys[i + 1]->dia = dia;
		keys[i + 1]->codigo = codigo;


		n = n + 1;
	
    } else { // Si este nodo no es hoja
        // Encuentra al niño que va a tener la nueva llave.
  /*      while (i >= 0 && keys2[i] > k)
            i--;*/
		while (i >= 0 && keys[i]->year > k && keys[i]->mes > mont)
			 i--;

        // Ver si el niño encontrado está lleno
        if (C[i+1]->n == 2*t-1) {
            // Si el hijo está lleno, entonces divídelo
            splitChild(i+1, C[i+1]);

             // Después de la división, la tecla central de C [i] sube y
             // C [i] se divide en dos. Ver cuál de los dos
             // va a tener la nueva llave
          /*  if (keys2[i + 1] < k)
                i++;*/
			if (keys[i + 1]->year < k && keys[i + 1]->mes < mont)
				i++;


        }
        C[i+1]->insertNonFull(k,mont,dia,codigo);
    }

	listados = list;
}


void BTreeNode::splitChild(int i, BTreeNode *y) {
	// Crear un nuevo nodo que va a almacenar (t-1) claves
	// de y

	BTreeNode * root = NULL;
	listados = new List();
	BTreeNode *z = new BTreeNode(y->t, y->leaf, listados);
	z->n = t - 1;

	// Copia las últimas (t-1) teclas de y a z
	for (int j = 0; j < t - 1; j++) {
		z->keys[j] = y->keys[j + t];
	}
	// Copia los últimos t hijos de y a z
	if (y->leaf == false) {
		for (int j = 0; j < t; j++)
			z->C[j] = y->C[j + t];
	}

	// Reducir el número de claves en y
	y->n = t - 1;

	// Dado que este nodo va a tener un nuevo hijo,
	// crear espacio de nuevo niño
	for (int j = n; j >= i + 1; j--)
		C[j + 1] = C[j];

	// Enlace el nuevo hijo a este nodo
	C[i + 1] = z;

	// Una tecla de y se moverá a este nodo. Encontrar ubicación de
	// nueva clave y mover todas las claves mayores un espacio adelante
	for (int j = n - 1; j >= i; j--) {
		keys[j + 1] = keys[j];
	}
	// Copia la clave central de y a este nodo
	keys[i] = y->keys[t - 1];

	// Incremento del conteo de claves en este nodo.
	n = n + 1;


	
}