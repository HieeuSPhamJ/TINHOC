#include<bits/stdc++.h>
#define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;


template<class A, class B> bool maximum(A& x, B y) {if (x < y) return x = y, true; else return false;}
template<class A, class B> bool minimize(A& x, B y) {if (x > y) return x = y, true; else return false;}

const int maxN = 1e6;

int n, m, d;
int a[maxN];
int b[maxN];
string s;

signed main(){
  //freopen("input.INP", "r", stdin);
  //freopen("output.OUT", "w", stdout);
  if (fopen(".inp", "r")) {
    freopen(".inp", "r", stdin);
    freopen(".out", "w", stdout);
  }
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m >> d;

        for (int i = 1; i <= n; i ++){
                cin >> a[i];
        }

        for (int i = 1; i <= n; i ++){
                cin >> b[i];
        }

        cin >> s;

        int presuffix = 0;
        for (int len = s.size() - 1; len >= 1; len --){
                bool check = true;
                for (int i = 0; i < len; i ++){
                        if (s[i] != s[s.size() - len + i]){
                                check = false;
                                break;
                        }
                }
                if (check){
                        presuffix = len;
                        break;
                }
        }

        int cntprer = count(all(s), 'R');
        int cntpreb = count(all(s), 'B');
        int cntsuffixr = count(s.begin() + presuffix, s.end(), 'R');
        int cntsuffixb = count(s.begin() + presuffix, s.end(), 'B');
        
        // cout << cntpreb << " " << cntprer << " " << cntsuffixb << " " << cntsuffixr << "\n";
        int ans = -(2e9 + 10);
        int save = 0;

        for (int i = 1; i <= n; i ++){
                int cost = - a[i] - b[n - i];
                int u = 0;
                int v = 0;
                if (i >= cntprer && n - i >= cntpreb){
                        cost += d;
                        for (int j = i - cntprer, k = n - i - cntpreb; j >= cntsuffixr && k >= cntsuffixb; j -= cntsuffixr, k -= cntsuffixb){
                                cost += d;
                        }
                }
                if (maximum(ans, cost)){
                        save = i;
                }
        }

        cout << ans << "\n";
        cout << s;
        int p = save - cntprer, q = n - save - cntpreb;
        for ( ; p >= cntsuffixr && q >= cntsuffixb; p -= cntsuffixr, q -= cntsuffixb){
                // if (presuffix == 0)break;
                for (int j = presuffix; j < s.size(); j ++){
                        cout << s[j];
                }
        }
        while (p > 0)cout << "R", p--;
        while (q > 0)cout << "B", q--;
  return 0;
}