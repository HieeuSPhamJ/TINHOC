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

const int maxN = 1e6 + 10;

int cnta[maxN];
int cntb[maxN];

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
        for (int i = 0; i <= n + 100; i++){
            cnta[i] = 0;
            cntb[i] = 0;
        }
        int ma = 0;
        for (int i = 0; i < n; i++){
            int x;
            cin >> x;
            for (int j = i; x; j++){
                cnta[j] += x % 2;
                x /= 2;
                ma = max(ma, j);
            }
        }

        for (int i = 0; i <= ma; i++){
            if (cnta[i] > 1){
                ma = max(ma, i + 1);
                cnta[i + 1] += cnta[i] / 2;
                cnta[i] = cnta[i] % 2;
            }
        }

        for (int i = 0; i < n; i++){
            int x;
            cin >> x;
            for (int j = i; x; j++){
                cntb[j] += x % 2;
                x /= 2;
                ma = max(ma, j);
            }
        }

        for (int i = 0; i <= ma; i++){
            if (cntb[i] > 1){
                ma = max(ma, i + 1);
                cntb[i + 1] += cntb[i] / 2;
                cntb[i] = cntb[i] % 2;
            }
        }

        for (int i = ma; i >= 0; i--){
            // cout << cnta[i] << " " << cntb[i] << endl;
            if (cnta[i] > cntb[i]){
                break;
            }
            if (cnta[i] < cntb[i]){
                cout << "NO" << endl;
                goto bru;
            }
        }

        cout << "YES" << endl;
        bru:;
    }
    return 0;
}

/*
1 1 4 5
3 1 2 3

1
01
00001
000101
110111

11
01
0001
00011

12021
101001


*/