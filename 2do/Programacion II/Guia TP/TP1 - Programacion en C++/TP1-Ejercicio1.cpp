#include <iostream>

using namespace std;

int x,y,d,e,s;
int suma(int,int,int);

int main(){

    cout<<"Ingrese posicion inicial X: "; cin>>x;
    cout<<"Ingrese posicion final Y: "; cin>>y;
    cout<<"Ingrese distancia de salto D: "; cin>>d;

    suma(x,y,d);
    cout<<"--------------------"<<endl;
    cout<<"La cantidad de saltos necesarios son: "<<s<<endl;

    return 0;
}

int suma (int x,int y,int d){
  e= y-x; // Distancia a saltar
  s= e/d; // Cantidad de saltos

  return s;
}
