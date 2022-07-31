#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
using namespace std;

const int maxN = 2 * 1e5 + 10;

int a[maxN];
int ans[maxN];
int prefix[maxN];
vector <ii> adj[maxN];
vector <int> preNode;

void getLen(int node, int father){
    for (auto newNode: adj[node]){
        if (newNode.se == father){
            continue;
        }
        prefix[newNode.se] = prefix[node] + newNode.fi;
        getLen(newNode.se, node);
    }
}

void DFS(int node, int father){
    for (auto newNode: adj[node]){
        if (newNode.se == father){
            continue;
        }
        
        DFS(newNode.se, node);
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    for (int i = 1; i < n; i++){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({w,b});
        adj[b].push_back({w,a});
    }

    getLen(1,1);
    preNode.push_back(1);
    DFS(1,1);

    for (int i = 1; i <= n; i++){
        cout << prefix[i] << ' ';
    }

    return 0;
}