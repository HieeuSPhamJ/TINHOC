#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
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
        vector <int> lists;
        for (int i = n; i >= 1; i--){
            // cout << i << ' ';
            lists.push_back(i);
        }
        for (int j = 0; j < n; j++){
            cout << lists[j] << ' ';
        }
        cout << endl;
        for (int i = 1; i < n; i++){
            swap(lists[i], lists[i - 1]);
            for (int j = 0; j < n; j++){
                cout << lists[j] << ' ';
            }
            cout << endl;
            swap(lists[i], lists[i - 1]);
        }
        // cout << endl;
    }
    return 0;
}