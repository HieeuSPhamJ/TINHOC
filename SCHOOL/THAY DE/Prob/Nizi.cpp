#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 1e6 + 10;
int a[maxN];
int pre[maxN];
int sum(int l, int r){
    return pre[r] - pre[l - 1];
}

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
        pre[i] = pre[i - 1] + a[i];
    }
    int ans = 0;
    int ll = 1;
    int lr = 1;
    int rl = n;
    int rr = n;
    
    while(ll <= rr){
        int x = sum
    }
    return 0;
}