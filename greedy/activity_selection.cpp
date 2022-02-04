//
// Created by kalyb on 28/11/2021.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Activity {
    int start, finish;

    // Constructor
    Activity(int start, int finish)
            : start(start), finish(finish)
    {
    }
};
//this compares
bool cmp(struct Activity a, struct Activity b)
{
    //we sort by finish value
    int r1 = a.finish;
    int r2 = b.finish;

    //invert this if you need ascending order
    return r1 < r2;
}


int findNumber(struct Activity arr[], int size){
    int ans = 0;
    int currFinish = 0;

    //we gotta sort them first
    sort(arr, arr + size, cmp);

    for(int i = 0; i < size; i++){
        //cout << arr[i].start << " - " <<arr[i].finish << endl;

        if(currFinish < arr[i].start){
            ans++;
            currFinish = arr[i].finish;
        }
    }


    return ans;
}
/*
int main(){

    //We have an array of activies paired with start and finish, we have to find
    //the number of maximum activites a person can do in this interval
    //basically we find to take as many sub arrays in an interval as possible, but they mustn't cover each other
    //because one person can only do one activity at the time and they are consecutive


    Activity arr[] = { { 1, 2 },
                   { 3, 4 },
                   { 5, 7 },
                   { 8, 9 },
                   { 0, 6 },
                   { 5, 9 } };

    int size = sizeof(arr) / sizeof(arr[0]);

    // Function Call
    cout << "Number of tasks = "
         << findNumber(arr, size);
    return 0;

}
*/
