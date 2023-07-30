#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

int dp[200][2][4];

int check(int l, int x, int r){
    if (x < l){
        return 0;
    }
    if (x > r){
        return 0;
    }
    return 1LL;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int l, r;
    cin >> l >> r;

    int n = log2(r);
    int a = 0;
    int b = 0;
    int ll = 0;
    int rr = 0;
    for (int i = n; i >= 0; i--){
        ll += ((l & (1LL << i)) > 0) * (1LL << i);
        rr += ((r & (1LL << i)) > 0) * (1LL << i);
        // cout << ll << " " << rr << endl;
        if (check(ll,a + (1LL << i),rr) and check(ll,b,rr)){
            a += (1LL << i);
        }
        else if (check(ll,b + (1LL << i),rr) and check(ll,a,rr)){
            b += (1LL << i);
        }
        else if (check(ll,b,rr) and check(ll,a,rr)){
            continue;
        }
        else{
            a += (1LL << i);
            b += (1LL << i);
        }
    
    }
    // cout << a << " " << b << endl;
    cout << (a xor b);

    return 0;
}

/*
110101
010111

10
01
*/