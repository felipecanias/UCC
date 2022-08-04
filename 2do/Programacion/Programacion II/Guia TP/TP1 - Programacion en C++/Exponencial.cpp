#include <iostream>

using namespace std;

int pow(int k, int j){
  int p=1;
  for(int i=1; i<=j; i++){
    p*=k;
  }
  return p;
}

int main(){

  cout<<pow(2,4);
  return 0;
}
