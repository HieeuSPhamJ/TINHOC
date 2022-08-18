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
        int a, b;
        cin >> a >> b;
        int count = 0;
        while(a != b){
            if (a < b){
                swap(a, b);
            }
            // cout << "Turn: " << a << " " << b << endl;
            int left = 0;
            int right = 1e9;
            int turnCut = 1e9;
            while(left <= right){
                int mid = (left + right) / 2;
                // cout << left << " " << mid << " " << right << endl;
                if (a - (b * mid) > b){
                    turnCut = mid;
                    left = mid + 1;
                }
                else{
                    right = mid - 1;
                }
            }
            turnCut++;
            // cout << turnCut << endl;
            a = a - (b * turnCut);
            count += turnCut;
        }
        cout << count << endl;

    }
    return 0;
}