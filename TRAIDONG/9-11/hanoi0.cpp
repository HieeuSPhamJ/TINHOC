#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define c1 fi.fi
#define c2 fi.se
#define c3 se
#define int long long
#define sss pair <pair <string,string>, string>
#define double long double
#define endl '\n'
using namespace std;


vector <int> Col[4];

void back(int a, int b, int c, int n){
    if (n == 1){
        cout << char('A' + a) << char('A' + b);
        return;
    }
    back(a,b,c,n - 1);
    cout << char('A' + a);
    if (n == 2){
        cout << char('A' + c);
    }
    else{
        back(c,a,b, n - 2);
        cout << char('A' + c);
        back(b,c,a, n - 2);
    }
    cout << char('A' + b);
    back(a,b,c,n - 1);

}


signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    back(0,1,2,n);
    return 0;
}