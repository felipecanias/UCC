#include <iostream>

using namespace std;

class rectangulo{
  private:
    int largo;
    int alto;
    float perimetro;
    float area;

  public:
    void setlargo(int l);
    void setalto(int a);
    int getlargo();
    int getalto();
    float getperimetro();
    float getarea();
};

  void rectangulo::setlargo(int largo){
    this->largo=largo;
  }
  void rectangulo::setalto(int alto){
    this->alto=alto;
  }

  int rectangulo::getlargo(){
    return largo;
  }
  int rectangulo::getalto(){
    return alto;
  }

  float rectangulo::getperimetro(){
    return 2*alto+2*largo;
  }
  float rectangulo::getarea(){
    return alto*largo;
  }

int main(){

  rectangulo R;
  int l,a;

  cout<<"Ingrese alto del rectangulo: "; cin>>a;
  R.setalto(a);
  cout<<"Ingrese largo del rectangulo: "; cin>>l;
  R.setlargo(l);

  cout<<"El perimetro del rectangulo es: "<<R.getperimetro()<<endl;
  cout<<"El area del rectangulo es: "<<R.getarea();

  return 0;
}
