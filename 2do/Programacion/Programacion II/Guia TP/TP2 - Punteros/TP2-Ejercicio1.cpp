#include <iostream>

using namespace std;

int main(){

  int x=1,y=2;
  int *p;

  p=&x;
  cout<<p<<endl;
  cout<<*p<<endl;
  cout<<"-------------------"<<endl;

  p=&y;
  cout<<p<<endl;
  cout<<*p<<endl;

  return 0;
}
