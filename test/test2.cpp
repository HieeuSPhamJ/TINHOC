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

int cnt[maxN];
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
        cin >> a[i];
        cnt[a[i]]++;
    }

    int ma = *max_element(a + 1, a + 1 + n);

    for (int i = 1; i <= ma + 100; i++){
        int t = 0;
        int count = 0;
        for (int j = i; j <= ma; j += i){
            if (cnt[j]){
                t  = __gcd(t,j);
                count++;
            }
            if (t == i and count > 1){
                goto bru;
            }
        }
        bru:;
        if (t != i or count <= 1){
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}