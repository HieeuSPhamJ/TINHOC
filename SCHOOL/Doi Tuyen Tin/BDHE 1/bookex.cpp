#include<bits/stdc++.h>
// #define int long long
#define ii pair <int,int>
#define f first
#define s second
using namespace std;

const int maxN = 1e6 + 10;

int boss[maxN];
int sizeCom[maxN];

int findBoss(int v){
    if (boss[v]==v){
        return v;
    }
    else return (boss[v]=findBoss(boss[v]));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++){
        sizeCom[i] = 1;
        boss[i] = i;
    }

    for (int i = 1; i <= n; i++){
        int b;
        cin >> b;
        int u = findBoss(i);
        int v = findBoss(b);
        if (u == v){
            continue;
        }
        else{
            boss[v] = u;
            sizeCom[u] += sizeCom[v];
        }
    }

    for (int i = 1; i <= n; i++){
        cout << sizeCom[findBoss(i)] << ' ';
    }

    return 0;
}