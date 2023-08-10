#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;


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
        int a[20];
        memset(a,0,sizeof(a));
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            int count = 0;
            for (;x > 0;){
                if (x & 1 != 0)
                {
                    a[count]++;
                }
                x /= 2;
                count++;
            }
        }
        int ma = 0;
        int mi = 1e18;
        for (int i = 1; i <= n; ++ i)
        {
            int now = 0;
            int count = 1;
            for (int i = 0; i <= 11; ++ i)
            {
                if (a[i])
                {
                    a[i]--;
                    now += count;
                }
                count *= 2;
            }
            mi = min(mi, now);
            ma = max(ma, now);
        }
        cout << ma - mi << endl;
    }
    return 0;
}