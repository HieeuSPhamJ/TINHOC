#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n, m;
        cin >> n >> m;
        string s = "";
        for (int i = 1; i <= m; i++){
            s = s + 'B';
        }
        int i1;
        int i2;
        for (int i = 1; i <= n; i++){
            int inp;
            cin >> inp;

            i1 = inp - 1;
            i2 = m - inp;

            if (s[min(i1,i2)] != 'A'){
                s[min(i1,i2)] = 'A';
            }
            else {
                s[max(i1,i2)] = 'A';
            }
        }
        cout << s;
        cout << endl;
    }
    return 0;
}