#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 2e5 + 10;

int a[maxN];
map <int,int> cnt;

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        cnt.clear();
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            cnt[a[i]]++;
        }
        int q;
        cin >> q;
        while(q--){
            int X, Y;
            cin >> X >> Y;
            int delta = X * X - 4 * Y;
            if (delta < 0){
                cout << 0 << " ";
                continue;
            }
            int x1 = (X + sqrt(delta)) / 2;
            int x2 = (X - sqrt(delta)) / 2;
            if (x1 + x2 == X and x1 * x2 == Y){
                if (x1 == x2){ 
                    cout << cnt[x1] * (cnt[x1] - 1) / 2 << " ";
                }
                else{
                    cout << cnt[x1] * cnt[x2] << " ";
                }
            }
            else{
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

/*
0 = x^2 - Xx + Y
*/