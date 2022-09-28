#ifndef NODO_H
#define NODO_H

#include <iostream>

using namespace std;

template<class T>class Nodo{
private:
  T dato;
  Nodo<T> *siguiente;

public:
  Nodo(T dato=0){
    this->dato = dato;
  };
  ~Nodo(){
    delete siguiente;
  }
  void setDato(T dato){
    this->dato = dato;
  };
  T getDato(){
    return dato;
  };
  void setSiguiente(Nodo<T> *siguiente){
    this->siguiente = siguiente;
  };
  Nodo<T>* getSiguiente(){
    return siguiente;
  };
};

#endif
