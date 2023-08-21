#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 2e5 + 10;

int check[maxN];

bool cmp(pair<ii,int> a, pair <ii,int> b){
    if (a.fi.fi == b.fi.fi){
        return a.fi.se > b.fi.se;
    }
    return a.fi.fi < b.fi.fi;

}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector <pair <ii,int>> ls;
    for (int i = 1; i <= n; i++){
        int a, b;
        cin >> a >> b;
        ls.push_back({{a,b}, i});
    }
    sort(all(ls));
    for (auto i: ls){
        cout << i.fi.fi << ' ' << i.fi.se << endl;
    }
    for (int i = 0, mi = 1e18, j = -1; i < n; i++){
        while(ls[j + 1].fi.fi < ls[i].fi.fi){
            j++;
            mi = min(mi, ls[j].fi.se);
        }
        cout << "+" << i  << " " << j << " " << mi << endl;
        if (mi - ls[i].fi.se >= 0){
            check[ls[i].se]++;
        }
    }
    // for (int i = n - 1, ma = 0, j = n - 1; i >= 0; i--){
    //     while(ls[j].fi.fi > ls[i].fi.fi){
    //         ma = max(ma, ls[j].fi.se);
    //         j--;
    //     }
    //     if (ma < ls[i].fi.se){
    //         check[ls[i].se]++;
    //     }
    // }

    int res = 0;
    for (auto i: ls){
        cout << i.se << ": " << check[i.se] << endl;
    }
    for (int i = 1; i <= n; i++){
        if (check[i] == 2){
            cout << i << " ";
        }
    }
    return 0;
}