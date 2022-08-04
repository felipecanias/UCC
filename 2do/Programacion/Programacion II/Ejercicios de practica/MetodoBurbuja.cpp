#include <iostream>
#include <time.h>

using namespace std;

int main ()
{
    int n[]= {4,1,2,3,5};
    int i,j,aux;

    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            if(n[j]>n[j+1]){
                aux=n[j];
                n[j]=n[j+1];
                n[j+1]=aux;
            }
        }
    }

    cout<<"Orden Ascendente: "<<endl;
    for(i=0;i<5;i++){
        cout<<n[i]<<endl;
    }

    return 0;
}
