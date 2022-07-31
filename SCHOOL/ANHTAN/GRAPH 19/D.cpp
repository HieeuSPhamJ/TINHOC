#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
using namespace std;

const int maxN = 2 * 1e5 + 10;

int n, m;
vector <int> adj[maxN];
int f[maxN];
int val[maxN];
vector <ii> lists;

void DFS(int v,int father){
    if (adj[v].size() <= 1){
        f[v] = 0;
    }
    vector <int> tempList;
    for (auto newV: adj[v]){
        if (newV != father){
            DFS(newV, v);
            tempList.push_back(f[newV] + 1);
        }
    }
    sort(tempList.rbegin(), tempList.rend());
    for (int i = 0; i < tempList.size(); i++){
        int temp = tempList[i];
        f[v] = max(f[v], temp + i);
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a); 
    }

    DFS(m, m);
    cout << f[m];

    return 0;
}       