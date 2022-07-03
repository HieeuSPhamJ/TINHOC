#include<bits/stdc++.h>
#define ii pair <int,int>
#define f first
#define s second
using namespace std;

int main(){
    // freopen("MAHOA.INP", "r", stdin);
    // freopen("MAHOA.OUT", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k = 2;
    cin >> k;
    string s;
    // getline(cin, s);
    while(cin >> s){
    for (int i = 0; i < s.size(); i++){
        char n = s[i];
        if (n == ' '){
            cout << ' ';
            continue;
        }
        if (n >= 'a' and n <= 'z'){
            char newN = char(n + k);
            // cout << newN;
            if (newN > 'z'){
                newN -= 'z';
                cout << char('a' + newN - 1);
            }
            else{
                cout << char(newN);
            }

        }
        else if (n >= 'A' and n <= 'Z'){
            int newN = n + k;
            // cout << newN;
            if (newN > 'Z'){
                newN -= 'Z';
                cout << char('A' + newN - 1);
            }
            else{
                cout << char(newN);
            }
        }
        else{
            cout << n;
        }
        // cout << ' ';
    }
    cout << ' ';
    }

    return 0;
}