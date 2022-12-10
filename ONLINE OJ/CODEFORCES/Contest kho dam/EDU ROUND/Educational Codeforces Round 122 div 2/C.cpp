#include<bits/stdc++.h>
using namespace std;

struct Stat{
    long long health;
    long long dmg;
    long long healthBoost;
    long long dmgBoost;

};


bool checkWon(Stat player, Stat enemy){
    long long enemyTurn = enemy.health / player.dmg + (enemy.health % player.dmg != 0);
    long long playerTurn = player.health / enemy.dmg + (player.health % enemy.dmg != 0);
    if (playerTurn >= enemyTurn){
        return 1;
    }
    return 0;

}


void printStat(Stat target){
    // cout << "#Stat" << endl << target.health << ' ' << target.dmg << endl;

}


int main(){
    int test;
    cin >> test;
    while(test--){
        Stat enemy, player;
        long long k;
        cin >> player.health >> player.dmg;
        cin >> enemy.health >> enemy.dmg;
        cin >> k >> player.dmgBoost >> player.healthBoost;
        player.health += k * player.healthBoost;
        int ans = 0;
        printStat(player);
        printStat(enemy);
        if (checkWon(player, enemy) == 1){
            ans = 1;
        }
        for (int i = 1; i <= k; i++){
            player.dmg += player.dmgBoost;
            player.health -= player.healthBoost;
            // cout << "----" << endl;
            printStat(player);
            printStat(enemy);
            if (checkWon(player, enemy) == 1){
                ans = 1;
                break;
            }
        }
        // cout << "+=========+" << endl;
        if (ans == 1){
            cout << "YES";
        }
        else{
            cout << "NO";
        }
        cout << endl;


    }

    return 0;
}