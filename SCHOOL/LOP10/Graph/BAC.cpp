#include<bits/stdc++.h>
using namespace std;


int main(){
    freopen("BAC.INP", "r", stdin);
    freopen("BAC.OUT", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        int count = 0;
        for (int j = 1; j <= n; j++){
            int inp;
            cin >> inp;
            count += inp;    
        }
        cout << i << ' ' << count << endl;
        
    }

    return 0;
}   