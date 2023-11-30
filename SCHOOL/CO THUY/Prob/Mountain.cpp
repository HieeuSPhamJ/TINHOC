#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

bool cmp(ii a, ii b){
    if (a.fi != b.fi){
        return a.fi > b.fi;
    }
    return a.se < b.se;
}

signed main(){
    // freopen("input.inp", "r", stdin);
    // freopen("A.out", "w", stdout);
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector <ii> ls;
    for (int i = 1; i <= n; i++){
        int x, y;
        cin >> x >> y;
        ls.push_back({x - y, x + y});
    }
    sort(all(ls));

    int res = n;
    ii last = {-1,-1};
    for(auto i: ls){
        if(i.fi >= last.se){
            last.fi = i.fi;
            last.se = i.se;
            continue;
        }
        if(i.fi == last.fi){
            res--;
            last.se = max(i.se, last.se);
        }
        else if(i.se <= last.se){
            res--;
        }
        else{
            last.fi = i.fi;
            last.se = i.se;
        }
    }
    cout << res << endl;
    return 0;
}