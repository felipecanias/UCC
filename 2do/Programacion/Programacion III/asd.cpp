#include <iostream>

using namespace std;

int *MultiplyArrayByTwo(int arr[], int size) {
  for (int i = 0; i < size; ++i) {
    arr[i] = 1;
  }
  return arr;
}

int main() {
  constexpr int size = 10;
  int c_array[size];

  int *ptr = MultiplyArrayByTwo(c_array, size);

  cout << "array = [ ";
  for (int i = 0; i < size; ++i) {
    cout << ptr[i] << ", ";
  }
  cout << "]" << endl;

  return EXIT_SUCCESS;
}
