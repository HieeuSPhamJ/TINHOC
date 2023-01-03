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

signed main(){
    freopen("input.inp", "r", stdin);
    freopen("B.out", "w", stdout);
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
        for (int i = 1; i <= n; ++ i)
        {
            char x;
            cin >> x;
            a[i] = (x == 'R');
        }
        int pos = -1;
        for (int i = 2; i <= n; ++ i)
        {
            if (a[i] == 0 and a[i - 1] == 1)
            {
                pos = 0;
                break;
            }
        }
        if (pos == -1){
            for (int i = 2; i <= n; ++ i)
            {
                if (a[i] == 1 and a[i - 1] == 0)
                {
                    pos = i - 1;
                    break;
                }
            }
        }
        cout << pos << endl;
    }
    return 0;
}