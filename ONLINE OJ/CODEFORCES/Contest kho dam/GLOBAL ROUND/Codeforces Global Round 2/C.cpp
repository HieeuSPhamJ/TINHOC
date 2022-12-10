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
    int n, m;
    cin >> n >> m;
    int countA = 0;
    int countB = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            int inp;
            cin >> inp;
            if (inp == 1){
                countA++;
            }
        }
    } 
    
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            int inp;
            cin >> inp;
            if (inp == 1){
                countB++;
            }
        }
    } 

    if (countA == countB){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    return 0;
}