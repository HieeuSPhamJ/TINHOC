#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 5 * 1e5 + 10;


int n, test;
vector <int> adj[maxN];
int dp[maxN];
int father[maxN][26];
vector <int> store[maxN];
vector <int> prefix[maxN];

void dfs(int a, int dad){
    store[dp[a]].push_back(a);
    for (auto i: adj[a]){
        if (i == dad){
            continue;
        }
        dp[i] = dp[a] + 1;  
        father[i][0] = a;  
        dfs(i,a);
    }
}

void init(){
    dp[0] = -1e18;
    for (int j = 1; j <= log2(n); j++){
        for (int i = 1; i <= n; i++){
            father[i][j] = father[father[i][j - 1]][j - 1];
        }
    }
}

int cal(int l, int r, int dep){
    int res = 0;
    res = prefix[dep][r];
    if (l > 0){    
        res = prefix[dep][r] xor prefix[dep][l - 1];
    }
    return __builtin_popcount(res);
}

int findAnc(int a, int dep){
    for (int i = log2(dp[a] + 1); i >= 0; i--){
        // cout << i << " " << father[a][i] << " " << dp[father[a][i]] << endl;
        if (dp[father[a][i]] >= dep){
            a = father[a][i];
        }
    }
    return a;
}


int findTurn(int a, int dep, int isLeft){
    if (store[dep].empty() or dp[a] > dep){
        return -1;
    }
    // cout << dp[a] << " ";
    // for (auto i: store[dep]){
    //     cout << i << ":" << findAnc(i, dp[a]) << " ";
    // }
    // cout << endl;
    int l = 0;
    int r = store[dep].size() - 1;
    int res = -1;
    while(l <= r){
        int i = (l + r) / 2;
        int anc = findAnc(store[dep][i], dp[a]);
        if (anc > a){
            r = i - 1;
        }
        else if (anc < a){
            l = i + 1;
        }
        else{
            res = i;
            if (isLeft){
                r = i - 1;
            }
            else{
                l = i + 1;
            }
        }
    }
    return res;
}


signed main(){
    
    freopen("input.inp", "r", stdin);
    freopen("A.out", "w", stdout);
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> test;
    
    freopen("input.inp", "r", stdin);
    freopen("A.out", "w", stdout);
    for (int i = 2; i <= n; i++){
        int x;
        cin >> x;
        adj[x].push_back(i);
        // cout << x << " " << i << endl;
        // adj[i].push_back(x);
    }
    
    string s;
    cin >> s;    

    dp[1] = 1;
    dfs(1,1);
    init();

    for (int i = 1; i <= n; i++){
        // cout << "Deep " << i << ": ";
        int t = 0;
        for (auto x: store[i]){
            t = (t xor (1 << (s[x - 1] - 'a')));
            prefix[i].push_back(t);
            // cout << x << " ";
        }
        // cout << endl;
    }

    // cout << findAnc(4,1) << endl;

    while(test--){
        int a, dep;
        cin >> a >> dep;
        
        // cout << "Left: " << endl;
        int l = findTurn(a, dep, 1);
        
        // cout << "Right: " << endl;
        int r = findTurn(a, dep, 0);

        // cout << l << " " << r << endl;

        if (r == -1 or l == -1){
            cout << "Yes" << endl;
            continue;
        }
        int t = cal(l, r, dep);
        if (t <= 1){
            cout << "Yes";
        }
        else{
            cout << "No";
        }
        cout << endl;
    }




    return 0;
}