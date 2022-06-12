#include <iostream>
#include <time.h>

using namespace std;

int main ()
{
    int m[100][100];
    int f,c,cantf,cantc,tamano,v,i,j;

    cout<<"Ingrese cantidad de filas y columnas: ";
    cin>>f;
    cin>>c;

    for(i=1;f>=i;i++){
        for(j=1;c>=j;j++){
        cout<<"Ingrese valor para fila: "<<i<<" y columna: "<<j<<" : "; cin>>m[i][j];
        }
    }

    for(i=1;f>=i;i++){
        for(j=1;c>=j;j++){
        cout<< m[i][j];
        }
    cout<<"\n";
    }



    return 0;
}
