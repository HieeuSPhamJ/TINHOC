#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

map <int, int> cnt;

int cal(int n){
    if (n == 0){
        return 1;
    }
    if (cnt[n]){
        return cnt[n];
    }
    
    return cnt[n] = cal(n / 2) + cal(n / 3);

}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    cout << cal(n);
    return 0;
}