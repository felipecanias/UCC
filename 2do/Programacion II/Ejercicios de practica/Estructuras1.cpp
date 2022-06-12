#include <iostream>
#include <time.h>

using namespace std;

struct empleado{
char nombre[30];
float salario;
}emp[100];

int main ()
{   int i,n,j=0,t=0;
    float mayor=0, menor=1000000;

    cout<<"Ingrese cantidad de empleados: "; cin>>n;

    for(i=0;i<n;i++){
        fflush(stdin);
        cout<<"Ingrese nombre de empleado: "<<endl; cin.getline(emp[i].nombre,30,'\n');
        cout<<"Ingrese salario: "<<endl; cin>>emp[i].salario;
    }

    for(i=0;i<n;i++){
        if(mayor < emp[i].salario){
            mayor= emp[i].salario;
        }
    }
    for(i=0;i<n;i++){
        if(menor > emp[i].salario){
            menor= emp[i].salario;
        }
    }

    for(i=0;i<n;i++){
        cout<<"Nombre del empleado: "<<emp[i].nombre<<endl;
        cout<<"Salario del empleado: "<<emp[i].salario<<endl;
    }

    for(i=0;i<n;i++){
        if(emp[i].salario==mayor){
            cout<<"El empleado con mayor salario es: "<<emp[i].nombre<<endl;
        }
    }

    for(i=0;i<n;i++){
        if(emp[i].salario==menor){
            cout<<"El empleado con menor salario es: "<<emp[i].nombre<<endl;
        }
    }
    return 0;
}
