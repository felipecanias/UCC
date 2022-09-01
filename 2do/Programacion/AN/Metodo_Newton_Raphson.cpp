#include <iostream>
#include <math.h>
#include <ctime>

using namespace std;

long double ErrorTolerado = 0.00001;
long double h = 0.0001;
int NumeroMaximoDePasos = 10000;
int NumeroDePasos = 0;

long double Funcion(long double X){
  return (exp(X));
}

long double Derivada(long double X){
  return ((Funcion(X+h)-Funcion(X))/h);
}

long double RaizPorNewtonRaphson(long double X){
  if(Funcion(X)<=ErrorTolerado){
    return X;
  }
  return RaizPorNewtonRaphson(X-(Funcion(X)/Derivada(X)));

}

int main(){
  cout << RaizPorNewtonRaphson(9);
}
