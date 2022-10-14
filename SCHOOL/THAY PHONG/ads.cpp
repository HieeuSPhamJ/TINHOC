#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int father[2010];

int findFather(int node){
    if (father[node] == node){
        return node;
    }
    return findFather(father[node]);
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        father[i] = i; 
    }
    int M = m;
    for (int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        int u = findFather(a);
        int v = findFather(b);
        if (u == v){
            continue;
        }
        father[u] = v;
        M--;
    }

    cout << M;
    return 0;
}