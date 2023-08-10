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
        int left, right, a;
        cin >> left >> right >> a;
        if (right == left){
            cout << right / a + right % a;
            cout << endl;
            continue;
        }
        if (right % a == 0){
            cout << max(right / a, (right - 1) / a + (right - 1) % a);
            cout << endl;
            continue;
        }

        int newRight = (right / a) * a;
        if (newRight < left){
            newRight = right;
        }

        cout << max({
            newRight / a + newRight % a,
            (newRight - 1) / a + (newRight - 1) % a,
            right / a + right % a,
        });

        cout << endl;
    }
    return 0;
}