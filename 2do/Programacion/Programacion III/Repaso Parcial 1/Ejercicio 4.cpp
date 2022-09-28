#include <iostream>
#include "Lista.h"
using namespace std;

int menorDato(Lista<int> &L, int t) {
 if(t==0) return L.getDato(t);
 if(L.getDato(t-1)<L.getDato(t-2)){
    int x=L.getDato(t-2);
    L.reemplazar(t-2,L.getDato(t-1));
    L.reemplazar(t-1,x);
    return menorDato(L,t-1);
 }
    return menorDato(L,t-1);
    
}

int main() {
  Lista<int> L;
    L.insertarPrimero(8);
    L.insertarPrimero(4);
    L.insertarPrimero(1);
    L.insertarPrimero(5);

    cout<<menorDato(L,L.getTamanio());
    return 0;
}