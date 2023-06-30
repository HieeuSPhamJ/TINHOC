#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
// #define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e6 + 10;

int n, m;

vector <int> adj[maxN];
vector <int> nadj[2 * maxN];
int father[2 * maxN][20];

int cnt = 1;
int low[maxN];
int num[maxN];

int lvl[maxN];

vector <int> st;

void tarjan(int nu, int fa){   
    low[nu] = num[nu] = cnt;
    cnt++;
    st.push_back(nu);
    for (auto i: adj[nu]){
        if (i == fa){
            continue;
        }
        if (num[i]){
            low[nu] = min(low[nu], num[i]);
            continue;
        }
        tarjan(i,nu);
        low[nu] = min(low[nu], low[i]);

        if (low[i] >= num[nu]){
            n++;
            // cout << nu << ": ";
            while(st.back() != nu){
                // cout << st.back() << ' ';
                // cout << n << " " << st.back() << endl;
                nadj[n].push_back(st.back());
                nadj[st.back()].push_back(n);
                st.pop_back();
            }
            // cout << n << " " << nu << endl;
            nadj[n].push_back(nu);
            nadj[nu].push_back(n);
            // cout << endl;
        }
    }
}

void dfs(int nu, int fa){
    for (auto i: nadj[nu]){
        if (i == fa){
            continue;
        }
        father[i][0] = nu;
        lvl[i] = lvl[nu] + 1;
        dfs(i,nu);
    }
}

void init(){
    lvl[0] = -1;

    for (int j = 1; j <= log2(n); j++){
        for (int i = 1; i <= n; i++){
            father[i][j] = father[father[i][j - 1]][j - 1];
        }
    }
}

int lca(int a, int b){
    if (lvl[a] < lvl[b]){
        swap(a,b);
    }
    for (int i = log2(lvl[a]); i >= 0; i--){
        if (lvl[father[a][i]] >= lvl[b]){
            a = father[a][i];
        }
    }

    if (a == b){
        return a;
    }

    for (int i = log2(lvl[a]); i >= 0; i--){
        if (father[a][i] != father[b][i]){
            a = father[a][i];
            b = father[b][i];
        }
    }

    return father[a][0];
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> n >> m;
    cin >> test;
    vector <ii> ls;
    for (int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        ls.push_back({a,b});
    }

    tarjan(1,1);

    dfs(1,1);
    init();

    // for (int i = 1; i <= n; i++){

    // }

    while(test--){
        int a, b;
        cin >> a >> b;
        cout << (lvl[a] + lvl[b] - 2 * lvl[lca(a,b)]) / 2 << endl;
    }

    // cout << "===END===";
    return 0;
}