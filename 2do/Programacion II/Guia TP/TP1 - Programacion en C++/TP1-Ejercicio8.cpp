#include <iostream>

using namespace std;

int pow(int k, int j){
  int l=1;
  for(int i=1; i<=j; i++){
    l*=k;
  }
  return l;
}

int cpolinomio(int &k, int j, int p){
  int v;
  k= k*pow(j,p);
  return k;
}

int main(){
  int grado,x,tarray,r=0;

  cout<<"Ingrese grado del polinomio: "; cin>>grado;
  int polinomio[grado];

  for( int i=0; i<=grado; i++){
    cout<<"Ingrese valor del coeficiente de grado "<<i<<" "; cin>>polinomio[i];
  }

  cout<<"Ingrese el valor de la variable X: "; cin>>x;
  for(int i=0; i<=grado; i++){
    cpolinomio(polinomio[i],x,i);
    r+=polinomio[i];
  }

  cout<<"El resultado del polinomio es: "<<r;
  return 0;
}
