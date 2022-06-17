#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define ii pair <int,int>
#define f first
#define s second
using namespace std;

const int maxN = 220;

int a[maxN];

main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }

        // cout << s << endl;

        int count = 0;

        string t = s;
        
        while (t != s or count == 0){
            string temp = t;
            for (int i = 0; i < (int)t.size(); i++){
                t[i] = temp[a[i] - 1];
            }
            // cout << t << endl;
            count++;
        }

    cout << count << endl;

    }

    return 0;
}