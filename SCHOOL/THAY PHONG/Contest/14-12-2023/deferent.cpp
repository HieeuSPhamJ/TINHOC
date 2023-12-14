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

const int maxN = 4e5 + 10;

int a[maxN];

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
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int res = 0;
    multiset <ii> ma;
    multiset <ii,greater<ii>> mi;
    int sma = 0;
    int smi = 0;
    for (int i = 1; i <= n; i++){
        int cnt = 1;
        while(ma.size() and (*ma.begin()).fi < a[i]){
            auto it = ma.begin();
            cnt += (*it).se;
            sma -= (*it).fi * (*it).se;
            ma.erase(it);
        }
        sma += a[i] * cnt;
        ma.insert({a[i], cnt});
        
        cnt = 1;
        while(mi.size() and (*mi.begin()).fi > a[i]){
            auto it = mi.begin();
            cnt += (*it).se;
            smi -= (*it).fi * (*it).se;
            mi.erase(it);
        }
        smi += a[i] * cnt;
        mi.insert({a[i], cnt});
        res += sma - smi;

    }

    cout << res << endl;
    return 0;
}