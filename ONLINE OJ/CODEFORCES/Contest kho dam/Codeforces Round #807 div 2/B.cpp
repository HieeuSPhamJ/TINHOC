#include<bits/stdc++.h>
#define ii pair <int,int>
#define f first
#define s second
#define int long long
using namespace std;

const int maxN = 2 * 1e5 + 10;

int a[maxN];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }

        int index = 1;
        while(a[index] == 0 and index < n){
            index++;
        }
        // cout << index << ' ';
        int count = 0;
        for (int i = index; i < n; i++){
            if (a[i] == 0){
                count++;
            }
            else{
                count += a[i];
            }
        }
        cout << count << endl;
    }
    return 0;
}