#include"bits/stdc++.h"
#define int long long
//#define double long double
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
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        int cnt0 = 0, cnt1 = 0;
        for (int i = 1, pre = 0; i <= n; i++){
            int x;
            cin >> x;
            pre += x;
            if (x % 2){
                cnt1++;
            }
            else{
                cnt0++;
            }
            if (i == 1){
                cout << pre << " ";
                continue;
            }
            if (cnt1 % 3 == 1){
                cout << pre - cnt1 / 3 - cnt1 % 3 << " ";
                continue;
            }
            cout << pre - cnt1 / 3 << " ";
        }

        cout << endl;
    }
    return 0;
}

/*
1: 0
2: 0
3: 1
4: 1
5: 1
6: 2
7: 2
8: 2
9: 3
10: 4

0 10
1 8
+1 9
2 7
+2 6
0 6



0 0


*/