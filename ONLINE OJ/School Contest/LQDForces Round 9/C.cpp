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
int adu[maxN];

signed main(){
    // freopen("input.inp", "r", stdin);
    // freopen("A.out", "w", stdout);
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    
    sort(a + 1, a + 1 + n);

    // for (int i = 1; i <= n; i++){
    //     cout << a[i] << " ";
    // }
    // cout << endl;

    for (int i = 1, j = 0; i <= n; i++){
        cout << a[i] << " ";
        while(a[i] - a[j] > k){
            j++;
        }
        j = max(1ll,j);
        // cout << j << " " << i << endl;
        // cout << i << ": " << i - j + 1 << endl;
        adu[i] = max(adu[i - 1], i - j + 1);
    }

    int res = 0;
    for (int i = 1, j = 0; i <= n; i++){
        while(a[i] - a[j] > k){
            j++;
        }
        j = max(1ll,j);
        res = max(res, adu[j - 1] + i - j + 1);
    }

    cout << res << endl;
    return 0;
}

/*
1 1 2 3 7 10 10 10


*/