#include <iostream>
#include <math.h>

using namespace std;

long double ErrorTolerado = 0.0001;
int NumeroMaximoDePasos = 10000;
int NumeroDePasos = 0;

long double Function(long double X){
  //FUNCION A ANALIZAR
  return (pow(X,2)-3);
}



long double RaizPorBiseccion(long double A, long double B, int N){

  long double Medio = (A+B)/2;
  //cout<<A<<" "<<B<<" "<<Medio<<endl;

  if((Function(A)<0&&Function(B)>0)||(Function(B)<0&&Function(A)>0)){
    if(NumeroDePasos<N){
      if(abs(Function(Medio))<=ErrorTolerado){

        return Medio;
      }
      else{
        if((Function(A)<0&&Function(Medio)>0)||(Function(Medio)<0&&Function(A)>0)){
          //cout<<"A: "<<Function(Medio)<<" "<<Medio<<endl;
          NumeroDePasos++;
          return RaizPorBiseccion(A,Medio, N);
        }
        else{
          //cout<<"B: "<<Function(Medio)<<" "<<Medio<<endl;
          NumeroDePasos++;
          return RaizPorBiseccion(Medio,B, N);
        }
      }
    }
    else{
      cout<<"El metodo finalizo por cantidad de pasos!"<<endl;
      return -1;
    }
  }
  else{
      cout<<"No se cumplen los requisitos para utilizar este metodo!"<<endl;
      return -1;
  }

}


int main(){

  cout << "METODO DE BISECCION" << endl << endl;
  cout << "El resultado de la aproximacion es: " << RaizPorBiseccion(2, 1, NumeroMaximoDePasos) << endl;
  cout << "Numero de pasos realizados para llegar a la aproximacion: " << NumeroDePasos << endl;

}
