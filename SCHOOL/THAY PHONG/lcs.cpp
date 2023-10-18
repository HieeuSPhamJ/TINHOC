#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

int mk[3][100];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s1, s2;
    cin >> s1 >> s2;
    for (int i = 0; i < s1.length(); i++){
        mk[0][s1[i] - 'a']++;
    }
    for (int i = 0; i < s2.length(); i++){
        mk[1][s2[i] - 'a']++;
    }

    int res = 0;
    for (int i = 0; i <= 40; i++){
        // cout << char(i + 'a') << " " << mk[0][i] << " " << mk[1][i] << endl;
        if (min(mk[0][i], mk[1][i]) == 0){
            res += max(mk[0][i], mk[1][i]);
        }
    }
    cout << res << endl;
    return 0;
}

/*
*/