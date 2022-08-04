#include <iostream>


using namespace std;

int main ()
{
    int n[100],num,i,mayor=0;

    cout<<"Ingrese numero de elementos del arreglo: "; cin>>num;

    for(i=0;i<num;i++){
        cout<<i+1<<" --> "<<" Ingrese un numero: ";
        cin>>n[i];

        if(n[i]>mayor){
            mayor=n[i];
        }
    }
    cout<<"-------------------"<<endl;

    cout<<"El numero de mayor valor del vector es: "<<mayor;

    return 0;
}
