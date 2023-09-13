#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

bool cmp(ii a, ii b){
    return a.se < b.se;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        vector <ii> ls;
        for (int i = 1; i <= n; i++){
            int x;
            cin >> x;
            ls.push_back({x,i});
        }
        sort(rall(ls));
        for (int i = 0; i < n; i++){
            ls[i].fi = i + 1;
        }
        sort(all(ls), cmp);

        for (auto i: ls){
            cout << i.fi << " ";
        }
        cout << endl;
    }
    return 0;
}