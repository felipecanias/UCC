#include <iostream>

using namespace std;

int a,b,k,i;
int AC=0;
int divisor(int c, int d, int h){
  for( i = c; i<=d; i++){
    if(i%h==0){
      AC++;
    }
  }
  return AC;
}

int main(){

  cout<<"Ingrese valor de A: "; cin>>a;
  cout<<"Ingrese valor de B: "; cin>>b;
  cout<<"Ingrese valor de K: "; cin>>k;


  cout<<"-------------------"<<endl;
  cout<<"La cantidad de valores divisibles por "<<k<<" son: "<<divisor(a,b,k);

  }
