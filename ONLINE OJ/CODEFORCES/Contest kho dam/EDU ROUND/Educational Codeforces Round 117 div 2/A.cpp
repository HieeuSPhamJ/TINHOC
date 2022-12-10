#include<bits/stdc++.h>
#define ii pair <int,int>
#define x first
#define y second
#define int long long
using namespace std;


int d(ii a, ii b){
    return abs(a.x - b.x) + abs(a.y - b.y);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        ii a = {0, 0};
        ii b;
        cin >> b.x >> b.y;
        if (d(a, b) % 2 == 0){
            int hd = d(a, b) / 2;
            int ax = abs(b.x);
            int ay = abs(b.y);
            if (abs(ax >= hd)){
                
            }
            cout << endl;
        }
        else{
            cout << -1 << ' ' << -1;
            cout << endl;
        }

    }
    return 0;
}