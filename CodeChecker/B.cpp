#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h> 
using namespace std;
 
typedef long long ll;
#define int ll
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pair<int, int>> vpi;
typedef vector<vector<int>> vvi;

int mod = 1000000007;

#define FOR(i,e) for(ll i = 0; i < e; i++)
#define FORM(i,s,e) for(ll i = s; i < e; i++)
#define nl "\n"
#define printArr(arr) FOR(abcd, arr.size()){cout<<arr[abcd]<<" ";}cout<<nl;
#define dbg(x) cout<<#x<<" = "<<x<<nl
#define pb push_back
#define pob pop_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define FOREACH(a,b) for(auto &(a): (b))
#define rev(v) reverse(all(v))
#define cint(n) int n; cin>>n
#define cint2(a,b) int a,b; cin>>a>>b
#define cint3(a,b,c) int a,b,c; cin>>a>>b>>c

int gcdExtended(int a, int b, int *x, int *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }

    int x1, y1; // To store results of recursive call
    int gcd = gcdExtended(b % a, a, &x1, &y1);

    // Update x and y using results of recursive
    // call
    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}

// Function to find modulo inverse of a
ll modInverse(ll a, ll m)
{
    int x, y;
    int g = gcdExtended(a, m, &x, &y);
    if (g != 1)
        return 0;
    else
    {
        // m is added to handle negative x
        ll res = (x % m + m) % m;
        return res;
    }
}
 
ll nCr(int n, int r){
    // remember to commend the ans/=i line in case of modulo
    if(r>n){
        return 0;
    }
    if(r>n-r){
        r = n-r;
    }
    ll ans = 1;
    for(int i = 1; i<=r ; i++){
        ans *= (n-i+1);
     // ans%= mod;
     // ans *= modInverse(i, mod);
     // ans %= mod;

    //   *********** COMMENT ***********
        ans /= i;
    }
 
    return ans;
}
 
ll binpow(ll a, ll b) {
    if (b == 0)
        return 1;
    long long res = binpow(a, b / 2);
    if (b % 2)
        return (res * res)%mod * a % mod;
    else
        return (res * res) %mod;
}

struct segTree{
    int size;
    vector<int> seg;

    void init(int n){
        size = 1;
        while(size<n) size *= 2;
        seg.assign(2*size, 0LL);
    }

    void build(vector<int> &arr, int idx, int lx, int rx){
        if(lx>rx) return;
        if(lx == rx){
            if(lx<sz(arr))
                seg[idx] = arr[lx];
            return;
        }

        int m = (lx + rx)/2;
        build(arr, 2*idx+1, lx, m);
        build(arr, 2*idx+2, m+1, rx);

        seg[idx] = seg[2*idx+1] + seg[2*idx+2];
        return;
    }

    void build(vector<int> &arr){
        build(arr, 0, 0, size-1);
    }

    void set(int target_idx, int v, int idx, int lx, int rx){
        if(lx==rx){
            seg[idx] = v;
            return;
        }
        int m = (lx + rx)/2;
        if(target_idx<=m){
            set(target_idx, v, 2*idx+1, lx, m);
        }
        else{
            set(target_idx, v, 2*idx+2, m+1, rx);
        }   

        seg[idx] = seg[2*idx+1] + seg[2*idx+2];
        return;
    }

    void set(int i, int v){
        set(i, v, 0, 0, size-1);
    }

    int sum(int l, int r, int idx, int lx, int rx){
        if(rx<l || lx>r) return 0;
        if(lx>=l && rx<=r) return seg[idx];

        int m = (lx+rx)/2;
        int s1 = sum(l, r, 2*idx+1, lx, m);
        int s2 = sum(l, r, 2*idx+2, m+1, rx);

        return (s1 + s2);
    }

    int sum(int l, int r){
        return sum(l, r, 0, 0, size-1);
    }
};

