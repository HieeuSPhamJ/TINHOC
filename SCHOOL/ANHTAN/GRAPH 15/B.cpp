#include<bits/stdc++.h>
using namespace std;

const int maxN = 1000010;
int boss[maxN];

int checkBoss(int v){
    if (boss[v] == v){
        return v;
    }
    boss[v] = checkBoss(boss[v]);
    return checkBoss(boss[v]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++){
        boss[i] = i;
    }
    int ans = n;
    for (int i = 1; i <= m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        if (w < k){
            continue;
        }
        if (checkBoss(a) != checkBoss(b)){
            boss[checkBoss(a)] = checkBoss(b);
            ans--;
        }
    }
    cout << ans;
    return 0;
}