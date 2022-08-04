#include <iostream>

using namespace std;

int main(){

    int x=5,y=10,z=15;
    int *p;

    p=&x;
    cout<<*p<<endl;
    p=&y;
    cout<<*p<<endl;
    p=&z;
    cout<<*p<<endl;

return 0;
}
