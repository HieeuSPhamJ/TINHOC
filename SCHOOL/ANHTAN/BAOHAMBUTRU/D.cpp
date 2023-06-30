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

map <string, int> cnt;
string a[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, d;
    cin >> n >> d;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        // cout << "#With: " << endl;
        for (int mask = 0; mask < (1 << 4); mask++){
            string ss = a[i];
            // cout << bitset<4>(mask) << endl;
            for (int id = 0; id < 4; id++){
                if ((mask & (1 << id)) == 0){
                    ss[id] = '.';
                    // cout << id << " ";
                }
            }
            // cout << endl;
            cnt[ss]++;
            // cout << ss << endl;
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++){
        cout << "With: " << a[i] << endl;
        for (int mask = 0; mask < (1 << 4); mask++){
            string ss = a[i];
            if (__builtin_popcount(mask) == d){
                continue;
            }
            int cur = 0;
            for (int id = 0; id < 4; id++){
                if ((mask & (1 << id))){
                    ss[id] = '.';       
                }
            }
            cout << ss << " " << cur << endl;
        }
        res += cur;
    }
    res /= 2;
    cout << n * (n - 1) - res << endl;
    return 0;
}