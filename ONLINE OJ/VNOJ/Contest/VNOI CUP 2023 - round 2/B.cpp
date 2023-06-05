#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1000;

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
        vector <int> ls;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            for (int j = i - 1; j >= 1; j--){
                ls.push_back(__gcd(a[i],a[j]));
            }
        }

        sort(all(ls));

        ls.pop_back();

        cout << ls.back() << endl;
    }
    return 0;
}