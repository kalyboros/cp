//
// Created by kalyb on 27/11/2021.
//

#include <iostream>

using namespace std;

//recursive
int fastExpoRec(int a, long long n, int MOD){

    //exit point
    if (n == 0){
        return 1;
    }
    // (a^n) % MOD

    if(n % 2 == 0){
        // a^n = ((a ^ 2) ^ (n/2))
        return fastExpoRec((1LL * a * a) % MOD, n/2, MOD);
    }
    // a^n = a * (a ^ (n-1))
    return (1LL * a * fastExpoRec(a, n-1, MOD)) % MOD;


}

int fastExpoIt(int a, long long n, int MOD){
    int ans = 1;

    while(n >= 1){

        //if n is an even number
        if(n % 2 == 0) {
            a = (1LL * a * a) % MOD;
            n /= 2;
        }

        //if n is an odd number
        else {
            ans = (1LL * ans * a) % MOD;
            n--;
        }


    }
    return ans;
}
/*
int main(){

    int a = 5;
    int n = 13;
    int MOD = 1000000007;

    cout << fastExpoRec(a,n,MOD);

    cout << endl;

    cout << fastExpoIt(a,n,MOD);

    return 0;
}
*/
