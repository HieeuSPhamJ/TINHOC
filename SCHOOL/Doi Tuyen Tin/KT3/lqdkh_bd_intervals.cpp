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
    freopen("intervals.INP", "r", stdin);
    freopen("intervals.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector <ii> lists;
    while(n--){
        int l, r;
        cin >> l >> r;
        lists.push_back({l,r});
    }
    sort(all(lists));

    int ans = 0;
    priority_queue <int, vector<int>, greater<int>> s;
    for (auto i: lists){
        while(!s.empty() and s.top() < i.fi){
            s.pop();
        }
        ans += s.size();
        s.push(i.se);
    }

    cout << ans << endl;
    return 0;
}