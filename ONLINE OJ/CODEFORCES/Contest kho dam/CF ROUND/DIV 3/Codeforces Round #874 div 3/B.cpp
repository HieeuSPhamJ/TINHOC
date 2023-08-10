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

ii a[maxN];
int b[maxN];

bool cmp(ii a, ii b){
    return a.se > b.se;
}

int res[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++){
            cin >> a[i].fi;
            a[i].se = i;
        }
        for (int i = 1; i <= n; i++){
            cin >> b[i];
        }

        sort(a + 1, a + 1 + n);
        sort(b + 1, b + 1 + n);

        for (int i = 1; i <= n; i++){
            res[a[i].se] = b[i];
        }   

        for (int i = 1; i <= n; i++){
            cout << res[i]<< " ";
        }
        cout << endl;

    }
    return 0;
}