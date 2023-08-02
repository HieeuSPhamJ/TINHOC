#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define MOD 1000000000
#define INF 1e18
#define fi first
#define se second
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define sz(a) ((int)(a).size())
#define endl '\n'
#define pi 3.14159265359
#define TASKNAME "assign"
template<typename T> bool maximize(T &res, const T &val) { if (res < val){ res = val; return true; }; return false; }
template<typename T> bool minimize(T &res, const T &val) { if (res > val){ res = val; return true; }; return false; }
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
const int MAXN = 1e6 + 9;
int n,m,a[5001],b[5001],SPF[MAXN];

unordered_map<int,int> factor1,factor2;
vector<int> prime;
set<int> stprime;
void sieve(int n){
    iota(SPF+1,SPF+1+n,1);
    for(int i=2;i<=n;i++){
        if (SPF[i] == i){
            prime.pb(i);
            for(int j=i*i;j<=n;j+=i){
                SPF[j] = i;
            }
        }
    }
//    for(auto x: prime){
//        cout<<x<<' ';
//    }
//    cout<<endl;
}
int power(int a,int b){
    int res = 1;
    while(b>0){
        if (b&1) res = (res * a) % MOD;
        b>>=1;
        a = (a * a ) % MOD;
    }
    return res;
}
bool isgreater(int ans,int a,int b){
    for(int i=1;i<=b;i++){
        ans = ans * a;
//        cout<<ans<<endl;
        if (ans >= 1e9) return true;
    }
    return false;
}
signed main()
{
    fast;
    freopen("input.inp", "r", stdin);
    freopen("B.out", "w", stdout);
    cin>>n;
    sieve(1000000);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if (a[i] <= 1000000){
            int tmp = a[i];
            while(tmp>1){
                int x = SPF[tmp];
                if (stprime.find(x) == stprime.end()) stprime.insert(x);
                while(tmp % x == 0){
                    tmp /= x;
                    factor1[x]++;
                }
            }
        }
        else{
            int tmp = a[i];
//            cout<<tmp<<endl;
            for(auto p: prime){
                if (p*p > a[i]) break;
                if (tmp%p == 0){
                    if (stprime.find(p) == stprime.end()) stprime.insert(p);
                    while(tmp % p == 0){
                        factor1[p]++;
//                        cout<<p<<' ';
                        tmp/=p;
                    }
                }

            }
//            cout<<endl;
//            cout<<tmp<<endl;
            if (tmp>1) stprime.insert(tmp), factor1[tmp]++;
        }
    }
    cin>>m;
     for(int i=1;i<=m;i++){
        cin>>b[i];
        if (b[i] <= 1000000){
            int tmp = b[i];
            while(tmp>1){
                int x = SPF[tmp];
                if (stprime.find(x) == stprime.end()) stprime.insert(x);
                while(tmp % x == 0){
                    tmp /= x;
                    factor2[x]++;
//                    cout<<tmp<<' ';
                }
//                cout<<endl;
            }
        }
        else{
            int tmp = b[i];
            for(auto p: prime){
                if (p*p > b[i]) break;
                if (tmp % p == 0){
                    if (stprime.find(p) != stprime.end()) stprime.insert(p);

                    while(tmp % p == 0){
                        factor2[p]++;
                        tmp/=p;
                    }

                }
            }
//            cout<<tmp<<endl;
            if (tmp>1) stprime.insert(tmp), factor2[tmp]++;
        }
    }
    int ans = 1;
//    cout<<endl;
    bool great = false;
    for(auto s: stprime){
        int co = min(factor1[s],factor2[s]);
        if (!great && isgreater(ans,s,co)) great = true;
//        cout<<s<<' '<<co<<' '<<factor1[s]<<' '<<factor2[s]<<' '<<great<<endl;
        if (great) ans = (ans * power(s,co))%MOD;
        else{
            for(int j=1;j<=co;j++){
                ans = ans * s;
            }
        }
    }
    if (great){
        printf("%09d%",ans);
        // cout << '\n';
    }
    else cout<<ans;
}

