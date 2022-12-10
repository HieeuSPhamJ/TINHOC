#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
// #define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;

int n, test;
int bit[maxN];

void update(int i, int v){
    while(i <= n){
        bit[i] += v;
        i += (i & (-i));
    }
}

int get(int i){
    int res = 0;
    while(i){
        res += bit[i];
        i -= (i & (-i));
    }
    return res;
}

/*
submask = mask & (submask - 1)
*/

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    n = 10;
    while(1){
        int t;
        cin >> t;
        if (t == 0){
            int i, v;
            cin >> i >> v;
            update(i,v);
        }
        else{
            int i;
            cin >> i;
            cout << get(i) << endl;
        }
    }

    return 0;
}