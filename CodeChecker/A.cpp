#include<bits/stdc++.h>
#define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 2e5 + 10;

bool dp[2000 * 2000 + 10];
bool mk[maxN];
int a[maxN];

signed main(){
    freopen("input.inp", "r", stdin);
    freopen("A.out", "w", stdout);
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen(".inp", "r")) {
        freopen(".inp", "r", stdin);
        freopen(".out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector <int> ls;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        if (a[i] == 1){
            cout << k + 1 << endl;
            return 0; 
        }
    }
    sort(a + 1, a + 1 + n);
    int base = 1;
    for (int i = 1; i <= n; i++){
        if (mk[a[i]] == 0){
            ls.push_back(a[i]);
            base = a[i];
        }
        for (int j = a[i]; j <= a[n]; j+=a[i]){
            mk[j] = 1;
        }
    }
    memset(mk,0,sizeof(mk));
    ls.pop_back();
    dp[0] = 1;
    mk[0] = 1;
    for (int j = 1; j < base * base; j++){
        if (!mk[j % base]){
            // cout << "With: " << j << endl;
            for (auto i: ls){
                if (j - i < 0){
                    break;
                }
                if (mk[(j - i) % base]){
                    dp[j] = mk[(j - i) % base];
                    // cout << j - i << " " << (j - i) % base << endl;
                    mk[j % base] = 1;
                    break;
                }
            }
        }
    }
    for (int i = 0; i <= base * base; i++){
        if (dp[i]){
            for (int j = i + base; j <= base * base; j += base){
                dp[j] = 0;
            }
        }
    }
    int res = 0;
    for (int i = 0; i <= base * base; i++){
        if (dp[i]){
            int st = 0;
            int en = k / base;
            if (i > k){
                break;
            }
            while (i + en * base > k){
                en--;
            }
            if (st <= en){
                // cout << i << ": "; 
                // for (int x = st; x <= en; x++){
                //     cout << i + x * base << " ";
                // }
                // cout << endl;
                res += en - st + 1;
            }
        }
    }
    cout << res << endl;
    return 0;
}