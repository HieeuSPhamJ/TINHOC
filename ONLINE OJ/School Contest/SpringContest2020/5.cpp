#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;

int a[maxN];
int rootSum = 0;
int child[maxN];
int father[maxN];
int ans[maxN];
vector <int> adj[maxN];

void init(int node, int Father){
    child[node] = 1;
    for (auto newNode: adj[node]){
        if (newNode == Father){
            continue;
        }

        init(newNode, node);
        child[node] += child[newNode];
        ans[node] += ans[newNode];
    }
    ans[node] += a[node] * child[node];
}

void DFS(int node, int Father){
    for (auto newNode: adj[node]){
        if (newNode == Father){
            continue;
        }
        ans[newNode] = ans[node] + a[newNode] * father[newNode] - a[node] * child[newNode];
        DFS(newNode, node);
        
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            adj[i].clear();
            ans[i] = 0;
        }

        for (int i = 1; i < n; i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
            // cout << a << " " << b << endl;
        }
        init(1,1);
        for (int i = 1; i <= n; i++){
            father[i] = n - child[i];
            // cout << i << ": " << child[i] << ", " << father[i] << ", " << ans[i] << endl;

        }

        DFS(1,1);

        for (int i = 1; i <= n; i++){
            cout << ans[i] - a[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}