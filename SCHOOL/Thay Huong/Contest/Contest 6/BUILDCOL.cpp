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

const int maxN = 1e5 + 10;

int n, k;
int a[maxN];
int b[maxN];
int fl[maxN];
int fr[maxN];

bool check(int x){
    for (int i = 1; i <= n; i++){
        b[i] = max(a[i], x);
    }    
    for (int i = 1; i <= n; i++){
        fl[i] = max(fl[i - 1], b[i]);
    }
    for (int i = n; i >= 1; i--){
        fr[i] = max(fr[i + 1], b[i]);
    }

    int res = 0;
    // cout << "with: " << x << endl;
    for (int i = 1; i <= n; i++){
        res += min(fl[i], fr[i]) - b[i];
    }
    return res >= k;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("BUILDCOL.inp", "r")) {
        freopen("BUILDCOL.inp", "r", stdin);
        freopen("BUILDCOL.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    int l = *min_element(a + 1, a + 1 + n);
    int r = *max_element(a + 1, a + 1 + n);
    int res = -1;

    while(l <= r){
        int mid = (l + r) / 2;
        if (check(mid)){
            l = mid + 1;
            res = mid;
        }
        else{
            r = mid - 1;
        }
    }
    cout << res << endl;
    return 0;
}