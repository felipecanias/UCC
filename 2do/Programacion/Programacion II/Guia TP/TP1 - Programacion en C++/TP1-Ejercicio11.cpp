#include <iostream>

using namespace std;

int contadornumdistintos( int t, int *p){
  int v[t];

  for(int i=0; i<t; i++){
    v[i]=*p;
    p++;
  }

  int contador=1;
  for( int i=0; i<t; i++){
      if(v[0]!=v[i]){
        contador++;
      }
  }
  return contador;
}

int main(){
  int tarray, *p;

  cout<<"Ingrese el tamaño del array: "; cin>>tarray;
  int array[tarray];
  p= array;

  for(int i=0; i<tarray; i++){
    cout<<"Ingrese el valor para la posicion "<<i<<" del array: "; cin>>array[i];
  }

  cout<<"La cantidad de numeros distitos en el vector es: "<<contadornumdistintos(tarray,p);

  return 0;
}
