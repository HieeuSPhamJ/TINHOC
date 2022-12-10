#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
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
        int n;
        cin >> n;
        int com = n;
        for (int i = 1, check = 0; i <= 2 * n; i++){
            char inp;
            cin >> inp;
            if (inp == '('){
                com -= check;
                check = 0;
            }
            else{
                check = 1;
            }

        }
        cout << com << endl;
    }
    return 0;
}