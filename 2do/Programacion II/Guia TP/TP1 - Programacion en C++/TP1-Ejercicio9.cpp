#include <iostream>

using namespace std;

bool permutacion (int t, int *p){
  int v[t];

  for(int i=0; i<t; i++){
    v[i]=*p;
    p++;
  }

  int contador=0, n=1;
  for( int i=0; i<t; i++){
    for( int j=0; j<t; j++){
      if(v[i]==v[j+n]){
        contador++;
      }
    }
    n++;
  }

  if (contador==0){
    return true;
  }
    return false;
}

int main(){
  int tarray, *p;

  cout<<"Ingrese el tamaño del array: "; cin>>tarray;
  int array[tarray];
  p= array;

  for(int i=0; i<tarray; i++){
    cout<<"Ingrese el valor para la posicion "<<i<<" del array: "; cin>>array[i];
  }

  if(permutacion(tarray,p)){
    cout<<"El array es una permutacion";
  }
  else{
    cout<<"El array no es una permutacion";
  }

  return 0;
}
