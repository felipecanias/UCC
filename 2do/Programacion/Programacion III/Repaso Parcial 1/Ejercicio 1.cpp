#include <iostream>
#include "Lista.h"
#include "Pila.h"
using namespace std;

void eliminar_desde_pila(Pila<unsigned int> *P, Lista<int> *L) {
  while (!P->esVacia()) {
    L->remover(P->pop());
  }
}

int main() {
  Lista<int> *L = new Lista<int>;
  Pila<unsigned int> *P = new Pila<unsigned int>;

  L->insertarPrimero(5);
  L->insertarPrimero(4);
  L->insertarPrimero(3);
  L->insertarPrimero(2);
  L->insertarPrimero(1);

  P->push(1);
  P->push(3);

  eliminar_desde_pila(P, L);

  cout << L->getDato(0) << endl;
  cout << L->getDato(1) << endl;
  cout << L->getDato(2) << endl;

  return 0;
}
