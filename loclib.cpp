#include "loclib.h"
#include <ctime>
#include <cstdlib>

int randomizer(int left, int right){
    int num = left + rand()%(right - left + 1);
    return num;
}

void random_array(std::vector<int>& vect, int N, int m, int M){
    vect.clear();
    for (int i = 0; i < N; ++i){
        vect.push_back(randomizer(m, M));
    }
}

void Swap(int& a, int& b){
    auto tmp = a;
    a = b;
    b = tmp;
}