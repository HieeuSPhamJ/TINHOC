#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int a[20];

signed main(){
    // freopen("XORVAL.INP", "r", stdin);
    // freopen("XORVAL.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        memset(a,0,sizeof(a));

        for (int t = 1; t <= n; t++){
            int x;
            cin >> x;
            // cout << "With: " << x << endl;
            for (int i = 0; i <= 18; i++){
                if (((x >> i) & 1ll)){
                    a[i]++;
                    // cout << i << " ";
                }
                else{
                    a[i]--;
                }
            }
            // cout << endl;
        }
        int res = 0;
        for (int i = 0; i <= 18; i++){
            cout << a[i] << " ";
            if (a[i] > 0){
                res = (res | (1ll << i));
            }
        }
        cout << endl;
        cout << res << endl;
    }
    return 0;
}