//
// Created by kalyb on 28/11/2021.
//

#include "iostream"

using namespace std;


//define indexes as 0 when input
void update(int x, int y, int val, int b[]){
    b[x] += val;
    b[y+1] -= val;
    //O(n) per query update
}

void buildFinalArray(int s[], int b[], int a[], int n){
/*
    for (int i = 1; i <= n; ++i) {
        s[i] = s[i-1] + b[i];
        a[i] += s[i];
    }
*/
    for (int i = 0; i < n; ++i) {

        if(i == 0){
            s[i] = b[i];
            a[i] += s[i];
        } else{
            s[i] = s[i-1] + b[i];
            a[i] += s[i];
        }

    }

}

void makeZeros(int s[], int b[], int n){
    for (int i = 0; i < n; ++i) {
        s[i] = 0;
        b[i] = 0;
    }
}

//this should only be used when you have all the updates at the beginning of task
int main(){
    int nmax = 5;
    int a[] = {1,2,3,4,5};

    int b[nmax];
    int s[nmax];

    makeZeros(s, b, nmax);

    update(0,5,-5, b);

    update(2,3,6, b);

    buildFinalArray(s,b,a,nmax);

    for (int i = 0; i < nmax; ++i) {
        cout << a[i] << endl;
    }

    return 0;
}


