#include<bits/stdc++.h>
using namespace std;
// DEFINE................
#define ll long long
#define pii pair<int, int>
#define piii pair<int, pair<int, int>>
#define oo LLONG_MAX
#define FILN(a) memset(a, 0x3f, sizeof(a))
const int N = 1e9 + 7;
//                   KHAI BAO
//-----------------------------------------------------------------------
int n, k;
int a[300009];
int dd[300009];
//-----------------------------------------------------------------------
//--------------HAM SO SANH----------------------------------------------
struct cmp{
    bool operator()(int a, int b){
        return a < b;
    }
};
//---------------HAM THEM-------------------------------------------------
void sub1(){
    int res = 0;
    for(int i = 1; i <= n; i ++){
        int cnt = 0;
        for(int j = i; j >= 1; j --){
            dd[a[j]] ++;
            if(dd[a[j]] == k) cnt ++;
            if(dd[a[j]] > k) break;
            if(i - j + 1 == cnt * k) res ++;
        }
        for(int j = i; j >= 1; j --)
            dd[a[j]] = 0;
    }
    cout << res;
}
void sub2(){
    vector<int> dp(300009, 0);
    ll res = 0;
    for(int i = 1; i <= n; i ++)
    {
        int ht = max(dp[i - 1], dd[a[i]] + 1);
        dd[a[i]] = i;
        dp[i] = max(ht, dp[i - 1]);
        res += i - ht + 1;
    }
    cout << res;
}
int pre[300009][3];
void sub3(){
    vector<int> vt(n + 9);
    for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= 2 ; j++){
                pre[i][j] = pre[i - 1][j] + (a[i] == j ? 1 : 0);
            }
        }
        for(int i = 1 ; i <= n ; i++){
            int j = a[i];
            int l = 1 , r = i;
            int res = i;
            if(pre[i][j] < k) continue;
            while(l <= r){
                int mid = l + r >> 1;
                if(pre[i][j] - pre[mid - 1][j] >= k){
                    res = mid;
                    l = mid + 1;
                }
                else{
                    r = mid - 1;
                }
            }
            vt[i] = res;
        }
        int res = 0;
        for(int i = 1 ; i <= n ; i++){
            int j = vt[i];
            if(vt[i] == 0) continue;
            if(i - j + 1 == k){
              //  cout << i << ' ' << j << "\n";
                res++;
            }
            int x = (a[i] == 1 ? 2 : 1);
            int l = 1 , r = i;
            while(l <= r){
                int mid = l + r >> 1;
                if(pre[i][x] - pre[mid - 1][x] >= k){
                    l = mid + 1;
                    j = mid;
                }
                else{
                    r = mid - 1;
                }
            }
            if(i - j + 1 == 2 * k && pre[i][a[i]] - pre[j - 1][a[i]] == k){
                //cout << i << ' ' << j << "\n";
                res++;
            }
            if(j > vt[i] && i - vt[i] + 1 == 2 * k ){
                res++;
            }


        }
        cout << res;
}
void sub4(){
    
}
//------------------------------------------------------------------------
void hihihah(){
    cin >> n >> k;
    int mx = 0;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    if(n <= 3000){
        sub1();
    }
    else{
        if(k == 1){
            sub2();
        }
        else{
            if(mx <= 2){
                sub3();
            }
            else{
                sub4();
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    if(fopen("mo.inp", "r")){
        freopen("mo.inp","r",stdin);
        //freopen("","w",stdout);
    }
    int t = 1;
//    cin >> t;
    while(t --){
        hihihah();
    }
}



