#include <iostream>

using namespace std;

int main(){

    int x, y, *p, *q;
    p = &x;
    *p = 5; //*p=5
    q = &y;
    *q = 23; //*q=23
    cout<<*p<<" "<<*q<<endl;
    q = p; //q=&x
    *p = 35;    // *p=35 *q=35
    cout<<*p<<" "<<*q<<endl;
    q = NULL; // q no apunta a nada
    cout<<x<<" "<<y<<endl; // x=35 y=23
    cout<<&p;
    return 0;
}
