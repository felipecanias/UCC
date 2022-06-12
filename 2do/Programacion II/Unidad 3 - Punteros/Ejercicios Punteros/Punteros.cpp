#include <iostream>

using namespace std;

int Ej1(){
    //Ejercicio 1

    int *p,a;

    p=&a;

    cout<<p;

}

int Ej2(){
    //Ejercicio 2

    int *p,z;

    p=&z;
    *p=10;

    cout<<z;
}

int Ej3(){
    //Ejercicio 3
    int *p,z;

    p=&z;
    *p=10;

    cout<<*p<<endl;
    // Si se puede imprimir
}

int Ej4(){
    //Ejercicio 4
    int *p,z;
    float *q,t;

    p=&z;
    q=&t;
    *p=10;
    *q=15;

    cout<<*p<<endl;
    cout<<*q<<endl;
}

int Ej5(){
    //Ejercicio 5
    int a = 501;
    int *p; //Variable | Direccion | Valor
    p = &a; //       p |    1000   | *p=501
    *p = 5; //       a |    1000   | a=5
}

int Ej6(){
    //Ejercicio 6
    int *p,z;
    float *q,t;
            //Variable | Direccion | Valor
    p=&z; //    p      |    1000   | *p=z
    q=&t; //    q      |    1001   | *q=t
    *p=10; //   z      |    1000   | z=10
    *q=15; //   t      |    1001   | t=15

    cout<<*p<<endl;
    cout<<*q<<endl;
}

int Ej7(){
    // Ejercicio 7

    int x1 = 50;
    int x2 = 100;
    int *pun1, *pun2;
                // Variable| Direccion | Valor
    pun1 = &x1; //  pun1   |    1000   |*pun1=50
    pun2 = pun1; // pun2   |    1000   |*pun2=50
    *pun1 = 2000; //  x1   |    1000   | x1=2000
    pun2 = &x2; // pun2    |    1001   |*pun2=100
    x1 = 1; //     pun1    |    1000   | *pun1=1
    x2 = 2; //     pun2    |    1001   |*pun2=2
    *pun1 = 500; //   x1   |    1000   | x1=500
    *pun2 = 600; //   x2   |    1001   | x2=600
}

int Ej8(){
    //Ejercicio 8

    int x=5,y=10,z=15;
    int *p;

    p=&x;
    cout<<*p<<endl;
    p=&y;
    cout<<*p<<endl;
    p=&z;
    cout<<*p<<endl;
}

int Ej9(){
    //Ejercicio 9
    float x,y;
    float *p;

    p=&x;
    *p=10;
    p=&y;
    *p=20;
    cout<<x<<endl;
    cout<<y<<endl;
}

int Ej10(){
    //Ejercicio 10

int f1(a){
a++
return a;
}

int f2(&a){
a++
return a;
}
}

int Ej11(){
    //Ejercicio 11

    int m[3][3]= {{2,5,4},{1,3,8},{7,9,10}};
    int menor =m[1][1];
    int i,j,t,k;
    int *f,*c;
    void f1(int,int);

int main(){

    f=&t;
    c=&k;
    f1(*f,*c);
    cout<<*f<<*c;
}

 void f1(int t,int k){
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                if (menor > m[i][j]){
                    menor = m[i][j];
                    *f=i+1;
                    *c=j+1;
                }
            }
        }
    }

}

int Ej12(){
    //Ejercicio 12
    char A[]={'h','o','l','a'};
    int i,j;
    char *f;

    f = A;

    cout<<*f;
    f++;
    cout<<*f;
    f++;
    cout<<*f;
    f++;
    cout<<*f;
}

int Ej13(){
    //Ejercicio 13
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
int main(){

return 0
}
