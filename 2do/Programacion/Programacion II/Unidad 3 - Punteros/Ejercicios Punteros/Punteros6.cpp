#include <iostream>

using namespace std;

int main(){

    int *p,z;
    float *q,t;

    p=&z; //p apunta a la direccion de z
    q=&t; //q apunta a la direccion de t
    *p=10; // el valor de z=10
    *q=15; // el valor de t=15

    cout<<*p<<endl;
    cout<<*q<<endl;
return 0;
}
