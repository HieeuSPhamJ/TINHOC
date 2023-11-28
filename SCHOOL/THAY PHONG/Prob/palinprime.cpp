#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

int notprime[300];

int LOG10(int n){
    if (n == 0){
        return 0;
    }
    return log10(n);
}

int get0(int x){
    int res = x;
    x /= 10;
    while(x){
        res *= 10;
        res += x % 10;
        x /= 10;
    }
    return res;
}
int get1(int x){
    int res = x;
    while(x){
        res *= 10;
        res += x % 10;
        x /= 10;
    }
    return res;
}

int sum(int x){
    int s = 0;
    while(x){
        s += x % 10;
        x /= 10;
    }
    return s;
}

void init(){
    notprime[0] = notprime[1] = 1;
    for (int i = 2; i * i <= 200; i++){
        if (notprime[i] == 0){
            for (int j = i * i; j <= 200; j += i){
                notprime[j] = 1;
            }
        }
    }
}

int cal(int n){
    int n0 = n;
    int len = LOG10(n);
    len /= 2;
    while(len--){
        n /= 10;
    }
    int res = 0;
    for (int i = 1; i <= n; i++){
        int x0 = get0(i);
        int x1 = get1(i);   
        
        if (x0 <= n0){
            res += !notprime[sum(x0)];
        }
        if (x1 <= n0){
            res += !notprime[sum(x1)];
        }

    }
    return res;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b;
    cin >> a >> b;
    init();
    cout << cal(b) - cal(a - 1) << endl;
    // cout << cal(a) << endl;
    // cout << cal(b) << endl;
    return 0;
}