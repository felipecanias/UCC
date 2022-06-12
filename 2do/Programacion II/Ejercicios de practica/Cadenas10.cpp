#include<iostream>
#include<conio.h>
#include<string.h>

using namespace std;

int main(){
    char fr1[100];
    int conteoa=0, conteoe=0, conteoi=0, conteoo=0, conteou=0;

    cout<<"\nDigite la frase: "<<endl;
    cin.getline(fr1,30,'\n');
    strlwr(fr1);
    for(int i = 0; i<30; i++){
            switch(fr1[i]){
                           case 'a': conteoa++;break;
                           case 'e': conteoe++;break;
                           case 'i': conteoi++;break;
                           case 'o': conteoo++;break;
                           case 'u': conteou++;break;
            }
    }
    cout<<"\nLa cantidad de 'a' en la frase es: "<<conteoa<<endl;
    cout<<"\nLa cantidad de 'e' en la frase es: "<<conteoe<<endl;
    cout<<"\nLa cantidad de 'i' en la frase es: "<<conteoi<<endl;
    cout<<"\nLa cantidad de 'o' en la frase es: "<<conteoo<<endl;
    cout<<"\nLa cantidad de 'u' en la frase es: "<<conteou<<endl;
    getch();
    return 0;
}
