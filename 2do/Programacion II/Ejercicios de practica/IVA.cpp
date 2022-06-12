#include <iostream>

using namespace std;

int main ()
{
    int precio=0;
    float preciof=0;

    cout<<"Ingrese precio del producto: "<<endl;
    cin>>precio;

    preciof= precio*1.21;

    cout<<"El precio con el iva aplicado es: "<<preciof;



    return 0;
}
