#include <iostream>

using namespace std;

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
