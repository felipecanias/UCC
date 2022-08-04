#include <iostream>
#include <time.h>

using namespace std;

int main ()
{
    int m[100][100], t[100][100];
    int f,c,cantf,cantc,tamano,v,i,j;

    for(i=1;3>=i;i++){ // Matriz Original
        for(j=1;3>=j;j++){
        cout<<"Ingrese valor para fila: "<<i<<" y columna: "<<j<<" : "; cin>>m[i][j];
        }
    }


    cout<<" Matriz original: "<<endl;
    for(i=1;3>=i;i++){
        for(j=1;3>=j;j++){
        cout<< m[i][j];
        }
    cout<<"\n";
    }


    cout<<"---------------"<<endl;


    for(i=1;3>=i;i++){ //Matriz Transpuesta
        for(j=1;3>=j;j++){
        t[j][i]= m[i][j];
        }
    }

        cout<<" Matriz transpuesta: "<<endl;
    for(i=1;3>=i;i++){
        for(j=1;3>=j;j++){
        cout<< t[i][j];
        }
    cout<<"\n";
    }


    cout<<"---------------"<<endl;


    if(m[1][2]==t[1][2]){
         if(m[1][3]==t[1][3]){
                if(m[2][3]==t[2][3]){
        cout<<"La matriz es simetrica"<<endl;
                }
         }
    }

    else{
        cout<<"La matriz es asimetrica"<<endl;
    }


    return 0;
}
