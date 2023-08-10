#include<bits/stdc++.h>
#define int long long
#define ii pair <int,int>
#define f first
#define s second
using namespace std;

const int maxN = 2 * 1e5 + 10;

int a[maxN];

main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n, k;
        cin >> n >> k;
        a[0] = 0;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        
        int temp = 0;
        int count = 0;
        int len = 1;

        for (int i = 2; i <= n; i++){
            if (a[i] * 2 > a[i - 1]){
                len++;
            }
            else{
                len = 1;
            }
            if (len >= k + 1){
                count++;
            }
            // cout << len << ' ';
        }
        // cout << endl;

        cout << count;

        cout << endl;
    }
    

    return 0;
}


