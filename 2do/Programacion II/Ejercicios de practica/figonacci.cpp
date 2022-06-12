#include <iostream>

using namespace std;

int main ()
{
    int n,figonacci1=0,figonacci2=1,i,r=1;

    cout<<"Ingrese cantidad de veces que se realizara figonacci: "; cin>>n;

    cout<<"1 ";
    for(i=1;i<n;i++){
        r=figonacci1+figonacci2;
        cout<<r<<" ";
        figonacci1=figonacci2;
        figonacci2=r;

    }

    return 0;
}
