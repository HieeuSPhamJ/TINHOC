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
    int test;
    cin >> test;
    while(test--){
        int n, m;
        cin >> n >> m;
        multiset <int> q;
        for (int i = 1; i <= n; i++){
            int x;
            cin >> x;
            q.insert(x);
        }
        
        for (int i = 1; i <= m; i++){
            int x;
            cin >> x;
            q.erase(q.begin());
            q.insert(x);
        }

        int ans = 0;

        for (auto i: q){
            ans += i;
        }
        cout << ans << endl;
    }
    return 0;
}

/*

*/