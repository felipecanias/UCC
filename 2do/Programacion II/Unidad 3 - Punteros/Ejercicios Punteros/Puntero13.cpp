#include <iostream>

using namespace std;

int main(){

    int v[10];
    int *p;

    p=v;
    cin>>*p;
    p++;
    cin>>*p;
    p++;
    cin>>*p;
    p++;

    cout<<v[0];
    cout<<v[1];
    cout<<v[2];
}
