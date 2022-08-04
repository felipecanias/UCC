#include <iostream>

using namespace std;

int main(){

  int v[14];
  int *p;

  p=v;

  for(int i=0; i<=14; i++){
    p[i]=rand() % 100 + 1;
  }

  for(int i=0; i<=14; i++){
    cout<<"El numero es: "<<*p<<" y la direccion de memoria es: "<<p<<endl;
    p++;
  }

  return 0;
}
