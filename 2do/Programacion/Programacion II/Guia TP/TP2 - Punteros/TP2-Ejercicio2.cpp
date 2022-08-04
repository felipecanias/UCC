#include <iostream>

using namespace std;

int main(){

  int v[4];
  int *p;

  p=v;

  for( int i=0; i<=4; i++){
    cout<<p<<endl;
    p++;
  }

  return 0;
}
