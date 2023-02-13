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
int cnt[maxN];
int cnt2[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    sort(a + 1, a + 1 + n);
    int res = 0;
    for (int i = 1; i <= n; i++){
        res += cnt2[a[i]];
        for (int j = 1000; j >= 1; j--){
            cnt2[a[i] + j] += cnt[j];
        }
        cnt[a[i]]++;
    }

    cout << res << endl;
    return 0;
}