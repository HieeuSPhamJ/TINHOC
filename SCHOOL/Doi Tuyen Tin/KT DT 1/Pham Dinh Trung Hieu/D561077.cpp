#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 2 * 1e5 + 10;
const int mod = 1000000531;
const int base = 256;
int POW[maxN];

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
    freopen("D561077.INP", "r", stdin);
    freopen("D561077.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    POW[0] = 1;
    for (int i = 1; i < maxN; i++){
        (POW[i] = POW[i - 1] * base) %= mod;
    }
    int n;
    cin >> n;
    hashtype s;
    cin >> s.data;
    s.init();

    // cout << s.getHash(2,4) << " " << s.getHash(9,11) << endl;

    int left = 0;
    int right = n - 1;
    int ans = -1;

    while(left <= right){
        int mid = (left + right) / 2;
        unordered_map <int,int> cnt;
        int ok = 0;
        for (int i = 1; i + mid <= n; i++){
            int now =  s.getHash(i, i + mid);
            cnt[now]++;
            if (cnt[now] >= 2){
                ok = 1;
                break;
            }
        }

        if (ok){
            left = mid + 1;
            ans = mid;
        }
        else{
            right = mid - 1;
        }
    }

    cout << ans + 1;

    return 0;
}