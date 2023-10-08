#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

map <int,int> dp[90];

vector <int> ls;

void init(){
    int a = 2;
    int b = 1;
    while(a <= 1e18){
        ls.push_back(a);
        // cout << a << endl;
        int t = a;
        a += b;
        b = t;
    }
}

int backtrack(int n, int la){
    // for (int i = 0, cnt = 0; i < 90; i++){
    //     cnt += (int)dp[i].size();
    //     if (cnt > 1e6){
    //         exit(1);
    //     }
    // }
    if (n == 1){
        return 1;
    }
    int &cur = dp[la][n];
    if (cur){
        return cur;
    }
    for (int i = la; i < ls.size(); i++){
        if (n % ls[i] == 0){
            int t = n;
            t /= ls[i];
            cur = cur + backtrack(t, i);
        }
    }
    // cout << n << ": " << cur << endl;
    return cur;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    init();
    while(test--){
        for (int i = 0; i < 90; i++){    
            dp[i].clear();
        }
        int n;
        cin >> n;
        cout << backtrack(n,0) << endl;
    }
    return 0;
}