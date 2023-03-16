#include <iostream>
#include <vector>
using namespace std;

void Swap(int& a, int& b);
void iter(vector<int>& array, unsigned const begin, int step);
void Shell_sort(vector<int>& array, vector<int>& step_array);

int main(){
    return 0;
}

void Swap(int& a, int& b){
    auto tmp = a;
    a = b;
    b = tmp;
}

void iter(vector<int>& array, unsigned const begin, int step){
    for (int i = begin; i <= array.size() - 1 - step; i += step){
        if (array[i] < array[i - 1]){
            Swap(array[i], array[i + 1]);
        }
    }
}

void Shell_sort(vector<int>& array, vector<int>& step_array){
    for (int step : step_array){
        for (int k = 0; k < step; ++k){
            iter(array, k, step);
        }
    }
}