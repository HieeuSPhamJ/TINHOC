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
    int n;
    cin >> n;
    vector <int> ls;
    int sum = 0;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        ls.push_back(x);
        sum += x;
    }
    sum /= n;
    int res = 0;
    for (auto &i: ls){
        if (i <= sum){
            res += (sum + 1 - i);
            i = sum;
        }
    }
    int ans = res;
    for (auto &i: ls){
        if (i > sum){
            int d = min(res,i - sum);
            i -= d;
            res -= d;
        }
    }
    res = 0;
    for (auto &i: ls){
        if (i > sum + 1){
            res += i - (sum + 1);
            i = sum + 1;
        }
    }
    ans += res;

    for (auto &i: ls){
        if (res and i == sum){
            res--;
            i++;
        }
    }

    for (auto i: ls){
        cout << i << " ";
    }
    cout << endl;
    cout << ans << endl;
    return 0;
}