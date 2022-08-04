#include <iostream>
#include <math.h>

using namespace std;

int main ()
{   float x,y, result=0;

    cout<<"Ingrese el valor de X: "; cin>>x;
    cout<<"Ingrese el valor de y: "; cin>>y;

    result= (sqrt(x))/(pow(y,2)-1);

    cout<<"El resultado es: "<<result;


    return 0;
}
