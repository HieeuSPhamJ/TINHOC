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

#define FOR(i , x , n) for(int i = x ; i <= n ; ++i)
#define REP(i , n) for(int i = 0 ; i < n ; ++i)
#define FORD(i , x , n) for(int i = x ; i >= n ; --i)

#define ll long long
#define oo 1e18
#define int long long

const int N = 1e6 + 5;
int q , n;
int a[N] , b[N];
vector < ii > g1 , g2 , g3;

bool cmp(ii a , ii b)
{
    return a.second < b.second;
}

main()
{
    //freopen("gen.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> q;
    while(q--)
    {
        int sum = 0;
        cin >> n;
        FOR(i , 1 , n)
            cin >> a[i];
        int ans = 0;
        FOR(i , 1 , n)
        {
            cin >> b[i];
            if(a[i] - b[i] >= 0)
                g1.push_back(ii(a[i] , b[i]));
            else if(a[i] - b[i] < 0)
                g2.push_back(ii(a[i] , b[i]));
            ans += abs(a[i] - b[i]);
        }
        sort(g1.begin() , g1.end());
        if(!g1.empty())
        {
            g3.push_back(g1[0]);
            g3.push_back(g1.back());
        }
        sort(g1.begin() , g1.end() , cmp);
        if(!g1.empty())
        {
            g3.push_back(g1[0]);
            g3.push_back(g1.back());
        }
        sort(g2.begin() , g2.end());
        if(!g2.empty())
        {
            g3.push_back(g2[0]);
            g3.push_back(g2.back());
        }
        sort(g2.begin() , g2.end() , cmp);
        if(!g2.empty())
        {
            g3.push_back(g2[0]);
            g3.push_back(g2.back());
        }
        int res = ans;
        REP(s , g3.size())
            REP(s1 , g3.size())
            {
                int a1 = g3[s].fi;
                int b1 = g3[s].se;
                int a2 = g3[s1].fi;
                int b2 = g3[s1].se;
                res = max(res , ans - abs(a1 - b1) - abs(a2 - b2) + abs(a1 - b2) + abs(a2 - b1));
            }
        cout << res << "\n";
        g1.clear();
        g2.clear();
        g3.clear();
    }
}
