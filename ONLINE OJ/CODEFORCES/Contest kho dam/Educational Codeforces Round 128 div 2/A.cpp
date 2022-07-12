#include<bits/stdc++.h>
#define ii pair <int,int>
#define f first
#define s second
#define ll long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (max(a, c) <= min(b, d)){
            cout << max(a, c);
        }
        else{
            cout << b + d;
        }
        cout << endl;

    }
    return 0;
}
