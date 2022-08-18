#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int c;
    cin >> c;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    vector <ii>

    int test;
    cin >> test;
    while(test--){
        int node, color;
        cin >> node >> color;

    }
    return 0;
}