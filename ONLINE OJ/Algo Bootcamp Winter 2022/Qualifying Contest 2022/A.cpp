#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define double long double
#define int long long
#define endl '\n'
using namespace std;

int solve(double n, double m, double x ,double y){
    int count = 0;
    while(n > x){
        n /= 2;
        count++;
    }
    while(m > y){
        m /= 2;
        count++;
    }
    return count;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    if (x > y){
        swap(n,m);
    }
    cout << min(solve(n,m,x,y), solve(m,n,x,y));
    
    return 0;
}