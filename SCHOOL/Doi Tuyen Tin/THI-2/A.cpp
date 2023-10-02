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
    for (int i = 1; i <= n; i++){
        int x1 = i;
        int x2 = i;
        int num1 = i / 10;
        int num2 = i;
        while(x1){
            num1 *= 10;
            num1 += x1 % 10;
            x1 /= 10;
        }
        while(x2){
            num2 *= 10;
            num2 += x2 % 10;
            x2 /= 10;
        }
        if (min(num1,num2) > n){
            break;
        }
        ls.push_back(num1);
        ls.push_back(num2);
    }
    cout << 0 << " " << 0 << endl;
    sort(all(ls));
    for (auto i: ls){
        if (i > n){
            break;
        }
        // cout << i << endl;
        vector <int> s;
        int x = i;
        while(x){
            s.push_back(x % 2);
            x /= 2;
        }
        int ok = 1;
        int len = s.size();
        for (int j = 0; j < len; j++){
            if (s[j] != s[len - j - 1]){
                ok = 0;
            }
        }
        if (ok){
            cout << i << " ";
            for (auto g: s){
                cout << g;
            }
            cout << endl;
        }
    }
    return 0;
}