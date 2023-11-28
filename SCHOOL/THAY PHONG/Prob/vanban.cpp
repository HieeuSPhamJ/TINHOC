#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    char c;
    map <char,int> cnt;
    while(cin >> c){
        cnt[c]++;
    }
    for (auto i: cnt){
        cout << i.fi << " : " << i.se << endl;
    }
    return 0;
}