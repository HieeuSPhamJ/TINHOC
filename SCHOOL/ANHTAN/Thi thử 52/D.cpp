#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 1e6 + 10;
const int mod = 1000000531;
const int base = 256;

int dp[maxN];
vector <char> ans;
int POW[maxN];

int add(int a, int b){
    return (a + b) % mod;
}
int subtr(int a, int b){
    return ((a + mod) - b) % mod; 
}
int mul(int a, int b){
    return (a * b) % mod;
}

void addChar(int i, char s){
    ans.push_back(s);
    (dp[i] = dp[i - 1] * base + s) %= mod;
}

int getHash(int left, int right){
    int len = (right - left + 1);
    int hash = subtr(dp[right], mul(dp[left - 1], POW[len]));
    return hash;
}

struct hashtype{
    string data;
    vector <int> ha;
    int len;
    void init(){
        len = data.length();
        ha.resize(len + 3);
        ha[0] = 0;
        for (int i = 0; i < len; i++){
            (ha[i + 1] = ha[i] * base + data[i]) %= mod;
        }
    }
    int getHash(int left, int right){
        return (ha[right] - (ha[left - 1] * POW[right - left + 1]) % mod + mod) % mod;
    }
};

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    POW[0] = 1;
    for (int i = 1; i <= 1e6; i++){
        (POW[i] = POW[i - 1] * base) %= mod;
    }
    ans.push_back('!');
    for (int i = 1; i <= n; i++){
        hashtype s;
        cin >> s.data;
        // cout << s.data << endl;
        s.init();
        if ((int)ans.size() == 1){
            // cout << "CAC";
            // cout << s.len;
            for (int j = 0; j < s.len; j++){
                addChar(ans.size(), s.data[j]);
                // cout << s.data[j] << " ";
            }
            // cout << endl;
            continue;
        }
        int ansLen = ans.size() - 1;
        int last = max(1ll, ansLen - s.len + 1);
        int id = 0;
        for (int j = ansLen; j >= last; j--){
            int hash1 = getHash(j, ansLen);
            int hash2 = s.getHash(1,ansLen - j + 1);
            // cout << j << " " << ansLen << ": " << hash1 << endl;
            // cout << 1 << " " << ansLen - j + 1 << ": " << hash2 << endl;
            if (hash1 == hash2){
                id = ansLen - j + 1;
                // break;
            }
        }
        // cout << id << endl;

        for (int j = id; j < s.len; j++){
            addChar(ans.size(),s.data[j]);
        }
    }
    
    for (int i = 1; i < ans.size(); i++){
        cout << ans[i];
    }

    // hashtype x;
    // x.data = "abcdef";
    // x.init();
    // cout << x.len;
    return 0;
}

/*
de
abcde
650680402
97 24930 6382179 633837393 262286687 145356397
*/