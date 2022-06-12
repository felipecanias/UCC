#include <iostream>
#include <time.h>

using namespace std;

int main ()
{
    char nombre[20];

    cout<<"Ingrese su nombre: ";
    cin.getline(nombre,1,'\n');

    cout<<nombre;

    return 0;
}
