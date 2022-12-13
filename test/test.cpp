#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int mod = 1e9 + 7;


int POW[30];

ii add(ii a, ii b){
    ii res;
    res.fi = POW[getLen(b.se)] * a.fi + b.fi;
    int sum = POW[getLen(b.se)] * a.se + b.se;
    res.fi += sum / mod;
    res.se += sum % mod;
    return res;
}


signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    POW[0] = 1;
    for (int i = 1; i <= 15; i++){
        POW[i] = POW[i - 1] * 10;
    }

    ii t = add({113,315153251},{0,2});
    cout << t.fi << " " << t.se << endl;
    
    return 0;
}
/*

a * mod * modaddaa

*/