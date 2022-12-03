#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 1e6 + 10;

int CNT = 0;
int a[1010][1010];
int b[1010][1010];
ii c[maxN];
vector <int> adj[maxN];
int father[maxN][23];
int level[maxN];
int root[maxN];
int check[maxN];
int ban[maxN];
struct QUERY{
    int t,x,y,u,v;
};

ii d[]{
    {0,1},
    {1,0},
    {-1,0},
    {0,-1}
};

int findRoot(int n){
    if (n == root[n]){
        return n;
    }
    return root[n] = findRoot(root[n]);
}

void DFS(int node, int daddy){
    for (auto newNode: adj[node]){
        if (newNode == daddy){
            continue;
        }
        father[newNode][0] = node;
        level[newNode] = level[node] + 1;
        DFS(newNode, node);
    }
}

void init(){
    level[0] = -1;
    for (int j = 1; j <= log2(CNT); j++){
        for (int i = 1; i <= CNT; i++){
            father[i][j] = father[father[i][j - 1]][j - 1];
        }
    }
}

int LCA(int a, int b){
    if (level[a] < level[b]){
        swap(a,b);
    }
    for (int i = log2(level[a]); level[father[a][i]] >= level[b]; i--){
        if (level[father[a][i]] >= level[b]){
            a = father[a][i];
        }
    }

    if (a == b){
        return a;
    }

    for (int i = log2(level[a]); father[a][0] != father[b][0]; i--){
        if (father[a][i] != father[b][i]){
            a = father[a][i];
            b = father[b][i];
        }
    }

    return father[a][0];
}

void mark(int node, int daddy){
    check[node] = 1;
    root[node] = daddy;
    for (auto nu: adj[node]){
        if (check[nu] == 0){
            mark(nu,daddy);
        }
    }
}

signed main(){
    // freopen("MAZE.INP", "r", stdin);
    // freopen("MAZE.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, q;
    cin >> n >> q;
    int ROOT = -1;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            CNT++;
            char inp;
            cin >> inp;
            a[i][j] = inp - '0';
            b[i][j] = CNT;
            root[CNT] = CNT;
            c[CNT] = {i,j};
            if (a[i][j] == 0){
                ROOT = b[i][j];
                if (a[i - 1][j] == 0 and i - 1 >= 1){
                    adj[b[i][j]].push_back(b[i - 1][j]);
                    adj[b[i - 1][j]].push_back(b[i][j]);
                    // cout << b[i][j] << " " << b[i - 1][j] << endl;
                }
                if (a[i][j - 1] == 0 and j - 1 >= 1){
                    adj[b[i][j]].push_back(b[i][j - 1]);
                    adj[b[i][j - 1]].push_back(b[i][j]);
                    // cout << b[i][j] << " " << b[i][j - 1] << endl;;
                }
            }
        }
    }

    DFS(ROOT,ROOT);
    init();

    stack <QUERY> listq;


    while(q--){
        int t;
        cin >> t;
        if (t == 1){
            int x, y;
            cin >> x >> y;
            listq.push({1,x,y,-1,-1});
            check[b[x][y]] = 1;
            ban[b[x][y]] = 1;
        }
        else{
            int x, y, u, v;
            cin >> x >> y >> u >> v;
            listq.push({2,x,y,u,v});
        }
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (check[b[i][j]] == 0){
                mark(b[i][j], b[i][j]);
            }
        }
    }

    stack <int> ans;

    while(!listq.empty()){
        QUERY i = listq.top();
        listq.pop();
        if (i.t == 1){
            int A = b[i.x][i.y];
            for (auto B: adj[A]){
                if (ban[B] == 1){
                    continue;
                }
                int U = findRoot(A);
                int V = findRoot(B);
                if (U == V){
                    continue;
                }
                else{
                    root[U] = V;
                }
            }
            ban[A] = 0;
        }
        else{
            int A = b[i.u][i.v];
            int B = b[i.x][i.y];
            if (findRoot(A) == findRoot(B)){
                // cout << level[A] + level[B] - 2 * level[LCA(A,B)] + 1 << endl;
                ans.push(level[A] + level[B] - 2 * level[LCA(A,B)] + 1);
            }
            else{
                // cout << -1 << endl;
                ans.push(-1);
            }
        }
    }

    while(!ans.empty()){
        cout << ans.top() << endl;
        ans.pop();
    }


    return 0;
}