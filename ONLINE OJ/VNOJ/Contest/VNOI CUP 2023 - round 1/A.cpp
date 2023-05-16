#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 110;

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
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        int ok = 0;
        for (int i = 1; i <= n; i++){
            int cnt = 1;
            int t = a[i];
            while(t != i){
                cnt++;
                t = a[t];
                if (cnt >= 4){
                    break;
                }
            }
            if (cnt == 3){
                ok = 1;
            }
        }
        if (ok){
            cout << "<3" << endl;
        }
        else{
            cout << "</3" << endl;
        }
    }
    return 0;
}