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

const int maxN = 3e5 + 10;

int res;
int n, k;
int a[maxN];
int cnt[maxN];

void solve(int l, int r){
    if (l > r){
        return;
    }
    if (r - l + 1 < k){
        return;
    }
    if (r - l + 1 == k){
        for (int i = l; i <= r; i++){
            if (a[i] != a[l]){
                return;
            }
        }
        res++;
        return;
    }
    for (int i = l; i <= r; i++){
        cnt[a[i]] = 0;
    }
    int mid = (l + r) / 2;
    
    for (int st = mid; st >= l; st--){
        cnt[a[i]]++;
        if (cnt[a[i]] > k){
            break;
        }
        
    }

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

    solve(1,n);

    cout << res << endl;
    return 0;
}

/*
1 2 2 2 1 1 2 2 2

5 3 4 7 6 10 8 9 10 
6 4 7 8 10 10 9 10 10 



*/