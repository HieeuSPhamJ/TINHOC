#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        int MiX = 0;
        int MiY = 0;
        int MaX = 0;
        int MaY = 0;
    
        for (int i = 1; i <= n; i++){
            int x, y;
            cin >> x >> y;
            MiX = min(MiX, x);
            MiY = min(MiY, y);
            MaX = max(MaX, x);
            MaY = max(MaY, y);
        }
        int x = abs(MaX - MiX);
        int y = abs(MaY - MiY);
        cout << 2 * (x + y) << endl; 
    }

    return 0;
}