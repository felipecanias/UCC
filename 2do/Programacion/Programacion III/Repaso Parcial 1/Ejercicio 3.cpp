#include <iostream>
using namespace std;

void asteriscos(int n){
  if (n == 1) cout << "*";
 else {
   cout << "*";
   asteriscos(n - 1);
 }
}

int main() {
    int x=0;
    cout<<"Ingrese el valor de n: ";cin>>x;
    asteriscos(x);
  return 0;
}
