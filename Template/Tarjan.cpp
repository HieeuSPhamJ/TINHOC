#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 1e4 + 10;

vector <int> adj[maxN];
int isKhop[maxN];
int num[maxN];
int low[maxN];

int cnt = 0;
int khop = 0;
int cau = 0;

void tarjan(int node, int father){
    num[node] = low[node] = ++cnt;
    int child = 0;
    for (auto newNode: adj[node]){
        if (newNode == father){
            continue;
        }
        if (num[newNode]){
            low[node] = min(low[node], num[newNode]);
        }
        else{
            tarjan(newNode, node);
            low[node] = min(low[node], low[newNode]);
            child++;
            if (low[newNode] >= num[newNode]){
                cau++;
                cout << node << " " << newNode << endl;
            }
            if (node == father){
                if (child >= 2){
                    isKhop[node] = 1;
                }
            }
            else{
                if (low[newNode] >= num[node]){
                    isKhop[node] = 1;
                }
            }
        }
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

    // for (int i = 1; i <= n; i++){
    //     cout << i << ": ";
    //     for (auto j: adj[i]){
    //         cout << j << ", ";
    //     }
    //     cout << endl;
    // }

    for (int i = 1; i <= n; i++){
        tarjan(i,i);
    }
    // tarjan(1,1);

    for (int i = 1; i <= n; i++){
        if (isKhop[i]){
            cout << i << endl;
        }
        khop += isKhop[i];
    }

    // cout << khop << " " << cau;
    return 0;
}