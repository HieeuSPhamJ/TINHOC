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

const int maxN = 1e5 + 10;

int a[maxN];

signed main(){
    freopen("input.inp", "r", stdin);
    freopen("A.out", "w", stdout);
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("LUXTABLE.inp", "r")) {
        freopen("LUXTABLE.inp", "r", stdin);
        freopen("LUXTABLE.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        map <int,ii> odd, even;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            if (i % 2){
                odd[a[i]].fi++;
                odd[a[i]].se++;
                even[a[i]].fi--;
            }
            else{
                odd[a[i]].fi--;
                even[a[i]].fi++;
                even[a[i]].se++;
            }
        }
        int cv[2];
        cv[0] = 0;
        cv[1] = 0;
        odd[0].fi = -1e18;
        even[0].fi = -1e18;
        for (auto t: odd){
            int i = t.fi;
            if (odd[cv[1]].fi < odd[i].fi){
                cv[1] = i;
            }
            if (odd[cv[1]].fi == odd[i].fi){
                if (odd[cv[1]].se < odd[i].se){
                    cv[1] = i;
                }
            }
            if (even[cv[0]].fi < even[i].fi){
                cv[0] = i;
            }
            if (even[cv[0]].fi == even[i].fi){
                if (even[cv[0]].se < even[i].se){
                    cv[0] = i;
                }
            }
        }
        // cout << cv[1] << ' ' << cv[0] << endl;
        int cnt = 0;
        for (int i = 1; i <= n; i++){
            int p = i % 2;
            if (a[i] == cv[p]){
                continue;
            }
            if (cv[p] == a[i + 1]){
                cnt+=2;
                a[i + 1] = cv[(p + 1) % 2];
            }
            cnt++;
            a[i] = cv[p];
        }
        
        cout << min(n - 1,cnt) << endl;
    }
    return 0;
}

/*
1 2 1 2 3 4 2 1
1 2 1 2 1 2 1 2
*/