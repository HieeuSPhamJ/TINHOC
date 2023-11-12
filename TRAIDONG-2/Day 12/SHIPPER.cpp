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
    int n, k;
    cin >> n >> k;
    vector <ii> ls[2];
    for (int i = 1; i <= n; i++){
        int x, v;
        cin >> x >> v;
        if (x < 0){
            ls[0].push_back({v,-x});
        }
        else{
            ls[1].push_back({v,x});
        }
    }
    sort(rall(ls[0]));
    sort(rall(ls[1]));
    int res = 0;
    for (int t = 0; t <= 1; t++){
        while(ls[t].size()){
            int sum = 0;
            int ma = 0;
            while(ls[t].size()){
                int bk = (int)ls[t].size() - 1;
                int tmp = min(k - sum, ls[t][bk].fi);
                if (tmp == 0){
                    break;
                }
                sum += tmp;
                ls[t][bk].fi -= tmp;
                ma = max(ma, ls[t][bk].se);
                if (ls[t][bk].fi == 0){
                    ls[t].pop_back();
                }
                else{
                    res += 2 * (ls[t][bk].fi / k) * ls[t][bk].se;
                    ls[t][bk].fi %= k;
                }
            }
            res += ma + ma;
        }   
    }

    cout << res << endl;
    return 0;
}

/* 
*/