#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 2 * 1e6 + 10;

vector <int> adj[maxN];

int child[maxN];
ii dp[maxN];
set <int> childLists[maxN];
int ans = 1e18;

void findChild(int node, int father){
    child[node] = 1;
    for (auto newNode: adj[node]){
        if (newNode == father){
            continue;
        }
        findChild(newNode, node);
        child[node] += child[newNode];
    }
}

void DFS(int node, int father){
    childLists[node].insert(child[node]);
    for (auto newNode: adj[node]){
        if (newNode == father){
            continue;
        }
        DFS(newNode, node);
        if (childLists[newNode].size() > childLists[node].size()){
            swap(childLists[newNode], childLists[node]);
        }
        for (auto i: childLists[newNode]){
            childLists[node].insert(i);
        }
        childLists[newNode].clear();
    }
    // cout << "----------" << endl;
    // cout << "Node: " << node << endl;
    int n = child[node];
    int s = n / 2;
    // for (auto i: childLists[node]){
    //     cout << i << " ";
    // }
    // cout << endl;
    auto it1 = childLists[node].upper_bound(s);
    auto it2 = it1;
    if (it2 != childLists[node].begin()){
        it2--;
    }
    if (it2 == childLists[node].end()){
        it2--;
    }
    // cout << *it1 << " " << *it2 << endl;
    dp[node] = {n - *it1, *it1};
    if (abs(dp[node].fi - dp[node].se) > abs((n - *it2) - *it2)){
        dp[node] = {n - *it2, *it2};
    }
    int a = child[1] - child[node];
    int b = dp[node].fi;
    int c = dp[node].se;
    // cout << a << " " << b << " " << c << endl;
    ans = min(ans, max({a,b,c}) - min({a,b,c}));
}

signed main(){
    freopen("CTREE.INP", "r", stdin);
    freopen("CTREE.OUT", "w", stdout);
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

    findChild(1,1);
    DFS(1,1);
    // for (int i = 1; i <= n; i++){
    //     cout << "Node " << i << ": ";
    //     cout << dp[i].fi << " " << dp[i].se << endl;
    // }
    cout << ans;
    return 0;
}