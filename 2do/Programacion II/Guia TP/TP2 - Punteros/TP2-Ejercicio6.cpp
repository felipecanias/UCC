#include <iostream>

using namespace std;

void Inversor( char *p, int l){
  char a[l],n=l-1,aux;
  
  for(int i=0; i<=l; i++){
    a[i]=*p;
    p++;
  }

  if(l%2==0){
    for(int i=0; i<(l/2); i++){
      aux=a[i];
      a[i]=a[n];
      a[n]=aux;
      n--;
    }
  }
  else{
    for(int i=0; i<(l+1)/2; i++){
      aux=a[i];
      a[i]=a[n];
      a[n]=aux;
      n--;
  }

}
for(int i=0; i<l; i++){
  cout<<a[i];
}
}

int main(){

  string x;
  cout<<"Ingrese una palabra: "; cin>>x;
  int largo= x.length();
  char *p, k[largo];


  for(int i=0; i<largo; i++){
    k[i]=x[i];
  }

  p=k;

  Inversor(p,largo);

  return 0;
}
