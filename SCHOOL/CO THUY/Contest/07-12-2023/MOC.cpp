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

const int maxN = 1e6 + 10;

int n, k;
int a[maxN];
int cntLim = 0;

int check(int mid){
    multiset<int>s;
    for (int i = mid; i <= n; i++){
        s.insert(a[i]);
    }
    int res = 0;
    for (int i = 1; i < mid; i++){
        auto it = s.lower_bound(a[i] + k);
        if (it != s.end()){
            res++;
            s.erase(it);
        }
        cntLim++;
    }
    return res;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("MOC.inp", "r")) {
        freopen("MOC.inp", "r", stdin);
        freopen("MOC.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    int res = 0;
    for (int i = 0; i <= n / 2; i++){
        if (cntLim >= 2e6){
            break;
        }
        res = max(res, check(n / 2 + i));
        res = max(res, check(n / 2 - i));
    }
    cout << res << endl;
    return 0;
}

/*
123456789
((((()))))
*/