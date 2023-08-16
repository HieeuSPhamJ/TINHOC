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
    int test;
    cin >> test;
    while(test--){
        int a, b, c;
        cin >> a >> b >> c;
        c %= 2;
        if (c == 1){
            if (a >= b){
                cout << "First" << endl;
            }
            else{
                
                cout << "Second" << endl;
            }
        }
        else{
            if (a > b){
                cout << "First" << endl;
            }
            else{
                
                cout << "Second" << endl;
            }
        }
    }
    return 0;
}