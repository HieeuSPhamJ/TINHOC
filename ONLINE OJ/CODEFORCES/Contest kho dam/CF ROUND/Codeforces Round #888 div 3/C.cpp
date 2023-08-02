#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 2e5 + 10;

int a[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n, k;
        cin >> n >> k;
        vector <int> ls;
        for (int i = 1; i <= n; i++){
            int x;
            cin >> x;
            a[i] = x;
            ls.push_back(x);
        }
        int ok = 1;
        // cout << "TOP" << endl;
        for (int i = 1; i <= k; i++){
            while(ls.size() and ls.back() != a[n]){
                ls.pop_back();
            }
            if (ls.empty()){
                ok = 0;
                break;
            }
            // cout << i << " " << ls.size() << endl;
            ls.pop_back();
        }
        if (a[1] == a[n]){
            goto bru;
        }
        for (int i = 1; i <= k; i++){
            while(ls.size() and ls.back() != a[1]){
                ls.pop_back();
            }
            if (ls.empty()){
                ok = 0;
                break;
            }
            ls.pop_back();
        }
        bru:;
        if (ok){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}