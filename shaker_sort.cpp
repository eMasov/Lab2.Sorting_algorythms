#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>
#include "loclib.h"
using namespace std;

void forward_step(vector<int>& array, int left_idx, int right_idx);
void backward_step(vector<int>& array, int left_idx, int right_idx);
void shaker_sort(vector<int>& array, unsigned begin_idx, unsigned end_idx);

int main(){
    srand(time(NULL));
    std::fstream file;
    file.open("shaker_time.csv", std::fstream::out | std::fstream::app);
    file << "N," << "Time (seconds)" << "\n";
    for (int N = 10000; N <= 300000; N += 10000){
        vector<int> array;
        random_array(array, N, 1, 2 * N);

        time_t begin = clock();
        shaker_sort(array, 0, N - 1);
        double t = (double)(clock() - begin) / CLOCKS_PER_SEC;

        file << N << "," << t << "\n";
        cout << N << endl;
    }
    file.close();
    return 0;
}

void forward_step(vector<int>& array, int left_idx, int right_idx){
    for (int i = right_idx; i >= left_idx; i--){
        if (array[i] < array[i - 1]){
            Swap(array[i - 1], array[i]);
        }
    }
}

void backward_step(vector<int>& array, int left_idx, int right_idx){
    for (int i = left_idx; i <= right_idx; i++){
        if (array[i] < array[i - 1]){
            Swap(array[i - 1], array[i]);
        }
    }
}

void shaker_sort(vector<int>& array, unsigned left_idx, unsigned right_idx){
    while (right_idx > left_idx){
        forward_step(array, left_idx, right_idx);
        ++left_idx;
        backward_step(array, left_idx, right_idx);
        --right_idx;
    }
}