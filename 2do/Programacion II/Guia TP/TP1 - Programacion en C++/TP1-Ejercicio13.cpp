#include <iostream>

using namespace std;

void determinarubic( int t, int *p, int k){
  int v[t], ubic[t];
  int contador=0, n=0;
  for(int i=0; i<t; i++){
    v[i]=*p;
    p++;
  }

  for( int i=0; i<t; i++){
    if(k==v[i]){
      contador++;
      ubic[n]=i;
      n++;
    }
  }
    if(contador!=0){
      for(int i=0; i<n; i++){
        cout<<"El numero esta presente y se encuentra en la ubicacion: "<<ubic[i]<<" del arreglo"<<endl;
      }
    }
    else{
      cout<<"El numero no se encuentra en el array";
    }
}

int main (){

  int tarray, *p,x;

  cout<<"Ingrese el tamaño del array: "; cin>>tarray;
  int array[tarray];
  p= array;

  for(int i=0; i<tarray; i++){
    cout<<"Ingrese el valor para la posicion "<<i<<" del array: "; cin>>array[i];
  }

  cout<<"Ingrese un numero: "; cin>>x;

  determinarubic(tarray, p, x);

  return 0;
}
