#include <iostream>
#include <time.h>

using namespace std;

int main ()
{
    char l1[]= {'a','b','c','d','e'};
    char l2[]= {'f','g','h','i','j'};
    char l3[10];
    int i;

    for(i=0;i<5;i++){
        l3[i]=l1[i];
    }

    for(i=5;i<10;i++){
        l3[i]=l2[i-5];
    }

    for(i=0;i<10;i++){
       cout<<l3[i]<<endl;
    }



    return 0;
}
