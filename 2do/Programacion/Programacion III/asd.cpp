#include <iostream>

using namespace std;


int main(){

  int *p;
  p=new int();

  *p=3;

  delete p;

  cout<<*p;

}