#include <iostream>
#include <time.h>

using namespace std;

int main ()
{
    int numero, dato, contador=0;

    srand(time(NULL)); // genera numero aleatorio
    dato= 1+ rand()%(100);

    do{
        cout<<"Digite un numero: "; cin>>numero;

        if(numero<dato){
            cout<<" Su numero es menor."<<endl;
        }
        if(numero>dato){
            cout<<"Su numero es mayor."<<endl;
        }
        contador++;
    }while(numero!=dato);

    cout<<"-----------------------"<<endl;

    cout<<"Adivino el numero: "<<dato<<endl;
    cout<<"Cantidad de intentos: "<<contador;


    return 0;
}
