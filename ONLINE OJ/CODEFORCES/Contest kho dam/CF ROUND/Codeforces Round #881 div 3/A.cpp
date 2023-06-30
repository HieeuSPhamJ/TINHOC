#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

bool cmp(int a, int b){
    return a > b;
}

signed main(){
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        vector <int> a;
        for (int i = 1; i <= n; i++){
            int x;
            cin >> x;
            a.push_back(x);
        }

        int res = 0;

        sort(all(a), cmp);

        for (int i = 1; i <= n / 2; i++){
            res += a[i - 1] - a[n - i];
        }

        cout << res << endl;
    }
    return 0;
}