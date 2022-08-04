#include <iostream>

using namespace std;

struct datos{
int dni,cuenta;
float saldo=100;
};


int main ()
{
    int i,f;
    datos v[100];
    float retiro=0, ingreso=0;




    cout<<"Ingrese numero de cuenta: ";
    cin>>v[i].cuenta;

    do{

    cout<<"Eliga la accion que quiere realizar: "<<endl;
    cout<<"Para ver saldo disponible: 0"<<endl;
    cout<<"Para realizar un retiro: 1"<<endl;
    cout<<"Para realizar un ingreso: 2"<<endl;
    cout<<"Para salir:3"<<endl;
    cin>>f;

    if(f==0){
        switch(v[i].cuenta){
            case 1: cout<<"El saldo disponible es: "<<v[i].saldo<<endl; break;
            case 2: cout<<"El saldo disponible es: "<<v[i].saldo<<endl; break;
            case 3: cout<<"El saldo disponible es: "<<v[i].saldo<<endl; break;
            case 4: cout<<"El saldo disponible es: "<<v[i].saldo<<endl; break;
            case 5: cout<<"El saldo disponible es: "<<v[i].saldo<<endl; break;
            default: cout<<"Saldo no disponible"<<endl; break;
        }
    }

    else if (f==1){
        switch (v[i].cuenta){
            case 1: cout<<"�Que cantidad desea retirar?: "<<endl; cin>>retiro;
                    v[i].saldo-=retiro;
                    cout<<"Retiro exitoso! Su retiro fue de: "<<retiro<<endl;
                    cout<<"Su saldo actual es: "<<v[i].saldo<<endl; break;
            case 2: cout<<"�Que cantidad desea retirar?: "<<endl; cin>>retiro;
                    v[i].saldo-=retiro;
                    cout<<"Retiro exitoso! Su retiro fue de: "<<retiro<<endl;
                    cout<<"Su saldo actual es: "<<v[i].saldo<<endl; break;
            case 3: cout<<"�Que cantidad desea retirar?: "<<endl; cin>>retiro;
                    v[i].saldo-=retiro;
                    cout<<"Retiro exitoso! Su retiro fue de: "<<retiro<<endl;
                    cout<<"Su saldo actual es: "<<v[i].saldo<<endl; break;
            case 4: cout<<"�Que cantidad desea retirar?: "<<endl; cin>>retiro;
                    v[i].saldo-=retiro;
                    cout<<"Retiro exitoso! Su retiro fue de: "<<retiro<<endl;
                    cout<<"Su saldo actual es: "<<v[i].saldo<<endl; break;
            case 5: cout<<"�Que cantidad desea retirar?: "<<endl; cin>>retiro;
                    v[i].saldo-=retiro;
                    cout<<"Retiro exitoso! Su retiro fue de: "<<retiro<<endl;
                    cout<<"Su saldo actual es: "<<v[i].saldo<<endl; break;
            default:cout<<"Error!"<<endl; break;



        }
    }
        else if (f==2){
        switch (v[i].cuenta){
            case 1: cout<<"�Que cantidad desea ingresar?: "<<endl; cin>>ingreso;
                    v[i].saldo+=ingreso;
                    cout<<"Ingreso exitoso! Su ingreso fue de: "<<ingreso<<endl;
                    cout<<"Su saldo actual es: "<<v[i].saldo<<endl; break;
            case 2: cout<<"�Que cantidad desea ingresar?: "<<endl; cin>>ingreso;
                    v[i].saldo+=ingreso;
                    cout<<"Ingreso exitoso! Su ingreso fue de: "<<ingreso<<endl;
                    cout<<"Su saldo actual es: "<<v[i].saldo<<endl; break;
            case 3: cout<<"�Que cantidad desea ingresar?: "<<endl; cin>>ingreso;
                    v[i].saldo+=ingreso;
                    cout<<"Ingreso exitoso! Su ingreso fue de: "<<ingreso<<endl;
                    cout<<"Su saldo actual es: "<<v[i].saldo<<endl; break;
            case 4: cout<<"�Que cantidad desea ingresar?: "<<endl; cin>>ingreso;
                    v[i].saldo+=ingreso;
                    cout<<"Ingreso exitoso! Su ingreso fue de: "<<ingreso<<endl;
                    cout<<"Su saldo actual es: "<<v[i].saldo<<endl; break;
            case 5: cout<<"�Que cantidad desea ingresar?: "<<endl; cin>>ingreso;
                    v[i].saldo+=ingreso;
                    cout<<"Ingreso exitoso! Su ingreso fue de: "<<ingreso<<endl;
                    cout<<"Su saldo actual es: "<<v[i].saldo<<endl; break;
            default:cout<<"Error!"<<endl; break;

        }
    }

    }while(f!=3);



    return 0;
}
