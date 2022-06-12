#include <iostream>

using namespace std;

  class fecha{
  private:
    int dia;
    int mes;
    int anio;

  public:
    fecha();
    void setdia (int x);
    void setmes (int y);
    void setanio (int z);
    int getdia ();
    int getmes ();
    int getanio ();
  };

  void fecha:: setdia (int x){
    dia= x;
  }
  void fecha:: setmes (int y){
    mes= y;
  }
  void fecha:: setanio (int z){
    anio= z;
  }

  int fecha:: getdia(){
    return dia;
  }
  int fecha::getmes(){
    return mes;
  }
  int fecha:: getanio(){
    return anio;
  }
  fecha::fecha(){
    dia=01;
    mes=01;
    anio=1990;
  }


int main(){
  fecha A, B;
  int d,m,a;


  cout<<"Ingrese dia de nacimiento: "; cin>>d;
  A.setdia(d);
  cout<<"Ingrese mes de nacimiento: "; cin>>m;
  A.setmes(m);
  cout<<"Ingrese anio de nacimiento: "; cin>>a;
  A.setanio(a);

  cout<<"------------------"<<endl;
  cout<<A.getdia()<<"/";
  cout<<A.getmes()<<"/";
  cout<<A.getanio()<<endl;

  cout<<"------------------"<<endl;
  cout<<B.getdia()<<"/";
  cout<<B.getmes()<<"/";
  cout<<B.getanio()<<endl;


  return 0;
}
