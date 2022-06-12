#include <iostream>
#include <string.h>
using namespace std;

void Mayuscula(char *p){
  char a[9], *k;

  for(int i=0; i<=9; i++){
    a[i]=*p;
    p++;
  }

  k=a;
  strupr(k);
  cout<<k;
}

int main(){

    char  x[9];
    char *p;

    p=x;

    cout<<"Ingrese una palabra de no mas de 10 letras: "; cin.getline(x,10,'\n');

    Mayuscula(p);

  return 0;
}
