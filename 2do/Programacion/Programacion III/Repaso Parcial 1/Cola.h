#ifndef U04_COLAS_COLA_COLA_H_
#define U04_COLAS_COLA_COLA_H_
#include "Nodo.h"
/**
 * Clase que implementa una Cola generica, ya que puede
 * almacenar cualquier tipo de dato T
 * @tparam T cualquier tipo de dato
 */
template <class T> class Cola {
private:
  Nodo<T> *ultimo;
  Nodo<T> *primero;

public:
  Cola();

  ~Cola();

  void encolar(T dato);

  T desencolar();

  bool esVacia();

  void Ordendeprioridad(T dato, int p);

  void Moveralfinal(int pos);
};

/**
 * Constructor de la clase Cola
 * @tparam T
 */
template <class T> Cola<T>::Cola() {
  ultimo = NULL;
  primero = NULL;
}

/**
 * Destructor de la clase Cola, se encarga de liberar la memoria de todos los
 * nodos utilizados en la Cola
 * @tparam T
 */
template <class T> Cola<T>::~Cola() {}

/**
 * Inserta un dato en la Cola
 * @tparam T
 * @param dato  dato a insertar
 */
template <class T> void Cola<T>::encolar(T dato) {
  Nodo<T> *nuevo = new Nodo<T>(dato);
  nuevo->setSiguiente(NULL);

  if (esVacia()) {
    primero = nuevo;
    ultimo = nuevo;
    return;
  }

  ultimo->setSiguiente(nuevo);
  ultimo = nuevo;
}

/**
 * Obtener el dato de la Cola
 * @tparam T
 * @return dato almacenado en el nodo
 */
template <class T> T Cola<T>::desencolar() {
  Nodo<T> *auxNodo = primero;
  T x = primero->getDato();

  if (esVacia())throw 404;

  primero = primero->getSiguiente();

  if(primero==NULL) ultimo==NULL;

  auxNodo->setSiguiente(NULL);
  delete auxNodo;
  return x;
}

/**
 * Responde si la Cola se encuentra Vacía
 * @tparam T
 * @return
 */
template <class T> bool Cola<T>::esVacia() { return ultimo == NULL; }

template <class T> void Cola<T>::Ordendeprioridad(T dato, int p) {
  Nodo<T> *nuevo = new Nodo<T>(dato), *auxNodo = primero;
  nuevo->setPrioridad(p);
  nuevo->setSiguiente(NULL);

  if (esVacia()) {
    ultimo = nuevo;
    primero = nuevo;
    return;
  }

  if (p < primero->getPrioridad()) {
    nuevo->setSiguiente(primero);
    primero = nuevo;
    return;
  }

  if (ultimo == primero) {
    primero->setSiguiente(nuevo);
    ultimo = nuevo;
    return;
  }

  while (auxNodo->getSiguiente() != NULL &&
         auxNodo->getSiguiente()->getPrioridad() <= p) {
    auxNodo = auxNodo->getSiguiente();
  }

  if (auxNodo->getSiguiente() == NULL) {
    auxNodo->setSiguiente(nuevo);
    ultimo = nuevo;
    return;
  }
  nuevo->setSiguiente(auxNodo->getSiguiente());
  auxNodo->setSiguiente(nuevo);
}

template <class T> void Cola<T>::Moveralfinal(int pos){
  Nodo<T> *auxNodo1, *auxNodo2;
  auxNodo1=primero;
  int posActual=0;

  if(esVacia()) throw 404;


  while (auxNodo1 != NULL && posActual < pos-1) {
    auxNodo1 = auxNodo1->getSiguiente();
    posActual++;
  }

  if(auxNodo1->getSiguiente()==ultimo) throw 405;

  auxNodo2=auxNodo1->getSiguiente();
  auxNodo1->setSiguiente(auxNodo2->getSiguiente());
  auxNodo2->setSiguiente(NULL);
  ultimo->setSiguiente(auxNodo2);
}


#endif // U04_COLAS_COLA_COLA_H_
