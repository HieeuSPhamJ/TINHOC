#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

unordered_map <int,int> hang;
unordered_map <int,int> cot;
unordered_map <int,int> cheosum;
unordered_map <int,int> cheosub;


signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        int a, b;
        cin >> a >> b;
        hang[a]++;
        cot[b]++;
        cheosum[a + b]++;
        cheosub[a - b]++;
        int ok = 0;
        if (hang[a] >= k){
            ok = 1;
        }
        if (cot[b] >= k){
            ok = 1;
        }
        if (cheosum[a + b] >= k){
            ok = 1;
        }
        if (cheosub[a - b] >= k){
            ok = 1;
        }
        if (ok){
            cout << i << endl;
            return 0;
        }
    }
    cout << - 1 << endl;
    return 0;
}