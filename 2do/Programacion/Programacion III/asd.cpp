#include <iostream>

using namespace std;


int main() {

  int arr[5];

  for(int i=0 ;i<5; i++){
    arr[i]=i;
  }
  for (int i = 0; i < 6; i++) {
    cout<<arr[i]<<endl;
  }
  return 0;
}
