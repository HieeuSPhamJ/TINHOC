#include<bits/stdc++.h>
#define int long long
#define endl '\n'
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
        if (a == 0 and b == 0){
            cout << 0;
            cout << endl;
            continue;
        }
        double x = a;
        double y = b;
        double dirD = sqrt(x * x + y * y);
        int dirI = sqrt(a * a + b * b);

        // cout << dirD << endl;

        if (dirD == double(dirI)){
            cout << 1;
            cout << endl;
            continue;
        }
        cout << 2;
        cout << endl;
        

    }

    return 0;
}