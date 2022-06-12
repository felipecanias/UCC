#include <iostream>

using namespace std;

int main ()
{
    int practico,teorico,participacion,notaf=0;

    cout<<"Ingrese nota del practico: "; cin>>practico;
    cout<<"Ingrese nota del teorico: "; cin>>teorico;
    cout<<"Ingrese nota del participacion: "; cin>>participacion;

    practico *= 0.30;
    teorico*= 0.60;
    participacion *= 0.10;

    notaf= practico + teorico + participacion;

    cout<<" La nota final es: "<<notaf;

    return 0;
}
