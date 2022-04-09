#include<bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("BAC.INP", "r", stdin);
    freopen("BAC.OUT", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        int count = 0;
        for (int j = 1; j <= n; j++){
            int inp;
            cin >> inp;
            count += (inp > 0);    
        }
        cout << i << ' ' << count << "\n";
        
    }

    return 0;
}   