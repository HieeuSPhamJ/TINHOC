#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 100010;
const int mod = 1000000007;

int a[maxN];

void init(){
    a[1] = 0;
    a[2] = 1;
    int check = -1;
    for (int i = 3; i < maxN - 2; i++){
        a[i] = i * a[i - 1] + check;
        if (i % 2 == 0){
            check = -1;
        }
        else{
            check = 1;
        }
        // cout << check;
        a[i] %= mod;
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        cout << a[n] << endl;
    }
    return 0;
}