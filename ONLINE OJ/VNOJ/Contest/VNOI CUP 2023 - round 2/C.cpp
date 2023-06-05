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
unordered_map <int,multiset <int>> dir;

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
        dir.clear();
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            dir[a[i]].insert(i % k);
        }
        sort(a + 1, a + 1 + n);

        for (int i = 1; i <= n; i++){
            if (dir[a[i]].find(i % k) != dir[a[i]].end()){
                dir[a[i]].erase(dir[a[i]].find(i % k));
            }
            else if (dir[a[i]].find((k - (i % k)) % k) != dir[a[i]].end()){
                dir[a[i]].erase(dir[a[i]].find((k - (i % k)) % k));
            }
            else{
                cout << "NO" << endl;
                goto bru;
            }
        }

        cout << "YES" << endl;
        bru:;
    

    }
    return 0;
}