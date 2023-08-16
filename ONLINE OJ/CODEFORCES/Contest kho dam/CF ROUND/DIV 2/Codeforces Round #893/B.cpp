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

int n, m, d;
int a[maxN];
int pre[maxN];
int suf[maxN];

int cal(int i, int j){
    return (a[i] - a[j] - 1) / d;
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
        
        cin >> n >> m >> d;
        a[0] = 1;
        a[m + 1] = n + 1;
        pre[0] = 1;
        for (int i = 1; i <= m; i++){
            cin >> a[i];
        }
        if (a[1] == 1){
            pre[1] = 1;
        }
        else{
            pre[1] = 2 + cal(1,0);
        }

        for (int i = 2; i <= m + 1; i++){
            pre[i] = pre[i - 1] + 1 + cal(i,i - 1);
        }

        pre[m + 1]--;
        suf[m + 1] = 0;

        for (int i = m; i >= 1; i--){
            suf[i] = suf[i + 1] + 1 + cal(i + 1,i);
        }

        int ans = n + 1;
        int cnt = 0;

        for (int i = 1; i <= m; i++){
            int t = pre[i - 1] + suf[i + 1];
            t += cal(i + 1, i - 1);
            if (t <= ans){
                if (t != ans){
                    cnt = 0;
                }
                ans = t;
                cnt++;
            }
        }
        cout << ans << " " << cnt << endl;
    }
    return 0;
}