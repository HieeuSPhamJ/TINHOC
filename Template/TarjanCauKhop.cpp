#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;

vector <int> adj[maxN];
bool isKhop[maxN];
int num[maxN];
int low[maxN];
int khop;
int cau;
int cnt;

void tarjan(int node, int father){
    low[node] = num[node] = ++cnt;
    int child = (node != father);
    for (auto newNode: adj[node]){
        if (newNode == father){
            continue;
        }

        if (num[newNode]){
            low[node] = min(low[node], num[newNode]);
        }
        else {  
            tarjan(newNode, node);
            low[node] = min(low[node], low[newNode]);
            if (low[newNode] == num[newNode]){
                cau++;
            }
            if (low[newNode] >= num[node]){
                child++;
            }
        }
    }
    if (child >= 2){
        // cout << node << endl;
        khop++;
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++){
        if (!num[i]){
            tarjan(i,i);
        }
    }

    // for (int i = 1; i <= n; i++){
    //     khop += isKhop[i];
    // }

    cout << khop << " " << cau << endl;
    return 0;
}
