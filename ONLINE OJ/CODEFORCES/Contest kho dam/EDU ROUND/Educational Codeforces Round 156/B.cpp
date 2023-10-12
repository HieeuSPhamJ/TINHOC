#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

double len(ii a, ii b){
    return sqrt((a.fi - b.fi) * (a.fi - b.fi) + (a.se - b.se) * (a.se - b.se));
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
        ii a, b, c;
        cin >> a.fi >> a.se;
        cin >> b.fi >> b.se;
        cin >> c.fi >> c.se;
        ii d = {0,0};
        double res1 = min(max(len(a,b), len(b,d)), max(len(a,c), len(c,d)));
        double res2 = max({len(b,c)/2, min(len(a,b), len(a,c)), min(len(b,d), len(c,d))});
        cout << fixed << setprecision(8) << min(res1,res2) << endl;
    }
    return 0;
}