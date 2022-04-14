#include<bits/stdc++.h>
using namespace std;

const int maxN = 100010;

int boss[maxN];

int checkBoss(int n){
    if (n == boss[n]){
        return n;
    }
    return boss[n] = checkBoss(boss[n]);
}

int main(){
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++){
            int a, b, w;
            cin >> a >> b >> w;
            if (w and checkBoss(a) != checkBoss(b)){
                boss[checkBoss(a)] = checkBoss(b);
            
            }
        }
        cout << endl;
    }
}