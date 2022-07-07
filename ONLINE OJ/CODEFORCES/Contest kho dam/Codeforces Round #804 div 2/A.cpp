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
        ll n;
        cin >> n;

        if (n % 2 == 1){
            cout << -1;
        }
        else{
            cout << n / 2 << ' ' << 0 << ' ' << 0;
        }
        cout << endl;
    }

    

    return 0;
}