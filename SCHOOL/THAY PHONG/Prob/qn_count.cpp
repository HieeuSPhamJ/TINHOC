#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
// #define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e7 + 10;

int a[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        int c;
        cin >> c;
        a[c]++;
    }
    int cnt = 0;
    int ma = 0;
    for (int i = 0; i < maxN; i++){
        cnt += (a[i] > 0);
        ma = max(ma, a[i]);
    }
    cout << cnt << endl << ma << endl;
    return 0;
}