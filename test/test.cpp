#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define MOD 1000000007
#define INF 1e18
#define fi first
#define se second
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define sz(a) ((int)(a).size())
#define endl '\n'
#define pi 3.14159265359
#define TASKNAME "A"
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
const int MAXN = 2e5 + 9;
int n,k,f[MAXN],x,ch[MAXN];
int cal(int x,int k){
    cout << x << " " << k << endl;
    int numd = log10(x)+1;
    while(x>0){
        int c = x % 10;
        ch[numd--] = c;
        x/=10;
    }
    return ch[k];
}

main()
{
    fast;
  //  freopen(TASKNAME".inp","r",stdin);
  //  freopen(TASKNAME".out","w",stdout);
    cin>>n>>k;
    f[1] = 1;
    for(x=2;x<=n;x++){
        int d = log10(x) + 1;
        f[x] = f[x-1] * 2 + d;
        if (f[x] > 1e15) break;
    }
    for(;x<MAXN;x++){
        f[x] = INF;
    }
    if (f[n] < k) cout<<-1<<endl;
    else{
        for(int i=n;i>=1;i--){
            int x = log10(i)+1;
            if (k<=x) {
                cout<<cal(i,k)<<endl;
                goto nexxt;
            }
            k-=x;

            if (f[i-1] > k) continue;
            int len = f[i-1];
            k = (k%len == 0) ? len: k%len;
        }
    }
    nexxt :;

}