#include <iostream>
using namespace std;
 
int main() {
   int *x;
   int y = 100;

   x = new int[y];
   x[10] = 0;
   cout << "Valor: " << x[10] << endl;
   delete[] x;

   return 0;
}
