#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

void ttt(int len1, int len2){
    if (len1 > len2){
        cout << '<' << endl;
    }
    else if (len1 < len2){
        cout << '>' << endl;
    }
    else{
        cout << '=' << endl;
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s1, s2;
    int len1, len2;
    map <char, int> conv;
    conv['S'] = 1;
    conv['M'] = 2;
    conv['L'] = 3;
    int test;
    cin >> test;
    while (test--){
        cin >> s1 >> s2;
        len1 = s1.length();
        len2 = s2.length();
        
        if (conv[s1[len1 - 1]] < conv[s2[len2 - 1]]){
            cout << '<' << endl;
        }
        else if (conv[s1[len1 - 1]] > conv[s2[len2 - 1]]){
            cout << '>' << endl;
        }
        else{
            if (s1[len1 - 1] == 'S'){
                ttt(len1, len2);
            }
            else if (s1[len1 - 1] == 'L'){
                ttt(len2, len1);
            }
            else{
                cout << '=' << endl;
            }
        }
    }
    return 0;
}