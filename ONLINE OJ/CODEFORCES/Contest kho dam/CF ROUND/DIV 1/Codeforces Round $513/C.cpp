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

int a[maxN];
int b[maxN];
map <int,int> sto;

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++){
        cin >> b[i];
    }

    for (int i = 1; i <= m; i++){
        for (int j = i, s = 0; j >= 1; j--){
            s += b[j];
            sto[s] = max(sto[s], i - j + 1);
        }
    }

    vector <ii> ls;
    int t = 0;
    for (auto i: sto){
        t = max(t, i.se);
        ls.push_back({i.fi,t});
        // cout << i.fi << ' ' << t << endl;
    }
    int S;
    cin >> S;
    int res = 0;
    for (int i = 1; i <= n; i++){
        for (int j = i, sum = 0; j >= 1; j--){
            sum += a[j];
            int tres = 0;
            int l = 0;
            int r = ls.size() - 1;
            // cout << j << ' ' << i << " " << sum << ": " << endl;
            while(l <= r){
                int mid = (l + r) / 2;
                ii t = ls[mid];
                if (sum * t.fi <= S){
                    // cout << t.fi << " " << t.se << endl;
                    l = mid + 1;
                    tres = (i - j + 1) * t.se;
                }
                else{
                    r = mid - 1;
                }
            }

            // cout << tres << endl;

            res = max(res,tres);
        }
    }

    cout << res << endl;

    return 0;
}