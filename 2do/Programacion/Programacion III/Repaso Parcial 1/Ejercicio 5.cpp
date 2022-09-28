#include "Cola.h"
#include <iostream>
using namespace std;

int main() {
  Cola<int> C;

  try {
    C.encolar(1);
    C.encolar(2);
    C.encolar(3);
    C.encolar(4);
    C.encolar(5);
    C.Moveralfinal(1);
  } catch (int x) {
    cout << "Error" << endl;
  }


    cout << C.desencolar() << endl;
    cout << C.desencolar() << endl;
    cout << C.desencolar() << endl;
    cout << C.desencolar() << endl;
    cout << C.desencolar() << endl;
    
    
  return 0;
}
