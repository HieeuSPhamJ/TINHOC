#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;

int a[maxN];
int prefix[maxN];
unordered_set <int> cnt;

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int  n, m;
    cin >> n >> a[1] >> m;
    int cycle = -1;
    for (int i = 2; i <= n; i++){
        a[i] = (a[i - 1] * a[i - 1]) % m; 
        prefix[i - 1] = (prefix[i - 2] + a[i]);
        if (cnt.find(a[i]) != cnt.end()){
            cycle = i - 2;
            break;
        }
        cnt.insert(a[i]);
    }
    // cout << cycle << endl;
    // for (int i = 1; i <= n; i++){
    //     cout << a[i] << " ";
    // }
    // cout << endl;

    if (cycle == -1){
        cout << "LMAO" << endl;
        return 0;
    }

    int ans = 0;

    n--;

    // cout << (n / cycle) << " " << (n % cycle) << " " << prefix[cycle] << endl;

    ans += a[1] + ((n / cycle) * prefix[cycle]) + prefix[(n % cycle)];

    cout << ans << endl;

    return 0;
}

/*
4 + 5 + 3 + 9
2 + 4 + 5 + 3 + 9 + 4 + 5 + 3 + 9 + 4
*/