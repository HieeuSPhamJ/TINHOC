#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
using namespace std;

const int maxN = 2 * 1e5 + 10;
const int mod = 1e9 + 7;

int n, m;
vector <int> adj[maxN];
int f[3][maxN];
int val[maxN];
vector <ii> lists;

void DFS(int v,int father){
    int temp[3] = {0};
    int check = 0;
    vector <ii> lists;
    for (auto newV: adj[v]){
        if (newV != father){
            DFS(newV, v);
            temp[1] = (f[1][newV] + f[0][newV]) % mod;
            temp[0] = f[1][newV] % mod;
            lists.push_back({temp[0], temp[1]});
            check = 1;
        }
    }

    temp[0] = 1;
    temp[1] = 1;

    for (auto i: lists){
        (temp[0] *= i.fi) %= mod;
        (temp[1] *= i.se) %= mod;
    }


    if (check == 1){
        f[0][v] = temp[0];
        f[1][v] = temp[1];
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a); 
    }
    for (int i = 1; i <= 2 * n; i++){
        f[1][i] = 1;
        f[0][i] = 1;
    }

    DFS(1, 1);
    cout << (f[0][1] + f[1][1]) % mod << endl;
    // cout << f[0][1] << ' ' << f[1][1];
    // for (int i = 1; i <= n; i++){
    //     cout << i << endl;
    //     cout << f[0][i] << ' ' << f[1][i] << endl;
    // }

    return 0;
}       