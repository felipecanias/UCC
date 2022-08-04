#include <iostream>
#include <time.h>

using namespace std;

int main ()
{
    int m[100][100], t[100][100];
    int f,c,cantf,cantc,tamano,v,i,j;

    for(i=1;3>=i;i++){
        for(j=1;3>=j;j++){
        cout<<"Ingrese valor para fila: "<<i<<" y columna: "<<j<<" : "; cin>>m[i][j];
        }
    }
    cout<<" Matriz Original: "<<endl;
    for(i=1;3>=i;i++){
        for(j=1;3>=j;j++){
        cout<< m[i][j];
        }
    cout<<"\n";
    }

    cout<<"---------------"<<endl;

    for(i=1;3>=i;i++){
        for(j=1;3>=j;j++){
        t[j][i]= m[i][j];
        }
    }

    cout<<" Matriz Transpuesta: "<<endl;
    for(i=1;3>=i;i++){
        for(j=1;3>=j;j++){
        cout<< t[i][j];
        }
    cout<<"\n";
    }

    return 0;
}
