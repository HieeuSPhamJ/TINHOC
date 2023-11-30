#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int mod = 1e9 + 7;

signed main(){
    freopen("DELETE.INP", "r", stdin);
    freopen("DELETE.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        vector <int> lists;
        for (int i = 1; i <= n; i++){
            int x;
            cin >> x;
            lists.push_back(x);
        }
        sort(lists.rbegin(), lists.rend());
        int temp = 1;
        int ans = 0;
        int d = 2;
        for (auto i: lists){
            (ans += i * temp) %= mod;
            // cout << temp << endl;
            (temp *= d) %= mod;
            d++;
        }
        cout << ans << endl;
    }
    return 0;
}