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
    int n, k;
    cin >> n >> k;
    vector <int> st[3];
    for (int i = 1; i <= n; i++){
        int t, x;
        cin >> t >> x;
        st[t].push_back(x);
    }
    sort(all(st[0]));
    sort(all(st[1]));
    sort(all(st[2]));

    multiset <int> s;
    int sum = 0;

    while(st[0].size() and s.size() < k){
        s.insert(st[0].back());
        sum += st[0].back();
        st[0].pop_back();
    }
    int res = sum;
    // cout << res << endl;
    while(st[2].size() and k > 1){
        k--;
        int t = st[2].back();
        st[2].pop_back();
        // cout << t << ": ";
        while(t-- and st[1].size()){
            // cout << st[1].back() << " ";
            s.insert(st[1].back());
            sum += st[1].back();
            st[1].pop_back();
        }
        // cout << endl;
        while(s.size() > k){
            sum -= *s.begin();
            s.erase(s.begin());
        }
        res = max(res,sum);
        // cout << res << endl;
    }

    cout << res << endl;

    return 0;
}