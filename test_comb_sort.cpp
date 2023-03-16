#include <iostream>
#include <vector>
#include "loclib.h"
using namespace std;

void bubble_sort(vector<int>& array, int step);
void comb_sort(vector<int>& array);

int main(){
    srand(time(NULL));
    int N = 10;
    vector<int> array;
    random_array(array, N, 1, 2 * N);

    for (int elem : array){
        cout << elem << "\t";
    }
    cout << endl;

    comb_sort(array);

    for (int elem : array){
        cout << elem << "\t";
    }
    cout << endl;

}

void bubble_sort(vector<int>& values) {
  for (size_t idx_i = 0; idx_i < values.size() - 1; ++idx_i) {
    for (size_t idx_j = 0; idx_j < values.size() - idx_i - 1; ++idx_j) {
      if (values[idx_j + 1] < values[idx_j]) {
        swap(values[idx_j], values[idx_j + 1]);
      }
    }
  }
}

void comb_sort(vector<int>& array){
    for (int step = array.size() - 1; step >= 1; step /= 2){
        for (int i = 0; i < array.size() - step; ++i){
            if (array[i] > array[i + step]){
                Swap(array[i], array[i + step]);
            }
        }
    }
    bubble_sort(array);
}