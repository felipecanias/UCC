#include <iostream>

using namespace std;

  void reorganizar( int t, int *p){
    int v[t];

    for(int i=0; i<t; i++){
      v[i]=*p;
      p++;
    }

    int posicion=0,q;
    for (int i=0; i<t; i++){
      if(v[i]%2!=0){
        q=v[posicion];
        v[posicion]=v[i];
        v[i]=q;
        posicion++;
      }
    }

    for(int i=0; i<t; i++){
      cout<<v[i];
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
