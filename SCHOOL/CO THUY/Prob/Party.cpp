#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e5 + 10;

int la[maxN];

signed main(){
    // freopen("party.INP", "r", stdin);
    // freopen("party.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector <ii> ls;
    for (int i = 1; i <= n; i++){
        int x, y;
        cin >> x >> y;
        ls.push_back({x,y});
    }
    int res = 0;
    vector <int> ans;
    for (int i = n - 1; i >= 0; i--){
        for (int j = i, adu = ls[i].fi;true;){
            if (la[adu] == 0){
                la[adu] = j;
                res++;
                goto bru;
            }
            if (la[adu] < j){
                goto bru;
            }
            int t = la[adu];
            la[adu] = j;
            if (adu == ls[t].se){
                goto bru;
            }
            j = t;
            adu = ls[t].se;
            
        }
        bru:;
        ans.push_back(res);
    }   

    reverse(all(ans));
    for (auto i: ans){
        cout << i << endl;
    }

    return 0;
}