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
        if (n == 1){
            cout << "1" << endl << 1 << endl;
            continue;
        }

        for (int i = log2(n + 1); i; i--){
            int st = (1 << i) - 1;
            vector <int> ls;
            ls.push_back(st);
            for (int j = i; j; j--){
                st = st xor (1 << j);
                st = st xor (1 << (j - 1));
                // cout << st << " ";
                if (st <= n){
                    ls.push_back(st);
                }
                else{
                    goto bru;
                }
            }
            cout << ls.size() << endl;
            for (auto i: ls){
                cout << i << " ";
            }
            cout << endl;
            break;
            bru:;
        }

        
    }
    return 0;
}
