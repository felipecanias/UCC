#include <iostream>

using namespace std;

class rectangulo{
  private:
    int largo;
    int alto;

  public:
    rectangulo(int a=5,int b=1);
    ~rectangulo(){cout<<"Se borra el rectangulo";}
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

  rectangulo::rectangulo( int a, int b){
    alto=a;
    largo=b;
  }

int main(){

int l1,l2,a1,a2,x,y,z;

cout<<"Ingrese alto del rectangulo 1: "; cin>>a1;
cout<<"Ingrese largo del rectangulo 1: "; cin>>l1;
rectangulo R1 (a1,l1);

cout<<"Ingrese alto del rectangulo 2: "; cin>>a2;
cout<<"Ingrese largo del rectangulo 2: "; cin>>l2;
rectangulo R2 (a2,l2);

  do{
    cout<<"1) Perimetro"<<endl;
    cout<<"2) Area"<<endl;
    cout<<"3) Area mayor"<<endl;
    cout<<"4) Salir"<<endl;
    cin>>x;

    switch (x) {
      case 1: cout<<"1) Perimetro rectangulo 1"<<endl;
              cout<<"2) Perimetro rectangulo 2"<<endl;
              cin>>y;
              switch (y) {
                case 1: cout<<R1.getperimetro()<<endl;break;
                case 2: cout<<R2.getperimetro()<<endl;break;
              }break;
      case 2: cout<<"1) Area rectangulo 1"<<endl;
              cout<<"2) Area rectangulo 2"<<endl;
              cin>>z;
              switch (z) {
                  case 1: cout<<R1.getarea()<<endl;break;
                  case 2: cout<<R2.getarea()<<endl;break;
              }break;
      case 3: if(R1.getarea()>R2.getarea()){
                cout<<"El area del Rectangulo 1 es mayor"<<endl;
              }
              else{
                cout<<"El area del Rectangulo 2 es mayor"<<endl;
              }
    break;
  }
  }while(x!=4);

  return 0;
}
