#include"bits/stdc++.h"
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

int dp[3][maxN];

bool cmp(ii a, ii b){
    return a.fi * b.se < b.fi * a.se;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("QUALUUNIEM.inp", "r")) {
        freopen("QUALUUNIEM.inp", "r", stdin);
        freopen("QUALUUNIEM.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, w;
    cin >> n >> w;
    vector <ii> ls;
    for (int i = 1; i <= n; i++){
        int t, c;
        cin >> t >> c;
        ls.push_back({c,t});
    }
    sort(all(ls), cmp);
    int res = 0;
    vector <int> st[4];
    vector <int> ne[4];
    while(w and ls.size()){
        if (w - ls.back().se >= 0){
            w -= ls.back().se;
            res += ls.back().fi;
            st[ls.back().se].push_back(ls.back().fi);
            // cout << ls.back().fi << endl;
        }
        else{
            ne[ls.back().se].push_back(ls.back().fi);
            while(ne[ls.back().se].size() > 1){
                ne[ls.back().se].pop_back();
            }
        }
        ls.pop_back();
    }


    int ores = res;


    if (ne[2].size() and w <= 1){
        vector <int> tv = st[1];
        int tres = ores;
        int tw = w;
        while(tv.size()){
            tres -= tv.back();
            tv.pop_back();
            tw++;
            if (tw >= 2){
                res = max(res, tres + ne[2].front());
                break;
            }
        }
    }

    if (ne[3].size() and w <= 2){
        vector <int> tv1 = st[1];
        vector <int> tv2 = st[2];
        int tres = ores;
        int tw = w;
        while(tv1.size()){
            tres -= tv1.back();
            tv1.pop_back();
            tw++;
            if (tw >= 3){
                res = max(res, tres + ne[3].front());
                break;
            }
        }
        tv1 = st[1];
        tv2 = st[2];
        tres = ores;
        tw = w;
        if (tv1.size()){
            tres -= tv1.back();
            // cout << tv1.back() << endl;
            tv1.pop_back();
            tw++;
        }
        if (tv2.size()){
            tres -= tv2.back();
            // cout << tv2.back() << endl;
            tv2.pop_back();
            tw+=2;
        }
        if (tw >= 3){
            res = max(res, tres + ne[3].front());
        }
        tv2 = st[2];
        tres = ores;
        tw = w;
        while(tv2.size()){
            tres -= tv2.back();
            // cout << tv2.back() << endl;
            tv2.pop_back();
            tw+=2;
            if (tw >= 3){
            // cout << "#" << " " << tres << " " << ne[3].front() << endl;
                res = max(res, tres + ne[3].front());
                break;
            }
        }
    }

    cout << res << endl;
    return 0;
}

/*
2 7
3 8
1 2
*/
