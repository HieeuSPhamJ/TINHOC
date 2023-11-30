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

signed main(){
    freopen("XEPDIA.INP", "r", stdin);
    freopen("XEPDIA.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector <int> ls;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        ls.push_back(x);
    }
    sort(rall(ls));
    int ans = 0;
    int te = 1e18;
    for (auto x: ls){
        if (te > 0){
            ans++;
            te = min(te - 1, x);
        }
        else{
            break;
        }
    }
    cout << ans << endl;
    return 0;
}