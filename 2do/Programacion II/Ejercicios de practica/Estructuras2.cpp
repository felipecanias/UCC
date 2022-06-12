#include <iostream>
#include <time.h>

using namespace std;

struct promedio{
float nota1;
float nota2;
float nota3;
};

struct alumno{
char nombre[30];
char sexo[10];
int edad;
struct promedio prom;
}alumno1;

int main ()
{   float p;

    cout<<"Ingrese nombre del alumno: "; cin.getline(alumno1.nombre,30,'\n');
    cout<<"Ingrese sexo del alumno: ";  cin.getline(alumno1.sexo,10,'\n');
    cout<<"Ingrese edad del alumno: ";  cin>>alumno1.edad;
    cout<<"Ingrese nota 1 del alumno: "; cin>>alumno1.prom.nota1;
    cout<<"Ingrese nota 2 del alumno: "; cin>>alumno1.prom.nota2;
    cout<<"Ingrese nota 3 del alumno: "; cin>>alumno1.prom.nota3;

    p=(alumno1.prom.nota1+alumno1.prom.nota2+alumno1.prom.nota3)/3;
    cout<<"------------------------"<<endl;
    cout<<"Nombre: "<<alumno1.nombre<<endl;
    cout<<"Sexo: "<<alumno1.sexo<<endl;
    cout<<"Edad: "<<alumno1.edad<<endl;
    cout<<"Promedio: "<<p<<endl;


    return 0;
}
