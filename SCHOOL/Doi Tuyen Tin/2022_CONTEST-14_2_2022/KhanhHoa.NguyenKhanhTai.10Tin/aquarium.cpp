#include<bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pb push_back
#define endl '\n'
#define TASKNAME "aquarium"
#define INF 1e18
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef pair<ii,ii> iiii;
typedef vector<int> vi;
const int MAXN =2e3 + 9;
int a[MAXN],cnt[MAXN],cost[MAXN],sum[MAXN],tg;
int bitmask[200009][20],dp[MAXN][MAXN],clost[MAXN][MAXN],pre[MAXN];
int n,m,ans = INF;
void sub1(int pos){
    if (pos==n+1){
        int num = 0;
        for(int i=1;i<=m;i++){
            num += cnt[i] * sum[i];
           // cout<<cnt[i]<<' '<<sum[i]<<endl;
        }
        if (num<ans){
            ans = num;
        }
        return;
    }
    for(int i=1;i<=m;i++){

        cnt[i]++;
        sum[i]+=a[pos];
        sub1(pos+1);
        sum[i]-=a[pos];
        cnt[i]--;

    }
}
void sub2(){
    for(int msk=1;msk<(1<<n);msk++){
        for(int j=0;j<=m;j++){
            bitmask[msk][j] = INF;
        }
        for(int i=0;i<n;i++){
            if (msk & (1<<i)) cost[msk] += a[i+1];
        }

    }
    bitmask[0][0] = 0;
    for(int msk=1;msk<(1<<n);msk++){

       for(int j=1;j<=m;j++){
           for(int i=msk;i>0;i=(i-1)&msk){
                int numbit = __builtin_popcount(i);
                bitmask[msk][j] = min(bitmask[msk][j],bitmask[msk ^ i][j-1] + numbit * cost[i]);
           }
        }
    }
    cout<<bitmask[(1<<n)-1][m]<<endl;
}
void sub3(){
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        pre[i] = pre[i-1] + a[i];
    }
    int dest = (m%2==0) ? m/2 : m/2+1;
    int ans = INF;
    for(int i=n;i>=dest;i--){
        ans = min(ans, i * pre[i] + (n-i) * (tg-pre[i]));
    }
    cout<<ans<<endl;

}
void sub4(){
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        pre[i] = pre[i-1] + a[i];
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int t=i-1;t>=0;t--){

                dp[i][j] = min(dp[i][j], dp[t][j-1] + (pre[i] - pre[t]) * (i-t));
            }
        }
    }
    cout<<dp[n][m]<<endl;
}
main(){

     ios_base::sync_with_stdio(NULL);
     cin.tie(NULL);
     cout.tie(NULL);
     freopen(TASKNAME".inp","r",stdin);
     freopen(TASKNAME".out","w",stdout);
     cin>>n>>m;
     for(int i=1;i<=n;i++){
        cin>>a[i];
        tg+=a[i];
     }
     sub4();
}

