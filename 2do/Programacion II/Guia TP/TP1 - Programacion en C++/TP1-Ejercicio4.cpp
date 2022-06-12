#include <iostream>

using namespace std;

int fac=1;

int factorial(int n){
  if(n>0){
    fac*=n;
    factorial(n-1);
  }
  else{
    return fac;
  }

}

int main(){
  int a;
  cout<<"Ingrese el numero a calcular el factorial: "; cin>>a;
  cout<<"-------------------------"<<endl;
  cout<<"El factorial de "<<a<<" es: "<<factorial(a);

  return 0;
}
