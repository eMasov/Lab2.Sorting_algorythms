#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>
#include "loclib.h"
using namespace std;

void bubble_sort(vector<int>& array, int step);
void comb_sort(vector<int>& array);

int main(){
    srand(time(NULL));
    std::fstream file;
    file.open("comb_time.csv", std::fstream::out | std::fstream::app);
    file << "N," << "Time (seconds)" << "\n";
    for (int N = 10000; N <= 300000; N += 10000){
        vector<int> array;
        random_array(array, N, 1, 2 * N);

        time_t begin = clock();
        comb_sort(array);
        double t = (double)(clock() - begin) / CLOCKS_PER_SEC;

        file << N << "," << t << "\n";
        cout << N << endl;
    }
    file.close();
    return 0;
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
        for (long unsigned int i = 0; i < array.size() - step; ++i){
            if (array[i] > array[i + step]){
                Swap(array[i], array[i + step]);
            }
        }
    }
    bubble_sort(array);
}