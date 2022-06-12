#include <iostream>

using namespace std;

int main(){

    float x,y;
    float *p;

    p=&x;
    *p=10;
    p=&y;
    *p=20;
    cout<<x<<endl;
    cout<<y<<endl;

return 0;
}
