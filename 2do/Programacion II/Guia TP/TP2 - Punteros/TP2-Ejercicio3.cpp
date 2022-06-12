#include <iostream>

using namespace std;

int main(){

  int v[4];
  int *p,*q;

  p=v;
  q=v;
  q+=4;

  cout<<q-p;

  return 0;
}
