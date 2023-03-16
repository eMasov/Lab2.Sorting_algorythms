#include <iostream>
#include <vector>
#include <cmath>
#include "loclib.h"
using namespace std;

vector<int> Fib_steps(int N);
void shell_sort(vector<int>& array, vector<int>& steps);

int main(){
    srand(time(NULL));
    vector<int> array;
    int N = 10;
    random_array(array, N, 1, 2 * N);

    vector<int> steps = Fib_steps(N);
    int permutation = 0;

    for (int elem : array){
        cout << elem << "\t";
    }
    cout << endl;

    shell_sort(array, steps, permutation);

    for (int elem : array){
        cout << elem << "\t";
    }
    cout << endl;
    cout << "Permutations = " << permutation << endl;
}

vector<int> Fib_steps(int N){
    vector<int> array;
    vector<int> step_array;
    int 
        Fib_1 = 1, 
        Fib_2 = 1;
    
    while (Fib_2 <= N){
        array.push_back(Fib_2);
        int tmp = Fib_2;
        Fib_2 = Fib_1 + Fib_2;
        Fib_1 = tmp;
    }

    for (int i = array.size() - 1; i >=0; --i){
        step_array.push_back(array[i]);
    }
    step_array.push_back(1);
    return step_array;
}

void shell_sort(vector<int>& array, vector<int>& steps, int& permutation) {
    int size = array.size();
    for (int step : steps){
        for (int i = step; i < size; ++i){
            for (int j = i - step; j >= 0 && array[j] > array[j + step]; j -= step){
                Swap(array[j], array[j + step]);
                ++permutation;
            }
        }
    }
}