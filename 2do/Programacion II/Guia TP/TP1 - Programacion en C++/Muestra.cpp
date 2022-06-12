#include <iostream>

using namespace std;

int main(){

  int X = 2000, k=0, DivSize=0;

  for(int i = 1; i<=X; i++){
    if(X%i==0){
      DivSize++;
    }
  }

  int DivX[DivSize];

  for(int i=1; i<=X; i++){
    if(X%i==0){
      DivX[k]=i;
      k++;
    }
  }

  for(int i=0; i<k; i++){
    cout<<DivX[i]<<endl;
  }

}
