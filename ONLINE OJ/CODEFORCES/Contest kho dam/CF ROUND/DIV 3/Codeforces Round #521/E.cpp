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
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    map <int,int> cnt;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        cnt[x]++;
    }
    vector <int> ls;
    for (auto i: cnt){
        ls.push_back(i.se);
    }
    sort(rall(ls));
    
    return 0;
}