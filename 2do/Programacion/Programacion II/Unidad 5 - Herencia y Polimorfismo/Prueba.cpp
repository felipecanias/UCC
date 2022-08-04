#include <iostream>

using namespace std;

 class A{
  protected:
     int a;
     int b;
   public:
     A();
      void seta(int a);
      void setb(int b);
      virtual void suma();
 };
  A::A(){
  a=0;
  b=0;
  }

  void A::suma(){
    int suma;
    suma=a+b;
  }
class B: public A{
    public:
      B();
      void seta(int a);
      void setb(int b);
      void suma();

  };
  B::B(){
    a=0;
    b=0;
  }
  void B::seta(int x){
    a=x;
  }
  void B::setb(int y){
    b=y;
  }

  void B::suma(){
    int suma;
    suma=a-b;
    cout<<suma<<endl;
  }

int main(){
  int a,b;
  B H;
  cout<<"Ingrese valor A:";
  cin>>a;
  cout<<"Ingrese valor B:";
  cin>>b;

  H.seta(a);
  H.setb(b);
  H.suma();


  return 0;
}
