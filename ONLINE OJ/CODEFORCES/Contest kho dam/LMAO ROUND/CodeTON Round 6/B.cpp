#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

int t;
bool conv(bool x){
    if (x == t){
        return !x;
    }
    return x;
}

int cp(int a, int b){
    for (int i = 30; i >= 0; i--){
        if (b & (1 << i)){
            if (a )
        }
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n, m;
        cin >> n >> m;
        int a = 0;
        for (int i = 1; i <= n; i++){
            int x;
            cin >> x;
            a = a xor x;
        }
        set <int> ls;
        for (int i = 1; i <= m; i++){
            int x;
            cin >> x;
            ls.insert(x);
        }
        if (n % 2 == 0){
            t = 1;
        }
        else{
            t = 0;
        }
        if (n % 2 == 0){
            for (int i = 30; i >= 0; i--){
            int c = a & (1 << i);
            if (conv(c) == c){
                continue;
            }
            set <int> ts;
            for (auto x: ls){
                if ()
            }
        }
        }
        
    }
    return 0;
}