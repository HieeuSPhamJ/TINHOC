#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;


int root[100000];

int findRoot(int n){
    if (n == root[n]){
        return n;
    }
    return root[n] = findRoot(root[n]);
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, test;
    cin >> n >> test;
    for (int i = 1; i <= n; i++){
        root[i] = i;
    }
    for (int i = 2; i <= n; i++){
        int a, k;
        cin >> a >> k;
        if (k == 2){
            continue;
        }
        int u = findRoot(i);
        int v = findRoot(a);
        if (v == u){
            continue;
        }
        root[u] = v;
    }
    while (test--){
        int a, b;
        cin >> a >> b;
        int u = findRoot(a);
        int v = findRoot(b);
        if (u == v){
            cout << "NO";
        }
        else{
            cout << "YES";
        }
        cout << endl;
    }
    return 0;
}