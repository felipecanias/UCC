#include <iostream>
#include <time.h>
#include <string.h>

using namespace std;

int main ()
{
    char palabra[]= "Hola";
    char palabra1[]=", Como estas?";
    char palabra2[30];

    strcpy(palabra2,palabra);

    strcat(palabra2,palabra1);


    cout<<palabra2<<endl;

    return 0;
}
