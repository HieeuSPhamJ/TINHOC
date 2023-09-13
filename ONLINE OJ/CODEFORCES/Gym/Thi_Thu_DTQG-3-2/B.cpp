#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;


int cal(int l1, int r1, int l2, int r2){
    int res = 0;
    int l = max(l1,l2);
    int r = min(r1,r2);
    int n = r - l + 1;
    res = n * (n - 1) / 2;
    res += n * (l - l2);
    res += (r1 - r) * (r2 - l1 + 1);
    return res;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    int res = 0;
    for (int i = a; i <= b; i++){
        res += cal(b,c,c - i,d - i);
    }
    cout << res << endl;
    return 0;
}