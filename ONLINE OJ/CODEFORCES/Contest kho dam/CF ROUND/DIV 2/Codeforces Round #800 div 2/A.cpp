#include<bits/stdc++.h>
#define int long long
#define ii pair <int,int>
#define f first
#define s second
using namespace std;

main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int a, b;
        cin >> a >> b;
        for (int i = 1; i <= b; i++){
            cout << '1';
        }
        for (int i = 1; i <= a; i++){
            cout << '0';
        }
        cout << endl;
    }
    return 0;
}