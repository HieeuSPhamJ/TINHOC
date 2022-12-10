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
        string s;
        char t;
        cin >> s >> t;
        int check = 0;
        for (int i = 0; i < s.length(); i+=2){
            if (t == s[i]){
                check = 1;
            }
        }

        if (check == 0){
            cout << "NO";
        }
        else{
            cout << "YES";
        }

        cout << endl;
    }

    return 0;
}