#include<bits/stdc++.h>
#define ii pair <int,int>
#define f first
#define s second
#define int long long
using namespace std;

const int maxN = 1e5 + 10;

string s[maxN];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        map <string, bool> mapCheck;
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> s[i];
            // cout << s[i] << endl;
            mapCheck[s[i]] = 1;
        }

        for (int i = 1; i <= n; i++){
            string tempS = s[i];
            int check = 0;
            for (int i = 1; i < tempS.length(); i++){
                string t1 = tempS.substr(0, i);
                string t2 = tempS.substr(i);
                // cout << t1 << ' ' << t2 << endl;
                if (mapCheck[t1] == 1 and mapCheck[t2] == 1){
                    check = 1;
                    break;
                }
            }
            cout << check;
        }
        cout << endl;
    }
    return 0;
}