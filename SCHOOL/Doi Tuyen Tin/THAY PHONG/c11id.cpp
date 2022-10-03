#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector <int> lists;
    for (int i = 1; i <= n; i++){
        int inp;
        cin >> inp;
        lists.push_back(inp);
    }
    sort(lists.begin(), lists.end());
    int t = 0;
    int ans = 1;
    for (auto i: lists){
        ans = ans * max(0ll,(i - t));
        t++;
    }
    cout << ans;
    return 0;
}