#include <iostream>
#include <time.h>

using namespace std;

int main ()
{
    int n[]= {4,3,2,5,1};
    int i,j,aux,mini;

    for(i=0;i<5;i++){
        mini=i;
        for(j=i+1;j<5;j++){
            if(n[j] < n[mini]){
                mini=j;
            }
        }
        aux=n[i];
        n[i]=n[mini];
        n[mini]=aux;
    }

    for(i=0;i<5;i++){
        cout<<n[i]<<endl;
    }


    return 0;
}
