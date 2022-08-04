#include <iostream>

using namespace std;

int main ()
{
    int a, b, c, x;

    cout<<"Ingrese los valores de A, B y C de la ecuacion Ax^2+Bx+C=0: ";
    cin>>a;
    cin>>b;
    cin>>c;

    x= b*b-4*a*c;

    if (x>0){
        cout<<"X1 y X2 son reales diferentes";}

        else if(x==0){
            cout<<"X1 y X2 son reales distintas";}

            else{
                cout<<"X1 y X2 son complejas";
        }


    return 0;
}
