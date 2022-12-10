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
        int sum = a + b + c + d;
        if (sum == 0){
            cout << 0;
        }
        else if (sum <= 3){
            cout << 1;
        }
        else if (sum == 4){
            cout << 2;
        }
        cout << endl;
    }
    return 0;
}