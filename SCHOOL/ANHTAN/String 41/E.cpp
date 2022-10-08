#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 1e6 + 10;
const int base = 256;
const int mod =  1e9 + 7;

int n, m;
string s1, s2;
int dp[3][maxN];
int po[maxN];

int add(int a, int b){
    return (a + b) % mod;
}
int subtr(int a, int b){
    return ((a + mod) - b) % mod; 
}
int mul(int a, int b){
    return (a * b) % mod;
}

void init(){
    po[0] = 1;
    for (int i = 0; i < n; i++){
        dp[0][i + 1] = add(mul(dp[0][i], base), (int)(s1[i]));
        po[i + 1] = mul(po[i], base);
    }
    for (int i = 0; i < m; i++){
        dp[1][i + 1] = add(mul(dp[1][i], base), (int)(s2[i]));
        po[i + 1] = mul(po[i], base);
    }
}

int getHash(int type, int left, int right){
    int len = (right - left + 1);
    left--;
    int hash = subtr(dp[type][right], mul(dp[type][left], po[len]));
    return hash;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    cin >> s1 >> s2;
    init();

    int test;
    cin >> test;
    while(test--){
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        int len1 = (r1 - l1 + 1);
        int len2 = (r2 - l2 + 1);
        cout << len1 << " " << len2 << endl;
        cout << s1.substr(l1 - 1, len1) << " " << s2.substr(l2 - 1, len2) << endl;
        // if (len2 != len1){
        //     if (len1 > len2){
        //         cout << ">";
        //     }
        //     else{
        //         cout << "<";
        //     }
        //     continue;
        // }
        int left = 0;
        int right = min((r1 - l1), (r2 - l2));
        int id = -1;
        while (left <= right){
            int mid = (left + right) / 2;
            int hash1 = getHash(0,l1, l1 + mid);
            int hash2 = getHash(1,l2, l2 + mid);
            cout << mid << " " << s1.substr(l1 - 1, mid + 1) << " " << s2.substr(l2 - 1, mid + 1) << endl;
            // cout << hash1 << " " << hash2 << endl;
            if (hash1 == hash2){
                left = mid + 1;
                id = max(id, mid);
            }
            else{
                right = mid - 1;
            }
        }
        cout << id << endl; 
        if (len1 != len2){
            // cout << (r1 - l1) << endl;
            if (id == (r1 - l1)){
                if (len1 > len2){
                    cout << ">";
                }
                else{
                    cout << "<";
                }
            }
            else if (s1[l1 + id] > s2[l2 + id]){
                cout << ">";
            }
            else {
                cout << "<";
            }
            continue;
        }
        // cout << s1[l1 + id] << " " << s2[l2 + id] << endl;
        if (id == (r1 - l1)){
            cout << "=";
        }
        else if (s1[l1 + id] > s2[l2 + id]){
            cout << ">";
        }
        else {
            cout << "<";
        }
        // cout << endl;
    }
    
    return 0;
}