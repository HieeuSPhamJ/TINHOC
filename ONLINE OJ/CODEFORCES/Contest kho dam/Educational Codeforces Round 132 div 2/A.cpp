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
        int a[5];
        for (int i = 0; i <= 3; i++){
            cin >> a[i];
        }
        int count = 0;
        int temp = a[0];
        while(a[temp] != -1){
            // cout << temp << " " << a[temp] << endl;
            int t = temp;
            
            if (temp != 0){
                count++;
            }
            temp = a[temp];
            a[t] = -1;
            
        }
        if (count == 3){
            cout << "YES";
        }
        else{
            cout << "NO";
        }
        cout << endl;
    }
    return 0;
}