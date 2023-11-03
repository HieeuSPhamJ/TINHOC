#include<bits/stdc++.h>
#define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 3e5 + 10;

int own[maxN];
int child[maxN];
int toUnder[maxN];
int father[maxN];
vector <int> adj[maxN];
int sz[maxN];

void dfs(int nu, int fa){
    father[nu] = fa;
    for (auto i: adj[nu]){
        if (i == fa){
            continue;
        }    
        dfs(i,nu);
        sz[nu]++;
        child[nu] += own[i];
    }
}

signed main(){
    freopen("input.inp", "r", stdin);
    freopen("B.out", "w", stdout);
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen(".inp", "r")) {
        freopen(".inp", "r", stdin);
        freopen(".out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, test;
    cin >> n >> test;
    for (int i = 1; i <= n; i++){
        cin >> own[i];
    }
    for (int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    while(test--){
        int t;
        cin >> t;
        if (t == 1){
            int x, c;
            cin >> x >> c;
            for (auto i: adj[x]){
                own[i] += c;
            }
            own[x] += 2 * c;
        }
        else{
            int x;
            cin >> x;
            int res = own[x];
            for (auto i: adj[x]){
                res += own[i];
            }
            cout << res << endl;
        }
        // cout << "====" << endl;
        // for (int i = 1; i <= n; i++){
        //     cout << own[i] << " " << child[i] << " " << toUnder[i] << endl;
        // }
    }
    return 0;
}