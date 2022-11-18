#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int a, b;

int LCM(int x, int y){
    int gcd = __gcd(x, y);
    return x / gcd * y;
}


void sub1(){
    int x = 0;
    for (int i = 1; i <= b; i++){
        x = max(x, LCM(i,a));
        // cout << i << " " << x << endl;
    }
    cout << x << endl;
}

void sub2(){
    int x = 0;
    while(__gcd(b,a) != 1){
        x = max(x, LCM(b,a));
        b--;
        x = max(x, LCM(b,a));
    }
    x = max(x, LCM(b,a));
    cout << x << endl;
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
        cin >> a >> b;
        if (b <= 1000){
            sub1();
            continue;
        }
        sub2();
    }
    return 0;
}


/*
gcd = 1;
a * b;
*/