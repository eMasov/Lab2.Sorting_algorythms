#include <iostream>
#include <vector>
#include "loclib.h"
using namespace std;

void forward_step(vector<int>& array, int left_idx, int right_idx);
void backward_step(vector<int>& array, int left_idx, int right_idx);
void shaker_sort(vector<int>& array, unsigned begin_idx, unsigned end_idx);

int main(){
    srand(time(NULL));
    int N = 10;
    vector<int> array;
    random_array(array, N, 1, 2 * N);

    for (int elem : array){
        cout << elem << "\t";
    }
    cout << endl;

    shaker_sort(array, 0, N - 1);

    for (int elem : array){
        cout << elem << "\t";
    }
    cout << endl;

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