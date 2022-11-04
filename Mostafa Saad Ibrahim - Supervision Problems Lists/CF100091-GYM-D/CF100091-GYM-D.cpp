#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 3 * 1e5 + 10;

int n, m, root;

int a[maxN];
int father[maxN][30];
int height[maxN];
int num[maxN];
int low[maxN];
int roof[maxN];
vector <int> adj[maxN];
int cnt = 0;
stack <int> st;

void init(){
    for (int i = 1; i <= n; i++){
        if (roof[i])
        for (auto j: adj[i]){
            if (j != roof[i]){
                adj[roof[i]].push_back(j);
                // cout << roof[i] << " " << j << endl;
            }
        }
    }
    queue <int> Q;
    Q.push(root);
    height[root] = 1;
    while(!Q.empty()){
        int tempV = Q.front();
        // cout << "Node: " << tempV << endl;
        Q.pop();
        for (auto newV: adj[tempV]){
            if (height[newV] == 0){
                // cout << newV << " ";
                father[newV][0] = tempV;
                height[newV] = height[tempV] + 1;
                Q.push(newV);
            }
        }
        // cout << endl;
    }

    for (int j = 1; j <= log2(n); j++){
        for (int i = 1; i <= n; i++){
            father[i][j] = father[father[i][j - 1]][j - 1];
        }
    }
}

void tarjanleocaydukhi(int node, int father){
    low[node] = num[node] = ++cnt;
    st.push(node);
    for (auto newNode: adj[node]){
        if (newNode == father){
            continue;
        }
        if (num[newNode]){
            low[node] = min(low[node], num[newNode]);    
        }
        else{
            tarjanleocaydukhi(newNode,node);
            low[node] = min(low[node], low[newNode]);    
        }
    }

    if (low[node] == num[node]){
        // cout << "NODE: " << node << endl;
        while(st.top() != node){
            adj[st.top()].push_back(node);
            for (auto newNode: adj[st.top()]){
                if (newNode == node){
                    continue;
                }
                adj[newNode].push_back(node);

            }
            // cout << st.top() << " ";
            roof[st.top()] = node;
            low[st.top()] = 1e18;
            num[st.top()] = 1e18;
            st.pop();
        }
        // cout << endl;
        low[st.top()] = 1e18;
        num[st.top()] = 1e18;
        st.pop();
    }

}

int lca(int a, int b){
    if (a == b){
        return father[a][0];
    }
    // cout << a << " " << b << endl;
    if (height[a] < height[b]){
        swap(a,b);
    }
    for (int i = log2(height[a]); i >= 0; i--){
        if (height[father[a][i]] >= height[b]){
            a = father[a][i];
        }
    }
    if (a == b){
        return a;
    }
    for (int i = log2(height[a]); father[a][0] != father[b][0]; i--){
        if (father[a][i] != father[b][i]){
            a = father[a][i];
            b = father[b][i];
        }
    }
    return father[a][0];
}


signed main(){
    freopen("magic.in", "r", stdin);
    freopen("magic.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    cin >> root;
    for (int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    tarjanleocaydukhi(root,root);
    init();
    int k;
    cin >> k;
    for (int i = 1; i <= k; i++){
        int a, b;
        cin >> a >> b;
        // cout << a << " " << b << " ";
        int lc = lca(a,b);
        // cout << lc << " ";
        if (a == b){
            cout << height[lc] << endl;
            continue;
        }
        cout << height[lc] - 1 << endl;
    }

    // for (int i = 1; i <= n; i++){
    //     cout << i << " " << height[i] << " " << father[i][0] << endl;
    // }

    // cout << lca(4,6);

    return 0;
}