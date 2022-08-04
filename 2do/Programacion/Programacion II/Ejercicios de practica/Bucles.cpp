#include <iostream>

using namespace std;

int main ()
{
    int n, suma=0, i;

    cout<<"Ingrese cantidad de numeros a sumar: "; cin>>n;

    for(i=0;i<=n;i++){
        suma+=i;
    }

    cout<<"El resultado es: "<<suma;

    return 0;
}
