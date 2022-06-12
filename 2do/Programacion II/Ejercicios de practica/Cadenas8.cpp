#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main ()
{
    char palabra[]= "123";
    char palabra1[]="123.32";
    int n1;
    float n2;

    n1=atoi(palabra);
    n2=atof(palabra1);

    cout<<n1<<endl;
    cout<<n2<<endl;

    return 0;
}
