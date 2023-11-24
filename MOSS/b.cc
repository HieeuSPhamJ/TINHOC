#include<bits/stdc++.h>
using namespace std;

#define y1 as214
#define ii pair < int , int >
#define iii pair < int , ii >
#define iv pair < ii , ii >

#define fi first
#define se second
#define fr front()
#define pb push_back

#define FOR(i , x , n) for(ll i = x ; i <= n ; ++i)
#define REP(i , n) for(ll i = 0 ; i < n ; ++i)
#define FORD(i , x , n) for(ll i = x ; i >= n ; --i)

#define ll long long
#define oo INT_MAX
#define eps 1e-8
#define div divv
#define pow poww
#define int long long

const int N = 1e6 + 5;
int q , m , k , n , x , y , x1 , x2 , y1 , y2;
int a[N] , b[N] , c[N] , cnt[N] , pre[N];
string s;
char f1[N] , f[N] , f2[N];
map < int , int > mp;

main()
{
    //freopen("gen.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> q;
    while(q--)
    {
        cin >> n;
        FOR(i , 1 , n)
            cin >> a[i];
        int mini = *min_element(a + 1 , a + 1 + n);
        int maxi = *max_element(a + 1 , a + 1 + n);
        int cnt = 0;
        vector < int > ans;
        while(mini != maxi)
        {
            if(maxi % 2 == 0 && mini % 2 == 1)
            {
                mini = (mini + 1) / 2;
                maxi = (maxi + 1) / 2;
                cnt++;
                ans.push_back(1);
            }
            else
            {
                mini /= 2;
                maxi /= 2;
                cnt++;
                ans.push_back(0);
            }
        }
        cout << cnt << "\n";
        if(!ans.empty() && ans.size() <= n)
        {
            REP(s , ans.size())
                cout << ans[s] << " ";
            cout << "\n";
        }
    }
}

