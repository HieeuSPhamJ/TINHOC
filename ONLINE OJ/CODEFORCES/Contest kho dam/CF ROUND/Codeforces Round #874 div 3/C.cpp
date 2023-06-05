#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        vector <int> a;
        int cnt0 = 0;
        int cnt1 = 0;
        for (int i = 1; i <= n; i++){
            int x;
            cin >> x;
            a.push_back(x);
            if (x % 2){
                cnt1++;
            }
            else{
                cnt0++;
            }
        }

        if (cnt1 == n or cnt1 == 0){
            cout << "YES" << endl;
            continue;
        }

        int ok = 0;

        sort(all(a));

        if (a[0] % 2 == 1){
            ok = 1;
        }


        if (ok){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }

    }
    return 0;
}