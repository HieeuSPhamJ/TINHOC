#include"bits/stdc++.h"
#define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define node pair<ii,int>
using namespace std;

int cnt[32];

class Compare{
public:
    bool operator()(node a, node b){
        return a.fi.fi < b.fi.fi;
    }
};

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("mexquery.inp", "r")) {
        freopen("mexquery.inp", "r", stdin);
        freopen("mexquery.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    set<node, Compare> s;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        s.insert({{i,i}, x});
    }
    int test;
    cin >> test;
    while(test--){
        // for (auto i: s){
        //     cout << i.fi.se - i.fi.fi + 1 << ' ' << i.se << endl;
        // }
        int t;
        cin >> t;
        int l, r;
        cin >> l >> r;

        // cout << "Solve: " << l << " " << r << endl;

        vector <node> ls;
        auto it = s.lower_bound({{l,l},0});
        if (it != s.begin()){
            it--;
            node tmp = *it;
            if (tmp.fi.se >= l){
                ls.push_back({{l, tmp.fi.se}, tmp.se});
                s.erase(it);
                tmp.fi.se = l - 1;
                s.insert(tmp);
            }
        }
        while(1){   
            it = s.lower_bound({{l,l},0});
            if (it == s.end() or (*it).fi.fi > r){
                break;
            }

            node x = *it;
            s.erase(it);
            if (x.fi.se > r){
                s.insert({{r + 1, x.fi.se}, x.se});
                x.fi.se = r;
            }
            // cout << "+" << x.fi.fi << ' ' << x.fi.se << " " << x.se << endl;
            ls.push_back(x);
        }

        for (int i = 0; i <= 31; i++){
            cnt[i] = 0;
        }

        if (t == 2){
            for (auto i: ls){
                cnt[i.se] = 1;
                // cout << i.se << endl;
            }
            for (int i = 0; i <= 31; i++){
                int x = cnt[i];
                if (x == 0){
                    cout << i << endl;
                    break;
                }
            }
            vector <node> ts;

            for (auto i: ls){
                if (ts.empty()){
                    ts.push_back(i);
                    continue;
                }
                if (ts.back().se == i.se){
                    ts[ts.size() - 1].fi.se = i.fi.se;
                }
                else{
                    ts.push_back(i);
                }
            }

            for (auto x: ts){
                s.insert(x);
            }
        }
        else{
            for (auto i: ls){
                cnt[i.se] += i.fi.se - i.fi.fi + 1;
                // cout << i.se << endl;
            }
            ls.clear();
            vector <ii> ts;
            for (int i = 0; i <= 31; i++){
                if (cnt[i]){
                    ts.push_back({i,cnt[i]});
                }
            }
            int te;
            cin >> te;
            if (te == 1){
                sort(all(ts));
            }
            else{
                sort(rall(ts));
            }

            int la = l;

            for (auto i: ts){
                ls.push_back({{la, la + i.se - 1}, i.fi});
                la = la + i.se;
            }

            for (auto x: ls){
                s.insert(x);
            }

        }
        // break;
    }
    return 0;
}

/*
1234567890
0101211223 
0101112223 

1 0
1 1
1 0
1 1
1 2
1 1
1 1
1 2
1 2
1 3

*/