#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

struct good{
    int p,w,k;
};

good a[100010];
int dp[2000];

bool cmp(good x, good y){
    return x.w < y.w;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, W;
    cin >> W >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i].p >> a[i].w >> a[i].k;
    }


    return 0;
}

/*

4 12 1
10 4 1
2 2 1
2 1 1
1 1 1

*/