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
    int n;
    cin >> n;
    int sq = 1000;
    vector <pair<ii,int>> sto[1010];
    for (int i = 1; i <= n; i++){
        int x, y;
        cin >> x >> y;
        sto[y / sq].push_back({{x,y},i});
    }
    for (int i = 0; i <= sq; i++){
        if (i % 2 == 0){
            sort(all(sto[i]));
        }
        else{
            sort(rall(sto[i]));
        }
        for (auto x: sto[i]){
            cout << x.se << " ";
        }
    }
    return 0;
}

/*
1e6 / k
2 * 1e6 * k
k
*/