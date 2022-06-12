#include <iostream>
#include <time.h>

using namespace std;

int main ()
{
    int n[]= {5,4,3};
    int i,pos,aux;

    for(i=0;i<3;i++){
        pos=i;
        aux=n[i];

        while((pos>0) && (n[pos-1] > aux)){
            n[pos] = n[pos-1];
            pos--;
        }
        n[pos]=aux;
    }


    for(i=0;i<3;i++){
        cout<<n[i]<<endl;
    }


    return 0;
}
