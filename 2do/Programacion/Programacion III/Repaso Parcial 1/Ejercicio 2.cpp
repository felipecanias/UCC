#include <iostream>
using namespace std;

void rango(int n) {
    if(n==1) cout<<"1"<<endl;
    else if((n%2)==1){
        cout<<n<<endl;
        rango(n-1);
    }
    else rango(n-1);
  }

int main() {
    int x=0;
    cout<<"Ingrese el valor de n; ";cin>>x;
    rango(x-1);
  return 0;
}
