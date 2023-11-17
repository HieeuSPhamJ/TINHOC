#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e6 + 10;

int a[maxN];
int l[maxN];
int r[maxN];

signed main(){
    freopen("MINLR.INP", "r", stdin);
    freopen("MINLR.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    a[0] = -1e18;
    a[n + 1] = -1e18;
    for (int i = 1; i <= n; i++){
        int t = i;
        while(a[t - 1] >= a[i]){
            t = l[t - 1];
        }
        l[i] = t;
    }
    r[n + 1] = n + 1;
    for (int i = n; i >= 1; i--){
        int t = i;
        while(a[t + 1] >= a[i]){
            t = r[t + 1];
        }
        r[i] = t;
    }
    
    for (int i = 1; i <= n; i++){
        cout << l[i] << " " << r[i] << endl;
    
    }
    return 0;
}