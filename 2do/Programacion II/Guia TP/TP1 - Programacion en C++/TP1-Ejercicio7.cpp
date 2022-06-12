#include <iostream>

using namespace std;

int intercambio(int &k, int &j){
  int q;
  q=k;
  k=j;
  j=q;

  return k,j;
}

int main(){
  int x,y;

  cout<<"Ingrese el valor de X: "; cin>>x;
  cout<<"Ingrese el valor de y: "; cin>>y;

  intercambio(x,y);

  cout<<"El valor de X es: "<<x<<endl;
  cout<<"El valor de Y es: "<<y<<endl;

  return 0;
}
