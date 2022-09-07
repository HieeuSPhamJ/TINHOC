#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;

vector <int> adj[maxN];
int down[maxN];
int up[maxN];
int ans[maxN];

void calDown(int node, int father){
    down[node] = 2;
    int tempAns = 1;
    for (auto newNode: adj[node]){
        if (father == newNode){
            continue;
        }
        calDown(newNode, node);
        tempAns = tempAns * down[newNode];
        down[node] = tempAns + 1;
    }
}

void calUp(int node, int father){
    int tempAns = up[father];
    for (auto newNode: adj[node]){
        if (father == newNode){ 
            continue;
        }
        tempAns = tempAns * down[newNode];
    }
    for (auto newNode: adj[node]){
        if (father == newNode){
            continue;
        }
        // cout << newNode << ": " << tempAns << endl;
        up[newNode] = tempAns / down[newNode] + 1;
        calUp(newNode,node);
    }
}


void calAns(int node, int father){
    int tempAns = down[node] - 1;
    tempAns *= up[node] - 1;
    for (auto newNode: adj[node]){
        if (father == newNode){      
            continue;
        }
        // tempAns *= down[newNode];
        calAns(newNode, node);
    }
    ans[node] = tempAns;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    calDown(1,1);
    up[1] = 1;
    calUp(1,1);

    for (int i = 1; i <= n; i++){
        cout << i << " Up: " << up[i] << endl;
    }
    cout << endl;

    for (int i = 1; i <= n; i++){
        cout << i << " Down: " << down[i] << endl;
    }
    cout << endl;

    up[0] = 1;
    calAns(1,0);

    for (int i = 1; i <= n; i++){
        cout << (ans[i] - 1) % m << endl;
    }

    return 0;
}