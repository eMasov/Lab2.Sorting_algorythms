#include <iostream>
#include <vector>
#include<cmath>
#include <chrono>
#include <fstream>
#include "loclib.h"
using namespace std;

int get_Fib_number(int N);
vector<int> Fib_steps(int N);
void Shell_sort(vector<int>& array, vector<int>& step_array, int& perm);

int main(){
std::fstream file;
    file.open("Time_Shell_Fibonacci.csv", std::fstream::out | std::fstream::app);
    file << "N," << "Time (seconds)" << "Permutations" << "\n";
    for (int N = 100000; N <= 10000000; N += 100000){
        vector<int> array;
        random_array(array, N, 1, 2 * N);

        vector<int> steps = Fib_steps(N);
        int perm = 0;

        time_t begin = clock();
        Shell_sort(array, steps, perm);
        double t = (double)(clock() - begin) / CLOCKS_PER_SEC;

        cout << N << endl;
        file << N << "," << t << "," << perm << "\n";
        // сделать запись perm в файл
    }
    file.close();
    return 0;
}

int get_Fib_number(int N){
    int 
        Fib_1 = 1, 
        Fib_2 = 1;
    

    while (Fib_2 <= N){
        int tmp = Fib_2;
        Fib_2 = Fib_1 + Fib_2;
        Fib_1 = Fib_2;
    }
    return Fib_1;
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