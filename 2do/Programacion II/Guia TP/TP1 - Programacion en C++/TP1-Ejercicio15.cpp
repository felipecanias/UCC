#include <iostream>

using namespace std;

void intercambioposicion( int t, int *p){
  int v[t],n=t-1,aux;

  for(int i=0; i<t; i++){
    v[i]=*p;
    p++;
  }

  if((t+1)%2==0){
    for(int i=0; i<(t+1)/2; i++){
      aux=v[i];
      v[i]=v[n];
      v[n]=aux;
      n--;
    }
  }
  else{
    for(int i=0; i<t/2; i++){
      aux=v[i];
      v[i]=v[n];
      v[n]=aux;
      n--;
  }
}
  for(int i=0; i<t; i++){
    cout<<v[i];
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

  intercambioposicion(tarray,p);

  return 0;
}
