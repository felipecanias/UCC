#include <iostream>
#include <math.h>
#include <ctime>

using namespace std;

long double ErrorTolerado = 0.00001;
int NumeroMaximoDePasos = 10000;
int NumeroDePasos = 0;

void delay(int secs) {
  for(int i = (time(NULL) + secs); time(NULL) != i; time(NULL));
}

long double Function(long double X){
  return (sqrt(sqrt((3+X-2*pow(X,2)))));
}

long double RaizPorPuntoFijo(long double X){
  //CONVERGE
  if(abs(Function(X)-Function(Function(X)))>=abs(Function(Function(X))-Function(Function(Function(X))))){
    cout<<"CONVERGE"<<endl;
    if(abs(Function(X)-X)<=ErrorTolerado){
      return X;
    }
    return RaizPorPuntoFijo(Function(X));
  }
  //DIVERGE
  if(abs(Function(X)-Function(Function(X)))<abs(Function(Function(X))-Function(Function(Function(X))))){
    cout<<"DIVERGE"<<endl;
    return -1;
  }
  //delay(1);
  return 0;
}

int main(){
  cout<<RaizPorPuntoFijo(1);
}
