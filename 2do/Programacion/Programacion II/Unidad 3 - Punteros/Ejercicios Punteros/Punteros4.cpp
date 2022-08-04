#include <iostream>

using namespace std;

int main(){

    int *p,z;
    float *q,t;

    p=&z;
    q=&t;
    *p=10;
    *q=15;

    cout<<*p<<endl;
    cout<<*q<<endl;
return 0;
}
