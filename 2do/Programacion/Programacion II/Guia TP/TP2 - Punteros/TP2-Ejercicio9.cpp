#include <iostream>

using namespace std;

int main(){

  int *p, n;

  cout<<"Ingrese tamaño del array: "; cin>>n;

  p= new int[n];

  for(int i=0; i<n; i++){
    cout<<"Ingrese los datos del array: "; cin>>p[i];
  }

  for(int i=0; i<n; i++){
    cout<<"Los datos son: "<<p[i]<<endl;
  }

  for(int i=0; i<n; i++){
    cout<<"Los datos son: "<<*p<<endl;
    p++;
  }

  delete p;

  return 0;
}
