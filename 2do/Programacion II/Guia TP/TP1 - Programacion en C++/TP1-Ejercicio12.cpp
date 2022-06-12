#include <iostream>

using namespace std;

void reorganizar( int t, int *p){
  int v[t];

  for(int i=0; i<t; i++){
    v[i]=*p;
    p++;
  }
  int q, contador;

  do{
    contador=0;
    for(int i=0; i<t-1; i++){
      if (v[i]<v[i+1]){
        q=v[i];
        v[i]=v[i+1];
        v[i+1]=q;
        contador++;
      }
    }
  }while(contador!=0);

  for(int i=0; i<t; i++){
    cout<<v[i]<<endl;
  }
}


int main(){
  int tarray, *p;

  cout<<"Ingrese el tamaño del array: "; cin>>tarray;
  int array[tarray];
  p= array;

  for(int i=0; i<tarray; i++){
    cout<<"Ingrese el valor para la posicion "<<i<<" del array: "; cin>>array[i];
  }

  reorganizar(tarray,p);

  return 0;
}
