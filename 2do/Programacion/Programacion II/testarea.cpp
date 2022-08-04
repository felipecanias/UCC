#include <iostream>

using namespace std;

class Base{
public:
  virtual void f(){cout<<"f(): clase base()!!"<<endl;}
  void g(){cout<<"g():clase base()!!"<<endl;}

};
class derivada1: public Base{
public:
  virtual void f(){cout<<"f(): clase derivada()!!"<<endl;}
  void g(){cout<<"g():clase derivada()!!"<<endl;}
};

int main(){
 Base b; derivada1 d1;
 Base *p=&b;
 p->f();
 p->g();
 p=&d1;
 p->f();
 p->g();
  return 0;
}
