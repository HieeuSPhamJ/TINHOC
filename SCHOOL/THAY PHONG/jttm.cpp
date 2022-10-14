#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int root[100010];
int com[100010];

int findRoot(int n){
    if (n == root[n]){
        return n;
    }
    return root[n] = findRoot(root[n]);
}

int nC2(int n){
    return (n * (n - 1)) / 2;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= n; i++){
        root[i] = i;
        com[i] = 1;
    }
    for (int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        int u = findRoot(a);
        int v = findRoot(b);
        if (v == u){
            continue;
        }
        root[u] = v;
        com[v] += com[u];
    }
    set <int> mySet;
    for (int i = 0; i < n; i++){
        mySet.insert(findRoot(i));
    }

    int ans = nC2(n);

    for (auto i: mySet){
        // cout << i << ": " << com[i] << endl;
        ans -= nC2(com[i]);
    }
    cout << ans;
    return 0;
}