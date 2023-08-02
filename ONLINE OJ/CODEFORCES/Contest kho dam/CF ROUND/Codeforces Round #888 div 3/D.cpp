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
        int n;
        cin >> n;
        multiset <int> s;
        int sum = (n + 1) * n / 2;
        int ok = 1;
        for (int i = 1; i < n; i++){
            cin >> a[i];
            int d = a[i] - a[i - 1]; 
            s.insert(d);
            // cout << d << " ";
        }
        // cout << endl;
        vector <int> miss;

        for (int i = 1; i <= n; i++){
            if (s.find(i) == s.end()){
                miss.push_back(i);
                // cout << i << " ";
            }
            else{
                s.erase(s.find(i));
            }
        }
        // cout << endl;
        int t = *s.begin();
        if (miss.size() > 2){
            cout << "NO" << endl;
            goto bru;
        }
        if (a[n - 1] > sum){
            cout << "NO" << endl;
            goto bru;
        }
        if (a[n - 1] == sum and t == miss[0] + miss[1]){
            cout << "YES" << endl;
            goto bru;
        }

        if (sum - a[n - 1] == miss[0]){
            cout << "YES" << endl;
            goto bru;
        }
        cout << "NO" << endl;

        bru:;
    }
    return 0;
}