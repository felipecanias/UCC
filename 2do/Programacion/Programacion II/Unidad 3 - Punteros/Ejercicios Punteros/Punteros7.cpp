#include <iostream>

using namespace std;

int main(){

int x1 = 50;
int x2 = 100;
int *pun1, *pun2;
pun1 = &x1; //pun1 apunta a la direccion de x1, *pun1=50
pun2 = pun1; // pun2 apunta en la misma direccion que pun1
*pun1 = 2000; // el valor de x1=2000
pun2 = &x2; // pun2 apunta a la direccion de x2, *pun2=100
x1 = 1; // *pun1=1
x2 = 2; // *pun2=2
*pun1 = 500; // x1=500
*pun2 = 600; //x2=600

return 0;
}
