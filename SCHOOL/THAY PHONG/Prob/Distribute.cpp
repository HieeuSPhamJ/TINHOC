#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 1e5 + 10;
const int mod = 1e9 + 7;

int n;
vector <int> adj[maxN];
int dp[maxN];
vector <int> ls;

void dfs(int nu, int fa){
    dp[nu] = 1;
    for (auto i: adj[nu]){
        if (i == fa){
            continue;
        }
        dfs(i,nu);
        dp[nu] += dp[i];
    }
    if (nu != 1){
        ls.push_back((n - dp[nu]) * dp[nu]);
        // cout << ls.back() << endl;
    }
}

int mul(int a, int b){
    return ((a % mod) * (b % mod)) % mod;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for (int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1,1);

    vector <int> st;
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++){
        int x;
        cin >> x;
        st.push_back(x);
    }


    if (ls.size() >= st.size()){
        sort(rall(ls));
        sort(rall(st));
        for (int i = 0; i < st.size(); i++){
            ls[i] = ls[i] * st[i];
        }
        int res = 0;
        for (auto i: ls){
            res = (res + i) % mod;
        }

        cout << res << endl;
    }
    else{
        sort(all(ls));
        sort(all(st));
        for (int i = 0; i < ls.size(); i++){
            ls[i] = ls[i] * st[i];
        }
        for (int i = ls.size(); i < st.size(); i++){
            (ls[ls.size() - 1] *= st[i]) %= mod;
        }
        int res = 0;
        for (auto i: ls){
            res = (res + i) % mod;
        }
        cout << res << endl;
    }



    return 0;
}

/*
12 10 6 6 6 6
2 2 3 3 4 5 5 7 13
*/