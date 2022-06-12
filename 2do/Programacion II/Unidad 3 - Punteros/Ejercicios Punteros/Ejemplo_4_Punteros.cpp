#include <iostream>

using namespace std;

int main(){

    int x, y, *p, *q;
    p = &x;
    *p = 14;
    q = p; //q apunta a &x

    if(p == q){
        cout<<"Mensaje1"; // se muestra este mensaje
        q=&y;}
    if(p == q){
        cout<<"Mensaje2";
        *q=14;}
    if(p == q){
        cout<<"Mensaje3";}
    if(*p == *q){
        cout<<"Mensaje4";
    }



    return 0;
}
