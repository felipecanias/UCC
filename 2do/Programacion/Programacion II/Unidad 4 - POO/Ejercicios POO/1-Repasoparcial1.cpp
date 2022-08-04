#include <iostream>

using namespace std;

class articulo{
  private:
    float preciobase;
    float preciominorista;
    float preciomayorista;

  public:
    void setpreciobase(float x);
    float getpreciobase();
    float getpreciominorista();
    float getpreciomayorista();
    void incremento(int a);

};

void articulo::setpreciobase(float preciobase){
  this->preciobase=preciobase;
}

float articulo::getpreciobase(){
  return preciobase;
}
float articulo::getpreciominorista(){
  preciominorista= preciobase*1.30;
  return preciominorista;
}
float articulo::getpreciomayorista(){
  preciomayorista= preciobase*1.15;
  return preciomayorista;
}
void articulo::incremento(int a){
  preciobase=a;
}

int main(){

  articulo A;
  float x,y;

  cout<<"Ingrese precio base del articulo: "; cin>>x;
  A.setpreciobase(x);

  cout<<"-----------------------"<<endl;

  cout<<"Precio base del articulo: "<<A.getpreciobase()<<endl;
  cout<<"Precio minorista del articulo: "<<A.getpreciominorista()<<endl;
  cout<<"Precio mayorista del articulo: "<<A.getpreciomayorista()<<endl;

  cout<<"-----------------------"<<endl;

  cout<<"Ingrese nuevo valor del precio base del producto: "; cin>>y;
    A.setpreciobase(y);
  cout<<"Precio base del articulo: "<<A.getpreciobase()<<endl;
  cout<<"Precio minorista del articulo: "<<A.getpreciominorista()<<endl;
  cout<<"Precio mayorista del articulo: "<<A.getpreciomayorista();




  return 0;
}
