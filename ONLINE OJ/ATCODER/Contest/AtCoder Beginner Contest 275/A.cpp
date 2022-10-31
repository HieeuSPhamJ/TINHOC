#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;



signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int id = 1;
    int m = 0;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        if (x >= m){
            m = x;
            id = i;
        }
    }
    cout << id;
    return 0;
}