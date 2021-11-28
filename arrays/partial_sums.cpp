//
// Created by kalyb on 27/11/2021.
//

#include <iostream>

using namespace std;


void buildPartialSums(int a[], int n, int s[]){

    s[0] = a[0];

    for (int i = 1; i < n; ++i) {
        s[i] = s[i-1] + a[i];
    }
}

int Query(int x, int y, int s[]){
    return s[y]-s[x-1];
}

int main(){
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int s[n];

    buildPartialSums(arr, n, s);

    for (int i = 0; i < n; ++i) {
        cout << s[i] << endl;
    }

    cout<<Query(0,2, s)<<endl;


}