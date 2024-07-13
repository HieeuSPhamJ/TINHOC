#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define MOD 1000000007
#define inf 1e18
#define fi first
#define se second
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define sz(a) ((int)(a).size())
#define endl '\n'
#define pi 3.14159265359
#define TASKNAME "ngoacdung"
template<typename T> bool maximize(T &res, const T &val) { if (res < val){ res = val; return true; }; return false; }
template<typename T> bool minimize(T &res, const T &val) { if (res > val){ res = val; return true; }; return false; }
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;

int cnt[2][11][2][2], dp1[2][11][2][2], dp2[2][11][2][2];
map<int, ii> solved;

//cnt[i][j][start][flag]
string str;

int changeBalance(int x){
    return ((x&1) ? -1 : 1);
}

void add(int &a, int b){
     a += b;
     if (a >= MOD) a -= MOD;
}

int mul(int a, int b){
    return (a * b) % MOD;
}

int cong(int a, int b){
    return (a + b) % MOD;
}

int tru(int a, int b){
    return ((a - b) % MOD + MOD) % MOD;
}
ii solve(int num){

     str = to_string(num);


     memset(cnt, 0, sizeof(cnt));
     memset(dp1, 0, sizeof(dp1));
     memset(dp2, 0, sizeof(dp2));
     cnt[0][0][0][1] = 1;

     dp1[0][0][0][1] = 0;
     dp2[0][0][0][1] = 0;
     int n = str.length();

     for(int i = 0; i <= str.length(); i++){
         int ii = i&1;
         memset(cnt[!ii], 0, sizeof(cnt[!ii]));
         memset(dp1[!ii], 0, sizeof(dp1[!ii]));
         memset(dp2[!ii], 0, sizeof(dp2[!ii]));

         for(int balance = 0; balance <= str.length() / 2 + 1; balance++){
             for(int start = 0; start < 2; start++){
                 for(int flag = 0; flag < 2; flag++){
                     if (cnt[ii][balance][start][flag]){
//                         cout << i << ' ' << balance << ' ' << start << ' ' << flag << ' '
//                              << cnt[ii][balance][start][flag] << ' ' << dp1[ii][balance][start][flag] << ' ' << dp2[ii][balance][start][flag] << endl;

                         if (i == str.length()) continue;
                         int mnc = 0, mxc = 9;

                         if (flag) mxc = (str[i] - '0');
                         int nxtstart = 0, nxtbalance = 0, nxtflag = 0;


                         for(int nxtc = mnc; nxtc <= mxc; nxtc++){
                             nxtstart = ((nxtc > 0) ? 1 : start);

                             if (nxtstart > 0) nxtbalance = balance + changeBalance(nxtc);

                             nxtflag = (flag and mxc == nxtc);
                             if (nxtbalance >= 0){
                                 add(cnt[!ii][nxtbalance][nxtstart][nxtflag], cnt[ii][balance][start][flag]);
                                 add(dp1[!ii][nxtbalance][nxtstart][nxtflag],
                                     cong(mul(10, dp1[ii][balance][start][flag]), mul(cnt[ii][balance][start][flag], nxtc)));

                                 int bonus1 = mul(100, dp2[ii][balance][start][flag]);
                                 int bonus2 = mul(20, mul(nxtc, dp1[ii][balance][start][flag]));
                                 int bonus3 = mul(cnt[ii][balance][start][flag], nxtc * nxtc);

//                                 cout << bonus1 << ' ' << bonus2 << ' ' << bonus3 << endl;

                                 add(dp2[!ii][nxtbalance][nxtstart][nxtflag], bonus1);
                                 add(dp2[!ii][nxtbalance][nxtstart][nxtflag], bonus2);
                                 add(dp2[!ii][nxtbalance][nxtstart][nxtflag], bonus3);

                             }
                         }
                     }
                 }
             }
         }
     }

     return ii(cong(cnt[str.length()&1][0][1][0], cnt[str.length()&1][0][1][1]),
               cong(dp2[str.length()&1][0][1][0], dp2[str.length()&1][0][1][1]) );
}
main()
{
    fast;
    if (fopen("input.inp","r")){
        freopen("input.inp","r",stdin);
        freopen("B.out","w",stdout);
    }
    int t;

    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        ii solve1, solve2;
//        solve2 = solve(b);
//        solve1 = solve(a - 1);
//        cout << solve1.fi << ' ' << solve1.se << endl;

        auto it = solved.find(b);
        if (it != solved.end()) solve2 = it->se;
        else solve2 = solve(b);

        solved[b] = solve2;


        it = solved.find(a - 1);
        if (it != solved.end()) solve1 = it->se;
        else solve1 = solve(a - 1);

        solved[a - 1] = solve1;


        cout << tru(solve2.fi, solve1.fi) << ' ' << tru(solve2.se, solve1.se) << endl;
    }
}