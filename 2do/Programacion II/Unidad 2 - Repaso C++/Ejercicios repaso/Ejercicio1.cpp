#include <iostream>

using namespace std;

int main ()
{
    int y, a=1, b=2, x1, x2, x;

    cout<<"Ingrese los valores de x1: "; cin>>x1;
    cout<<"Ingrese los valores de x2: "; cin>>x2;


    for(x=x1;x<=x2;x++){

        y= a*x+b;
        cout<<"Los valores de Y son: "<<y<<endl;
    }



    return 0;
}
