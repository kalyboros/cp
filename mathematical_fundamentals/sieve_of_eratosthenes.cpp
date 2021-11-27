//
// Created by kalyb on 27/11/2021.
//

//

#include <iostream>
//#define Nmax 100001

using namespace std;

const int Nmax = 100001;

bool isPrime[Nmax];

void soe(int n){
    for (int i = 2; i <= n ; ++i) {
        isPrime[i] = true;
    }
    for (int i = 2; i <= n/2; ++i) {
        if (!isPrime[i])continue;
        //smart way to iterate through the multipliers of a number
        for (int j = i*2; j <= n ; j += i) {
            isPrime[j] = false;
        }

    }
}

/*
int main() {
    int n = 100;
    soe(100);

    for (int i = 0; i < n; ++i) {
        if (!isPrime[i])continue;
        cout << i << " ";
    }
    
    return 0;
}
*/