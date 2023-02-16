#include<bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector <int>
#define fi first
#define se second
#define ii pair<int , int>
#define FOR(i , a , b) for(int i = a ;i <= b ; i += 1)
#define FORD(i , a , b) for(int i = a ;i >= b ; i -= 1)
#define REP(i , a) for(int i = 0 ;i < a ; i += 1)

const int oo = 1e9 + 7;
const int MOD = 1e9 + 7;

int n , d;
string s;
int Hash1[50005] , Hash2[50005];
int Pow1[50005] , Pow2[50005];
int base1 = 31 , base2 = 257;
vi res;

int get1(int i , int j){
    return (Pow1[j - i + 1] * Hash1[i - 1] - Hash1[j] + MOD) % MOD;
}

int get2(int i , int j){
    return (Pow2[j - i + 1] * Hash2[i - 1] - Hash2[j] + MOD) % MOD;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("KSTRING.inp" , "r" , stdin);
    freopen("KSTRING.out" , "w" , stdout);
    cin >> n >> d >> s;
    s = "*" + s;
    if(d == 0){
        Pow1[0] = 1; Pow2[0] = 1;
        FOR(i , 1 , n){
            Pow1[i] = (Pow1[i - 1] * base1) % MOD;
            Pow2[i] = (Pow2[i - 1] * base2) % MOD;
            Hash1[i] = (Hash1[i - 1] * base1 + (s[i] - 'a' + 1)) % MOD;
            Hash2[i] = (Hash2[i - 1] * base2 + (s[i] - 'a' + 1)) % MOD;
        }
        int dem , ans;
        FOR(i , 1 , n){
            if(n / i == 1){
                cout << "0 ";
                continue;
            }
            res.clear();
            for(int j = 1 ; j <= n ; j += i) {
                if(j + i - 1 > n) break;
                res.push_back((get1(j , j + i - 1) << 30) + get2(j , j + i - 1));
            }
            sort(res.begin() , res.end());
            res.push_back(0);
            dem = 1; ans = 0;
            FOR(i , 1 , res.size() - 1){
                if(res[i] == res[i - 1]) dem += 1;
                else {
                    ans += dem * (dem - 1) / 2;
                    dem = 1;
                }
            }
            cout << ans << ' ';
        }
    }
    else if(n == 1) cout << 0;
    else {
        cout << n * (n - 1) / 2 << ' ';
        FOR(i , 2 , n) cout << "0 ";
    }
    return 0;
}
