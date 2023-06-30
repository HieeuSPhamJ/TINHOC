#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 2020;

int a[maxN];
int t[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> t[i];
    }
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int res = 0;
    for (int i = 1; i <= n; i++){
        int sum = 0;
        unordered_set <int> ts;
        multiset <int> lt;
        map <int,int> sto;
        for (int j = i; j >= 1; j--){
            sum += a[j];
            if (ts.find(t[j]) == ts.end()){
                ts.insert(t[j]);
                sto[t[j]] = a[j];
                lt.insert(sto[t[j]]);
            }
            else{
                lt.erase(lt.find(sto[t[j]]));
                sto[t[j]] += a[j];
                lt.insert(sto[t[j]]);
            }
            // cout << j << " " << i << " " << ts.size() << endl;
            int tmin = 0;
            if (ts.size() >= k){
                tmin = *lt.rbegin();
            }
            // cout << sum << " " << tmin << endl;
            res = max(res, sum - k * tmin);

        }
    }
    cout << res << endl;
    return 0;
}