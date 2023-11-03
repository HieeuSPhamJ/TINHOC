#include<bits/stdc++.h>
#define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen(".inp", "r")) {
        freopen(".inp", "r", stdin);
        freopen(".out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N = 50;
    int cnt = 0;
    for (int i1 = 1; i1 <= N; i1++){
    for (int i2 = 1; i2 <= N; i2++){
    for (int i3 = i1; i3 <= N; i3++){
    for (int i4 = i2; i4 <= N; i4++){
    for (int i5 = i1; i5 <= i3; i5++){
    for (int i6 = i2; i6 <= i4; i6++){
        cnt++;
    }   
    }   
    }   
    }   
    }   
    }
    cout << cnt << endl;
    return 0;
}

/*
488410000
*/