#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    map <int,int> cnt;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        cnt[x]++;
    }
    vector <int> ls;
    for (auto i: cnt){
        ls.push_back(i.se);
    }
    sort(all(ls));
    // for (auto i: ls){
    //     cout << i << " ";
    // }
    // cout << endl;
    int res = 0;

    for (int st = 1; st <= ls.back(); st++){
        int t = st;
        int tres = 0;
        // cout << "With: " << st << endl;
        int l = 0;
        while(1){
            if (l >= ls.size()){
                break;
            }
            int r = ls.size() - 1;
            while(l < r){
                int mid = (l + r) / 2;
                if (ls[mid] < t){
                    l = mid + 1;
                }
                else{
                    r = mid;
                }
            }
            // cout << t << " " << r << endl;
            if (l < ls.size() and ls[r] >= t){
                tres += t;
                t *= 2;
                l++;
            }
            else{
                break;
            }
        }
        // cout << " =>" << tres << endl;
        res = max(res,tres);
    }
    cout << res << endl;
    return 0;
}