#include <iostream>

using namespace std;

class material{
  private:
    int codigo;
    int cant;
    int cantminima;
    int cantmaxima;

  public:
    material(int a,int b, int c, int d);
    void setcodigo(int f);
    void setcant(int x);
    void setcantminima(int y);
    void setcantmaxima(int z);
    int getcant();
    int getcantminima();
    int getcantmaxima();
    void agregar(int a);
    void extraer(int b);

};
  material::material(int a,int b, int c, int d){
    codigo=a;
    cant=b;
    cantminima=c;
    cantmaxima=d;
  }
  void material::setcodigo(int f){
    codigo=f;
  }
  void material::setcant(int x){
    cant=x;
  }
  void material::setcantminima(int y){
    cantminima=y;
  }
  void material::setcantmaxima(int z){
    cantmaxima=z;
  }

  int material::getcant(){
    return cant;
  }
  int material::getcantminima(){
    return cantminima;
  }

  int material::getcantmaxima(){
    return cantmaxima;
  }

  void material::agregar(int a){

    if((a+cant)<=cantmaxima){
      cant+=a;
      cout<<"Se agrego la cantidad con exito!"<<endl;
    }
    else{
      cout<<"La cantidad a agregar supera el maximo del contenedor"<<endl;
    }
  }

  void material::extraer(int b){

    if(b<=cant){
      cant-=b;
      cout<<"La cantidad fue extraida con exito!"<<endl;
    }
    else{
      cout<<"No hay suficiente cantidad para extraer"<<endl;
    }
  }



int main(){

  int x,codigo,cant,cantminima,extraer;
  material M(0,0,0,0);

  do{
    cout<<"1)Crear Deposito"<<endl;
    cout<<"2)Agregar material"<<endl;
    cout<<"3)Extraer material"<<endl;
    cout<<"4)Verificar estado del deposito"<<endl;
    cout<<"5)salir"<<endl;
    cout<<"---------------------"<<endl;
    cin>>x;
    cout<<"---------------------"<<endl;

    switch(x){
      case 1:   cout<<"Ingrese codigo del material: "; cin>>codigo;
                M.setcodigo(codigo);
                cout<<"Ingrese cantidad del material: "; cin>>cant;
                M.setcant(cant);
                M.setcantmaxima(cant);
                cout<<"Ingrese cantidad minima del material: "; cin>>cantminima;
                M.setcantminima(cantminima);
                cout<<"---------------------"<<endl;
                break;

      case 2: cout<<"La cantidad del contenedor es de: "<<M.getcant()<<endl;
              cout<<"Ingrese cantidad de material a agregar: "; cin>>cant;
              M.agregar(cant);
              cout<<"---------------------"<<endl;
              break;

      case 3: cout<<"La cantidad del contenedor es de: "<<M.getcant()<<endl;
              cout<<"Ingrese cantidad a extraer: "; cin>>extraer;
              M.extraer(extraer);
              cout<<"---------------------"<<endl;
              break;

      case 4: cout<<"El estado del deposito es: "<<M.getcant()<<endl;
              cout<<"---------------------"<<endl;
              break;

    }

  }while(x!=5);

  return 0;
}
