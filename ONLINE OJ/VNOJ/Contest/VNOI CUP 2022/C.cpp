#include<bits/stdc++.h>
#define int long long
#define ii pair <int,int>
#define f first
#define s second
using namespace std;

const int maxN = 1e6 + 10;

string a[maxN];
map <string, int> checkMap;

main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++){
        cin >> a[i];
        checkMap[a[i]] = 1;
    }

    int limit = 10;

    for (int i = 1; i <= n; i++){
        int count = 0;
        // cout << a[i] << ' ' << checkMap[a[i]] << endl;
        // checkMap[a[i]] = 0;
        // a[i] += a[i][0];
        // checkMap[a[i]]++;
        // cout << a[i] << ' ' << checkMap[a[i]] << endl;
        while(checkMap[a[i]] == 1){
            // checkMap[a[i]]--;
            count++;
            a[i] += a[i][0];
            // checkMap[a[i]]++;
            // cout << a[i] << ' ' << checkMap[a[i]] << endl;
        }
        // cout << a[i] << ' ';
        cout << count << endl;
        // cout << endl;
    }
    



    return 0;
}
