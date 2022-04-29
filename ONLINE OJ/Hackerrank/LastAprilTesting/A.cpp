#include <bits/stdc++.h>
using namespace std;

int main(){
    int test;
    cin >> test;
    while (test--){
        string s;
        long long n;
        cin >> s >> n;
        string sr;
        for (int i = s.size() - 1; i >= 0; i--){
            sr += s[i];
        }
        // cout << s << sr;
        s += sr;
        n--;
        n = n % s.size();
        cout << s[n];

        cout << endl;
    }

    return 0;
}