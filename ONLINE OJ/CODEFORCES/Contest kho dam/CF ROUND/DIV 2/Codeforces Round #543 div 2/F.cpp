#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

 
const int maxN = 5010;
const ii mod = {1e9 + 7, 1e9 + 9};
const ii base = {50,24};
 
ii ha[maxN];
int dp[maxN];
ii POW[maxN];
int cnt[maxN];
int a[maxN];
 
ii mul(ii a, ii b){
    (a.fi *= b.fi) %= mod.fi;
    (a.se *= b.se) %= mod.se;
    return a;
}
 
ii add(ii a, ii b){
    (a.fi += b.fi) %= mod.fi;
    (a.se += b.se) %= mod.se;
    return a;
}
 
 
ii subtr(ii a, ii b){
    (a.fi = a.fi - b.fi + mod.fi) %= mod.fi;
    (a.se = a.se - b.se + mod.se) %= mod.se;
    return a;
}
 
void print(ii a){
    cout << a.fi << " " << a.se << endl;
}
 
ii get(int l, int r){
    return subtr(ha[r], mul(ha[l - 1], POW[r - l + 1]));
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, x, y;
    cin >> n >> x >> y;
    
    for (int i = 1; i <= n; i++){
        char c;
        cin >> c;
        a[i] = c;
        dp[i] = 1e18;
    }

    ha[0] = {0,0};
    POW[0] = {1,1};
    for (int i = 1; i <= n; i++){
        POW[i] =  mul(POW[i - 1], base);
    }
    for (int i = 1; i <= n; i++){
        ha[i] = add(mul(ha[i - 1], base), {a[i], a[i]});
        // cout << a[i] << " ";
    }
    // cout << endl;

    // print(get(1,3));

    for (int i = 1; i <= n; i++){
        dp[i] = min(dp[i], dp[i - 1] + x);
        int far = i - 1;
        int l = i;
        int r = n;
        
        // cout << "With: " << i << endl;
        while(l <= r){
            int mid = (l + r) / 2;
            ii ha1 = get(i,mid);
            int len = (mid - i + 1);
            // cout << " " << mid << " ";
            // print(ha1);
            for (int j = 1; j + len - 1 <= i - 1; j++){
                // cout << "  " << j << " " << j + len - 1 << " ";
                // print(get(j,j + len - 1));
                if (ha1 == get(j,j + len - 1)){
                    l = mid + 1;
                    far = mid;
                    goto bru;
                }
            }
            r = mid - 1;
            bru:;
        }
        for (int j = i; j <= far; j++){
            dp[j] = min(dp[j], dp[i - 1] + y);
        }
    }


    cout << dp[n] << endl;
    return 0;
}

/*
123456789012345678901234567890
eeaeaebdacdbabccbddcaddcddceea
*/