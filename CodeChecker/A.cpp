//memset 0x3f -> > 1000000000
#include <bits/stdc++.h>
#define f first
#define s second
#define MAXSIZE (int)(2e5+5)
// #define int long long
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
typedef pair<int,int> ii;
string answerString[2] = {"NO", "YES"};
int add(int x, int y, int mod)
{
    int t = x + y;
    return t - mod * (t>=mod);
}
int sub(int x, int y, int mod)
{
    int t = x - y;
    return t + mod * (t<0);
}
int a[(int)(3e5+5)];
int dpl[(int)(3e5+5)];
int dpr[(int)(3e5+5)];
vector <ii> v;
signed main()
{
    //freopen("text.inp","r",stdin);
    //freopen("text.out","w",stdout);
    freopen("input.inp", "r", stdin);
    freopen("A.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) dpl[i] = a[i] + i - 1;
    for (int i=1;i<=n;i++) dpr[i] = a[i] + (n - i);
    for (int i=1;i<=n;i++) dpr[i] = max(dpr[i-1],dpr[i]);
    for (int i=n;i>=1;i--) dpl[i] = max(dpl[i+1],dpl[i]);
    int minn = (int)(2e9);
    for (int i=1;i<=n;i++)
        minn = min(minn,max(a[i],max(dpr[i-1],dpl[i+1])));
    cout<<minn;
}
