#include <iostream>

using namespace std;

int main ()
{
    int i, c, v[100],minimo,maximo,cont=0;
    double media, dist, total=0, rango;

    cout<<"Cantidad de valores: ";
    cin>>c;

    for(i=0; i<c;i++){
         cout<<"Ingrese el valor para la posicion: "<< i+1 <<endl;
         cin>>v[i];
         total+=v[i];
    }

    media= total/c;

    cout<<"La media del conjunto es: "<<media<<endl;

    for(i=0;i<c;i++){

        dist=media-v[i];
        cout<<"La distancia con la media es: "<<dist<<" para el valor "<<i+1<<endl;

    }

    for(i=0;i<c;i++){
        if(v[i]<media){
          minimo=v[i];
          media=v[i];
        }
    }
    for(i=0;i<c;i++){
        if(v[i]>media){
          maximo=v[i];
          media=v[i];
        }
    }

    cout<<"El minimo es: "<<minimo<<endl;
    cout<<"El maximo es: "<<maximo<<endl;

    rango=maximo-minimo;
    cout<<"El rango del conjunto es: "<<rango<<endl;

    media= total/c;

    for(i=0;i<c;i++){
        if(v[i]<=(media+2) && v[i]>=(media-2)){
            cont+=1;
        }

    }

    cout<<"La cant. de valores con una distancia menor a 2 a la media son: "<<cont;

    return 0;
}
