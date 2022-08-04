#include <iostream>

using namespace std;

int main ()
{
    int x,y,aux;

    cout<<"Ingrese el valor de X: "; cin>>x;
    cout<<"Ingrese el valor de Y: "; cin>>y;

    aux=x;
    x=y;
    y=aux;

    cout<<"EL valor de X es: "<<x<<endl;
    cout<<"El valor de Y es: "<<y;


    return 0;
}
