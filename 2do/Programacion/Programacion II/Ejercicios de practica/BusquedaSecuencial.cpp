#include <iostream>
#include <time.h>

using namespace std;

int main ()
{
    int a[]= {3,2,5,4,1};
    int i=0,dato=8;
    char band = 'F';

    while ((band=='F') && (i<5)){
        if(a[i]== dato){
            band= 'V';
        }
        i++;
    }

    if(band== 'F'){
        cout<<"El dato no se encuentra en el arreglo";
    }
    if(band== 'V'){
        cout<<"El dato si se encuentra en el arreglo";
    }




    return 0;
}
