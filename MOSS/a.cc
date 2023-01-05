#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 2 * 1e5 + 10;

int n;
int a[maxN], used[maxN];

void run_case(){
    cin >> n;
    memset(used, 0, sizeof used);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int ans = 0;
    bool ok = 0;
    for (int i = 1; i <= n; i++){
        if (used[i])
            continue;
        vector <int> f;
        int x = i;
        while (!used[x]){
            used[x] = 1;
            f.push_back(x);
            x = a[x];
        }
        ans += (int) f.size() - 1;
        sort(all(f));
        for (int j = 0; j < f.size(); j++)
            if (abs(f[j] - f[j + 1]) == 1)
                ok = 1;
    }
    if (ok) 
        ans--;
    else 
        ans++;
    cout << ans << "\n";

}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        run_case();
    }
    return 0;
}