#include"bits/stdc++.h"
#define int long long
//#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 5e4 + 10;

int n, k;
int a[maxN];
int res[maxN];
vector <ii> q[maxN];

int temp[]

void solve(int l, int r){
    if (l > r){
        return;
    }
    if (l == r){
        if (q[l].size() and q[l].front().fi == l){
            res[q[l].front().se] = 1;
        }
        return;
    }
    int mid = (l + r) / 2;


    solve(l, mid);
    solve(mid + 1, r);
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen(".inp", "r")) {
        freopen(".inp", "r", stdin);
        freopen(".out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int test;
    cin >> test;
    for (int i = 1; i <= test; i++){
        int l, r;
        cin >> l >> r;
        query[l].push_back({r,i});
    }
    
    solve(1,n);
    
    return 0;
}
/*
100000 
1668928
*/