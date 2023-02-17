#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;


unordered_map <int,int> m;
priority_queue <int> s;

signed main(){
    freopen("candies.INP", "r", stdin);
    freopen("candies.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        m.clear();
        while(s.size()){
            s.pop();
        }
        while(n--){
            int x;
            cin >> x;
            m[x]++;
        }
        for (auto i: m){
            // cout << i.fi << " " << i.se << endl; 
            s.push(i.se);
        }
        int ans = 0;
        int cnt = 1e18;
        while(s.size() and cnt > 0){
            cnt =min(cnt, s.top());
            s.pop();
            ans += cnt;
            cnt--;
        }
        cout << ans << endl;

    }
    return 0;
}