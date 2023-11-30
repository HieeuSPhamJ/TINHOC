#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1010;

int t[maxN];


signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    for (int i = 1; i <= n; i++){
        t[i] = (a[i - 1] != b[i - 1]);
    }
    int res = 0;

    for (int i = 1; i <= n; i++){
        if (t[i] == 1 and t[i - 1] == 0){
            res++;
        }
    }

    cout << res << endl;

    return 0;
}