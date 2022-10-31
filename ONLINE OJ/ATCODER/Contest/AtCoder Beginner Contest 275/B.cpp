#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int mod = 998244353;

int add(int a, int b){
    return (a + b) % mod;
}
int subtr(int a, int b){
    return ((a + mod) - b) % mod; 
}

long long mul(int A, int B)
{
    if (B == 0)
        return 0;

    long long T = mul(A, B / 2) % mod;

    if (B & 1)
        return ((T + T) % mod + A % mod) % mod;
    else
        return (T + T) % mod;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    cout << subtr(mul(a, mul(b,c)), mul(d,mul(e,f)));

    return 0;
}