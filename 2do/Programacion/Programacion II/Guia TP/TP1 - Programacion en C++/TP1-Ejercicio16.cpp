#include <iostream>

using namespace std;

void sumamatriz( int f, int c, int *p, int q, int w){
  int m[f][c],sumatoria=0;

  for(int i=0; i<f; i++){
    for(int j=0; j<c; j++){
      m[i][j]=*p;
      p++;
    }
  }

  for(int i=0; i<f; i++){
    for(int j=0; j<c; j++){
      if(((q-i)==1||(q-i)==-1) && ((w-j)==1||(w-j)==-1)){
        sumatoria+=m[i][j];
      }
    }
  }

  cout<<"El resultado es: "<<sumatoria;

}

int main(){

  int filas,columnas, *p,p1,p2;

  cout<<"Ingrese las cantidad de filas de la matriz: "; cin>>filas;
  cout<<"Ingrese las cantidad de columnas de la matriz: "; cin>>columnas;
  int matriz[filas][columnas];
  p= matriz[0];

  for(int i=0; i<filas; i++){
    for(int j=0; j<columnas; j++){
      cout<<"Ingrese el valor para la posicion "<<i<<" "<<j<<" de la matriz: "; cin>>matriz[i][j];
    }
  }

  cout<<"Ingrese posicion para la suma adyacente de los demas elementos: "; cin>>p1; cin>>p2;

  sumamatriz(filas,columnas,p,p1,p2);

  return 0;
}
