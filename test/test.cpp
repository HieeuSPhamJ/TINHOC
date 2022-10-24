#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int b(int x){
    return (1 - x*x*(1+x+x*x)/(1-x*x*x) * (1-x*x*x))/(1-2*x);
}

int cal(int x){
    int temp = 0;
    for (int i = 0; i <= x; i++){
        temp += pow(x,b(i));
        // cout << b(i) << endl;
    }

    return (1+x+x*x)/((1-x) * (1-x) * (1-x)) - temp/((1-x) * (1-x));
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (int i = 0; i <= 10; i++){
        cout << b(i) << endl;
    }
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        // cout << cal(n + 1) << endl;
    }
    return 0;

}
