#include<bits/stdc++.h>
#define ii pair <int,int>
#define f first
#define s second
#define ll long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        ll n, m;
        cin >> n >> m;
        cout << ((1 + m) * m) / 2 + m * (n - 1);
        cout << endl;
    }
    return 0;
}