#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 2 * 1e5 + 10;

int lvl[maxN];
int n, m;
int a[maxN];
vector <int> adj[maxN];
int res;

void DFS(int node, int father){
    for (auto newNode: adj[node]){
        if (newNode == father){
            continue;
        }
        DFS(newNode, node);
        lvl[newNode] = lvl[node] + 1;
    }
}


signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n;
    for (int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    DFS(1,1);
    cin >> m;
    for (int i = 1; i <= m; i++){
        cin >> a[i];
    }

    int ans = a[1];
    for (int i = 1; i <= m; i++){
        if (lvl[ans] > lvl[a[i]]){
            ans = a[i];
        }
        else if (lvl[ans] == lvl[a[i]]){
            ans = min(ans,a[i]);
        }
    }
    cout << ans;

    return 0;
}