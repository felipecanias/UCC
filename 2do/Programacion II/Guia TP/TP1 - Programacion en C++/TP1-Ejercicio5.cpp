#include <iostream>

using namespace std;

bool EsPrimo(int n){
  int c=0;
  for(int i=1; i<=n; i++){
    if (n%i==0){
      c++;
    }
  }
  return c==2;
}



int main(){
  int n1,n2;
  int k=0,q=0, DivSize=0, DivSize2=0;
  int band=0;

  cout<<"Ingrese numero 1: "; cin>>n1;
  cout<<"Ingrese numero 2: "; cin>>n2;

// Determinacion del tamaño del array Divn1
  for(int i = 1; i<=n1; i++){
    if(n1%i==0){
      if(EsPrimo(i)){
        DivSize++;
      }
    }
  }

  int Divn1[DivSize];

//Carga de divisores EsPrimo al array Divn1
  for(int i=1; i<=n1; i++){
    if(n1%i==0){
      if(EsPrimo(i)){
        Divn1[k]=i;
        k++;
      }
    }
  }


// Determinacion del tamaño del array Divn2
  for(int i = 1; i<=n2; i++){
    if(n2%i==0){
      if(EsPrimo(i)){
        DivSize2++;
      }
    }
  }

  int Divn2[DivSize2];

//Carga de divisores EsPrimo al array Divn2
  for(int i=1; i<=n2; i++){
    if(n2%i==0){
      if(EsPrimo(i)){
        Divn2[q]=i;
        q++;
      }
    }
  }

//Comprobando si los divisores EsPrimo de n1 y n2 son iguales
  if (k==q){
    for(int i=0; i<k; i++){
      if (Divn1[i]==Divn2[i]){
        band++;
      }
    }
    if(band==k){
      cout<<"Los divisores primos de n1 y n2 son iguales";
      }
    else{
      cout<<"Los divisores primos de n1 y n2 son diferentes";
    }
  }
  else{
    cout<<"Los divisores primos de n1 y n2 son diferentes";
  }

  return 0;
}
