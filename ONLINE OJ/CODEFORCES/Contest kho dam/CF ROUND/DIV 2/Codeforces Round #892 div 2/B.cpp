#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e5 + 10;

vector <int> a[maxN];

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
        int res = 0;
        int mi1 = 1e18;
        int mi2 = 1e18;
        
        for (int i = 1; i <= n; i++){
            int nn;
            cin >> nn;
            a[i].clear();
            for (int j = 1; j <= nn; j++){
                int x;
                cin >> x;
                a[i].push_back(x);
                sort(all(a[i]));
                while(a[i].size() > 2){
                    a[i].pop_back();
                }
            }
            res += a[i][1];
            mi1 = min(mi1,a[i][0]);
            mi2 = min(mi2,a[i][1]);
        }

        res = res - (mi2 - mi1);
        cout << res << endl;
    }
    return 0;
}