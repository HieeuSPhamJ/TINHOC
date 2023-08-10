#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;


const int maxN = 2e5 + 10;

ii a[maxN];
int pre[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i].fi;
        }
        for (int i = 1; i <= n; i++){
            a[i].se = i;
        }
        sort(a + 1, a + 1 + n);

        for (int i = 1; i <= n; i++){
            pre[i] = pre[i - 1] + a[i].fi;
        }

        vector <ii> ans;
        for (int i = 1; i <= n; i++){
            ans.push_back({a[i].se, (2 * i - n) * a[i].fi - 2 * pre[i] + pre[n] + n});
        }
        sort(all(ans));

        for (auto i: ans){
            cout << i.se << " ";
        }
        cout << endl;
    }
    return 0;
}

/*

*/