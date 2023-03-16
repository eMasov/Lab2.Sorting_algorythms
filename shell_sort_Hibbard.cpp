#include <iostream>
#include <vector>
#include<cmath>
#include <chrono>
#include <fstream>
#include "loclib.h"
using namespace std;

vector<int> Hibbard_steps(int N);
void Shell_sort(vector<int>& array, vector<int>& step_array, int& perm);

int main(){
    std::fstream file;
    file.open("Shell_time_Hibbard.csv", std::fstream::out | std::fstream::app);
    file << "N," << "Time (seconds)" << "Permutations" << "\n";
    for (int N = 100000; N <= 10000000; N += 100000){
        vector<int> array;
        random_array(array, N, 1, 2 * N);

        vector<int> steps = Hibbard_steps(N);
        int perm = 0;

        time_t begin = clock();
        Shell_sort(array, steps, perm);
        double t = (double)(clock() - begin) / CLOCKS_PER_SEC;

        cout << N << endl;
        file << N << "," << t << "," << perm << "\n";
    }
    file.close();
    return 0;
}

vector<int> Hibbard_steps(int N){
    vector<int> step_array;
    for (int i = floor(log2(N + 1)); i >= 1; --i){
        step_array.push_back(pow(2, i) - 1);
    }
    return step_array;
}

void Shell_sort(vector<int>& array, vector<int>& steps, int& perm) {
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