#include<bits/stdc++.h>
#define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen(".inp", "r")) {
        freopen(".inp", "r", stdin);
        freopen(".out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, x;
    cin >> n >> x;
    deque <int> ls;
    for (int i = 0; i < (1 << n); i++){
        ls.push_back(i xor (i >> 1));
    }
    while(ls.front() != x){
        ls.push_back(ls.front());
        ls.pop_front();
    }
    ls.pop_front();
    for (auto i: ls){
        cout << i << endl;
    }
    return 0;
}

/*
000
001
011
010
110
111
101
100

*/