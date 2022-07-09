#include <iostream>
#include <math.h>

using namespace std;

double Tolerance=0.001;
double Increment=0.01;

double SenDeXIgualAX(double X){
  double Z = X;
  if(abs(sin(X)-X)>Tolerance){
    SenDeXIgualAX(Z+Increment);
  }
  else{
    return X;
  }
}

int main(){

  double Inters = SenDeXIgualAX(0.2);
  cout<<Inters;

}
