#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define endl "\n"
#define int long long
using namespace std;

const int maxN = 2 * 1e5 + 10;

int n, test;
vector <ii> adj[maxN];
int father[maxN][32];
int minLen[maxN][32];
int maxLen[maxN][32];
int height[maxN];

void init(){
    for (int j = 1; (1 << j) <= n; j++){
        for (int i = 1; i <= n; i++){
            father[i][j] = father[father[i][j - 1]][j - 1];
            minLen[i][j] = min(minLen[i][j - 1], minLen[father[i][j - 1]][j - 1]);
            maxLen[i][j] = max(maxLen[i][j - 1], maxLen[father[i][j - 1]][j - 1]);
        }
    }
}

void DFS(int node, int khang){
    for (auto newNode: adj[node]){
        if (newNode.se == khang){
            continue;
        }
        father[newNode.se][0] = node;
        minLen[newNode.se][0] = newNode.fi;
        maxLen[newNode.se][0] = newNode.fi;
        height[newNode.se] = height[node] + 1;
        DFS(newNode.se, node);
    }
}

ii LCA(int a, int b){
    if (height[a] < height[b]){
        swap(a, b);
    }

    int ansMax = 0;
    int ansMin = 1e18;
 
    for (int i = log2(height[a]); height[a] != height[b]; i--){
        if (height[a] - height[b] >= (1 << i)){
            // cout << a << " " << father[a][i] << " " << minLen[a][i] << "-" << maxLen[a][i] << endl;
            ansMin = min(ansMin, minLen[a][i]);
            ansMax = max(ansMax, maxLen[a][i]);
            a = father[a][i];
        }
    }
 
    if (a == b){
        // cout << ansMin << "-" << ansMax << endl;
        return {ansMin,ansMax};
        return {a,b};
    }
 
    for (int i = log2(height[a]); father[a][0] != father[b][0]; i--){
        if (father[a][i] != father[b][i]){
            ansMin = min({ansMin, minLen[a][i], minLen[b][i]});
            ansMax = max({ansMax, maxLen[a][i], maxLen[b][i]});
            a = father[a][i];
            b = father[b][i];
        }
    }
 
    return {min({ansMin, minLen[a][0], minLen[b][0]}), max({ansMax, maxLen[a][0], maxLen[b][0]})};
    ///
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for (int i = 1; i < n; i++){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({w, b});
        adj[b].push_back({w, a});
    }

    DFS(1,1);
    init();
    int test;
    cin >> test;
    while(test--){
        int a, b;
        cin >> a >> b;
        ii lca = LCA(a, b);
        cout << lca.fi << " " << lca.se << endl;
    }

    return 0;
}