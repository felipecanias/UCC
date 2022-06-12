#include <iostream>
#include "reloj.h"

using namespace std;


int main(){
  tiempo H;
  temperatura T;
  int x,y,z,c,xx,yy,zz,t,h;

  cout<<"Ingrese hora:"; cin>>x;
  H.sethora(x);
  cout<<"Ingrese minutos: "; cin>>y;
  H.setmin(y);
  cout<<"Ingrese segundos: "; cin>>z;
  H.setseg(z);
  cout<<"Ingrese hora de la alarma:"; cin>>xx;
  H.sethoraalarma(xx);
  cout<<"Ingrese minutos de la alarma: "; cin>>yy;
  H.setminalarma(yy);
  cout<<"Ingrese segundos de la alarma: "; cin>>zz;
  H.setsegalarma(zz);
  cout<<"Ingrese duracion de la alarma: "; cin>>t;
  H.settiempoalarma(t);
  cout<<"Ingrese temperatura en grados C: "; cin>>c;
  T.settemp(c);

  cout<<"------------------"<<endl;
  cout<<"La hora es: ";
  cout<<H.gethora()<<":";
  cout<<H.getmin()<<":";
  cout<<H.getseg()<<endl;
  cout<<"La temperatura es: "<<T.gettemp()<<" grados C"<<endl;


  do{
    ++H;
    H.alarma();

  cout<<H.gethora()<<":";
  cout<<H.getmin()<<":";
  cout<<H.getseg()<<endl;

  }while(true);


  return 0;
}