// z-array is 0 indexed
vector<int> z_function(string &s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

// PRIME FACTORISATION USING SEIVE  
// #define MAXN 100001
// int spf[MAXN];
// void sieve()
// {
//     spf[1] = 1;
//     for (int i=2; i<MAXN; i++)
//         spf[i] = i;
//     for (int i=4; i<MAXN; i+=2)
//         spf[i] = 2;
//     for (int i=3; i*i<MAXN; i++)
//     {
//         if (spf[i] == i)
//         {
//             for (int j=i*i; j<MAXN; j+=i)
//                 if (spf[j]==j)
//                     spf[j] = i;
//         }
//     }
// }
// void getFactorization(int x, vector<int> &factors)
// {
//     while (x != 1)
//     {
//         factors.push_back(spf[x]);
//         x = x / spf[x];
//     }
// }

// LINEAR SIEVE
// const int N = 10000000;
// vector<int> lp(N+1);
// vector<int> pr;
// void linSv(){
//     for (int i=2; i <= N; ++i) {
//         if (lp[i] == 0) {
//             lp[i] = i;
//             pr.push_back(i);
//         }
//         for (int j = 0; i * pr[j] <= N; ++j) {
//             lp[i * pr[j]] = pr[j];
//             if (pr[j] == lp[i]) {
//                 break;
//             }
//         }
//     }
// }

// LOWEST COMMON ANCESTOR
// N = (n+1) in case of 1 indexed
// resize adj -> preprocess(root) -> LCA
// int N, l;
// vector<vector<int>> adj;
// int timer;
// vector<int> tin, tout;
// vector<vector<int>> up;
// void dfs(int v, int p)
// {
//     tin[v] = ++timer;
//     up[v][0] = p;
//     for (int i = 1; i <= l; ++i)
//         up[v][i] = up[up[v][i-1]][i-1];
//     for (int u : adj[v]) {
//         if (u != p)
//             dfs(u, v);
//     }
//     tout[v] = ++timer;
// }
// bool is_ancestor(int u, int v)
// {
//     return tin[u] <= tin[v] && tout[u] >= tout[v];
// }
// int lca(int u, int v)
// {
//     if (is_ancestor(u, v))
//         return u;
//     if (is_ancestor(v, u))
//         return v;
//     for (int i = l; i >= 0; --i) {
//         if (!is_ancestor(up[u][i], v))
//             u = up[u][i];
//     }
//     return up[u][0];
// }
// void preprocess(int root) {
//     tin.resize(N);
//     tout.resize(N);
//     timer = 0;
//     l = ceil(log2(N));
//     up.assign(N, vector<int>(l + 1));
//     dfs(root, root);
// }

// DSU
// resize leader,gsize -> make_set(i) for all i
// vector<int> leader;
// vector<int> gsize;
// vector<vector<int>> adj;
// int find_set(int v) {
//     if (v == leader[v])
//         return v;
//     return leader[v] = find_set(leader[v]);
// }
// void make_set(int v) {
//     leader[v] = v;
//     gsize[v] = 1;
// }
// void union_sets(int a, int b) {
//     a = find_set(a);
//     b = find_set(b);
//     if (a != b) {
//         if (gsize[a] < gsize[b])
//             swap(a, b);
//         leader[b] = a;
//         gsize[a] += gsize[b];
//     }
// }

int n,k; 
vi a;
int dp[5001][5001];


signed main()
{
//#ifndef ONLINE_JUDGE
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
//#endif
freopen("input.inp", "r", stdin);
freopen("B.out", "w", stdout);
fast_cin();


cin>>n>>k;
a.resize(n);
FOR(i,n){
    cin>>a[i];
}
sort(all(a));

dp[0][0] = 0;


for(int i = 1;i<=n; i++){
    // till index i
    for(int len = 1; len<=k; len++){
        // if we end at current index
        auto it = lower_bound(a.begin(), a.end(),a[i-1]-5);
        int idx = (it - a.begin());
        int l = (i-1-idx+1);
        dp[i][len] = max(dp[i][len], dp[idx][len-1] + l);

        // if we don't end at current index
        dp[i][len] = max(dp[i-1][len], dp[i][len]);
    }
}

cout<<dp[n][k]<<nl;


return 0;
}