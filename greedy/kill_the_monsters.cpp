//
// Created by kalyb on 04/12/2021.
//
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int killMonster(int hp, int K, vector<int>dmg){

    //we will be saving all the kills we make in pq, so when later our hp drops below
    //0 we can comeback and make a decision where we should use a potion to regain hp
    priority_queue<int>kills;

    for (int i = 0; i < dmg.size(); i++) {
        cout << "iteration:" << i << endl;
        if (dmg[i] <= 0){
            //we can gain hp by fighting a monster that has neg attack
            hp+=-dmg[i];
            cout << "gaining:" << dmg[i] << endl;
            continue;
        }

        //else we just normally fight a monster
        hp-=dmg[i];
        kills.push(dmg[i]);
        cout << "losing:" << dmg[i] << endl;
        cout << "hp status:" << hp << endl;


        //after fighting we have to check if our hp is below 0
        //to keep fighting we still need available potions and kills queue has to be populated

        while (hp <= 0 && K > 0 && kills.empty() == false){
            cout << "doing stuff about my neg health" << endl;

            int kill = kills.top();
            kills.pop();
            hp+=kill;
            K--;
        }

        //if we didnt get our hp in surplus, we stop fighting at the current monster
        if(hp < 0) return i;
        //if we can still overcome this current monster, we can get to next one and then lose
        if(hp == 0) return i+1;

    }

    //we can fight them all
    return dmg.size();

}

int main(){
    cout<<"kill the monster\n";

    //hp is how much hp we have, K is number of potions, vector damage is how much damage we take when fighting a mosnter
    vector<int>dmg = {-3, 2, 3, -2, 8, 8, 6, 4, 3, 3};
    int k = 2;
    int hp = 10;

    cout<<killMonster(hp, k, dmg);



}
