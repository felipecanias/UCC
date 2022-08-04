#include <iostream>

using namespace std;

bool primo(int n){
  int c=0;
  for(int i=1; i<=n; i++){
    if (n%i==0){
      c++;
    }
  }
  return c==2;
}

/*
bool semiprimo(int n){
  for(int i=2; i<= n; i++){
    for(int k=2; i<=n; k++){
      if (n==i*k){
        if(primo(i) && primo(k)){
            return 1;
        }
      }
    }
  }
  return 0;
}
*/

bool semiprimo(int n){
  for(int i=2; i<= n; i++){
    if(n%i==0&&primo(i)&&primo(n/i)){
       return 1;
  }
}
return 0;
}

int main(){
  int x;

  cout<<"Ingrese un numero: "; cin>>x;

  if(semiprimo(x)){
    cout<<"El numero es semiprimo";
  }
  else{
    cout<<"El numero no es semiprimo";
  }


  return 0;
}
