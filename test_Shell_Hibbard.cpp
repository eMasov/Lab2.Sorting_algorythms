#include <iostream>
#include <vector>
#include <cmath>
#include "loclib.h"
using namespace std;

vector<int> Hibbard_steps(int N);
void shell_sort(vector<int>& array, vector<int>& steps, int& perm);

int main(){
    srand(time(NULL));
    vector<int> array;
    int N = 10;
    random_array(array, N, 1, 2 * N);

    vector<int> steps = Hibbard_steps(N);
    int perm = 0;
    for (int elem : array){
        cout << elem << "\t";
    }
    cout << endl;

    shell_sort(array, steps, perm);

    for (int elem : array){
        cout << elem << "\t";
    }
    cout << endl;
    cout << "Permutations = " << perm << endl;
}

vector<int> Hibbard_steps(int N){
    vector<int> step_array;
    for (int i = floor(log2(N + 1)); i >= 1; --i){
        step_array.push_back(pow(2, i) - 1);
    }
    return step_array;
}

void shell_sort(vector<int>& array, vector<int>& steps, int& perm) {
    int size = array.size();
    for (int step : steps){
        for (int i = step; i < size; ++i){
            for (int j = i - step; j >= 0 && array[j] > array[j + step]; j -= step){
                Swap(array[j], array[j + step]);
                ++perm;
            }
        }
    }
}