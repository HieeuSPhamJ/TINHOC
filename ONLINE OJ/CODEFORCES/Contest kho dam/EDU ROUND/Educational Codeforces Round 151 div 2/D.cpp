#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 3e5 + 10;


int n;
int a[maxN];
int p[maxN];
int s[maxN];

int cal(int k){
    int t = 0;
    for (int i = 1; i <= n; i++){
        if (t >= k and t + a[i] < k){
            t = k;
        }
        else{
            t += a[i];
        }
    }
    return t;
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
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            p[i] = p[i - 1] + a[i];
        }
        s[n + 1] = 1e18;
        for (int i = n; i >= 1; i--){
            s[i] = min(s[i + 1], p[i]);
        }

        int res = 0;
        int t = cal(0);
        
        for (int i = 1; i <= n; i++){
            if (t < p[n] + p[i] - s[i + 1]){
               res = max(res, p[i]);
               t = p[n] + p[i] - s[i + 1];
            }
        }
        cout << res << endl;
    }
    return 0;
}

/*
3 -2 1 2
3 1 2 4
s[i]

A - p[i] + 

gọi Sj là tổng từ 1->j, tổng từ (1->i) + tổng từ (i+1->n) -(Si-min(S(i+1->n) )

*/