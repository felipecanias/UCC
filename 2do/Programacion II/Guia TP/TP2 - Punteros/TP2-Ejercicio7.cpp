#include <iostream>

using namespace std;

void Inversor( char *p1, char *p2, int l){
  char array1[l-1],array2[l-1], *a, *b;

  a=array1;
  b=array2;

  for( int i=0; i<l; i++){
    a[i]=p1[i];
  }

  for(  int i=0; i<l; i++){
    b[i]=a[i];
  }

  for(  int i=0; i<l; i++){
    cout<<b[i];
  }

}

int main(){
  string z;

  cout<<"Ingrese primera cadena: "; cin>>z;

  int largo= z.length();
  char *p1, *p2, x[largo-1], y[largo-1];

  p1=x;
  p2=y;

  for(int i=0; i<largo; i++){
    p1[i]=z[i];
  }

    Inversor(p1, p2, largo );

  return 0;
}
