#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

void cal(int n){
    vector <int> ls;
    for (int i = 1; i <= n; i++){
        ls.push_back(i);
    }
    int ans = 0;
    while(next_permutation(all(ls))){
        int res = 0;
        int ma = 0;
        for (int i = 1; i <= n; i++){
            res += i * ls[i - 1];
            ma = max(ma, i * ls[i - 1]);
        }
        res -= ma;
        if (ans < res){
            ans = res;
        }
    }
    ls.clear();
    for (int i = 1; i <= n; i++){
        ls.push_back(i);
    }
    cout << "N = " << n << ": " << ans << endl;
    while(next_permutation(all(ls))){
        int res = 0;
        int ma = 0;
        for (int i = 1; i <= n; i++){
            res += i * ls[i - 1];
            ma = max(ma, i * ls[i - 1]);
        }
        res -= ma;
        if (ans == res){
            for (auto i: ls){
                cout << i << " ";
            }
            cout << endl;
        }
    }
}

const int maxN = 1e5 + 10;

int a[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // for (int i = 1; i <= 15; i++){
    //     cal(i);
    // }
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        int ans = 0;
        for (int t = 1; t <= n; t++){
            for (int i = 1; i <= n; i++){
                a[i] = i;
            }
            reverse(a + t, a + n + 1);
            int res = 0;
            int ma = 0;
            for (int i = 1; i <= n; i++){
                // cout << a[i] << " ";
                res += i * a[i];
                ma = max(ma, i * a[i]);
            }
            // cout << endl;
            res -= ma;
            if (ans < res){
                ans = res;
            }
        }
        cout << ans << endl;
    }
    return 0;
}