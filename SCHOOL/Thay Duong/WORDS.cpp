#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

int cnt[200][200];

signed main(){
    freopen("WORDS.INP", "r", stdin);
    freopen("WORDS.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        string s;
        cin >> s;
        cnt[s[0]][s[s.length() - 1]]++;
    }
    int res = 0;
    for (int s1 = 'A'; s1 <= 'Z'; s1++){
    for (int s2 = 'A'; s2 <= 'Z'; s2++){   
    for (int s3 = 'A'; s3 <= 'Z'; s3++){
    for (int s4 = 'A'; s4 <= 'Z'; s4++){
        // cout << s1 << " " << s2 << " " << s3 << " " << s4 << ": " << endl;
        int t = cnt[s1][s2];
        cnt[s1][s2]--;
        t *= cnt[s2][s3];
        cnt[s2][s3]--;
        t *= cnt[s4][s3];
        cnt[s4][s3]--;
        t *= cnt[s1][s4];

        cnt[s1][s2]++;
        cnt[s2][s3]++;
        cnt[s4][s3]++;
        res += t;
        
    }       
    }        
    }
    }

    cout << res << endl;
    return 0;
}