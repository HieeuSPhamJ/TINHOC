#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;

vector <int> adj[maxN];
int num[maxN];
int low[maxN];
int Count;
int cnt;
stack <int> stackNode;

void tarjan(int node){
    stackNode.push(node);
    num[node] = low[node] = ++cnt;
    for (auto newNode: adj[node]){
        if (num[newNode]){
            low[node] = min(low[node], num[newNode]);
        }
        else{
            tarjan(newNode);
            low[node] = min(low[node], low[newNode]);
        }
    }
    if (num[node] == low[node]){
        Count++;
        while(stackNode.top() != node){
            low[stackNode.top()] = num[stackNode.top()] = 1e18;
            stackNode.pop();
        }
        low[stackNode.top()] = num[stackNode.top()] = 1e18;
        stackNode.pop();
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while (test--){
        int n, m;
        cin >> n >> m;
        Count = cnt = 0;
        while(!stackNode.empty()) stackNode.pop();
        for (int i = 1; i <= n; i++){
            num[i] = low[i] = 0;
            adj[i].clear();
        }
        for (int i = 1; i <= m; i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
        }
        for (int i = 1; i <= n; i++){
            if (!num[i])
            tarjan(i);
        }
        // cout << Count;
        cout << (Count != n) << endl;
    }
    return 0;
}
