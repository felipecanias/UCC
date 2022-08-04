#include <iostream>
#include <time.h>
#include <string.h>

using namespace std;

int main ()
{
    char palabra[]= "Hola";
    char palabra2[]= "Holaa";

    if (strcmp(palabra,palabra2)==0){
        cout<<"Las palabras son iguales.";
    }
    else{
        cout<<"Las palabras son diferentes.";
    }

    return 0;
}
