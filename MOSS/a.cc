#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long

const int inf = 1e18 + 7;
const int N = 1e5 + 7;
const int MOD = 1e9 + 7;

int n, m, d, ans, id, cnt;
int a[N], sum[N], suf[N];
int current;

int add(int a , int b) {
    return (a + b); 
}

int dis(int a , int b) {
    return a - b;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) {
        cin >> n >> m >> d;
        for (int i = 1 ; i <= m ; i++) cin >> a[i];
        for (int i = 1 ; i <= m + 1 ; i++) {
            sum[0] = 0;
        }
        a[0] = 1LL; sum[0] = 1LL;
        a[m + 1] = n + 1;
        if ((a[1] - 1) == 0) {
            sum[1] = 1;
        }
        else
        {
            sum[1] = add(2 , (a[1] - 2)/d);
        }
        suf[m + 1] = 0;
        for (int i = 2; i <= m + 1; i++)
            sum[i] = add(sum[i - 1] , (dis(a[i] , a[i - 1]) - 1)/d) + 1;
        sum[m + 1] --;
        for (int i = m; i >= 1; -- i){
            suf[i] = add(suf[i + 1] , 1 + (a[i + 1] - a[i] - 1)/d);
        }
        ans = n + 1;
        cnt = 0;
        for (int i = 1; i <= m; ++ i)
        {
            current = add(sum[i - 1] , suf[i + 1]);
            current = add(current , (a[i + 1] - a[i - 1] - 1) / d);
            if (current == ans) {
                cnt = cnt + 1;
            }
            else {
                if (current < ans) {
                    ans = current;
                    cnt = 1;
                }
            }
        }
        cout << ans << " "  << cnt << '\n';
    }

    return 0;
}