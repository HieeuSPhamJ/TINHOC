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
#define t top()
 
#define FOR(i , x , n) for(int i = x ; i <= n ; ++i)
#define FORD(i , x , n) for(int i = x ; i >= n ; --i)
#define REP(i , n) for(int i = 0 ; i < n ; ++i)
 
#define int long long
#define ll long long
#define oo 1e18

const int N = 1e6 + 5;
int q , n , k , x , y;
int a[N];
char f1[N] , f2[N];

main()
{
    //     freopen("input.inp", "r", stdin);
    // freopen("B.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> q;

    
    while(q--)
    {
        int cnt = 0;
        cin >> n >> x >> y;
        FOR(i , 1 , n)
            cin >> f1[i];
        FOR(i , 1 , n)
            cin >> f2[i];
        int r = 0;
        FOR(i , 1 , n)
            if(f1[i] != f2[i])
            {
                cnt++;
                a[++r] = i;
            }
        if(cnt % 2 == 0)
        {
            if(cnt == 2)
            {
                if(a[1] + 1 == a[2])
                {
                    if(x <= 2 * y)
                        cout << x << "\n";
                    else
                        cout << 2 * y << "\n";
                    goto l1;
                }
            }
            cout << y * cnt / 2 << "\n";
            l1:;
        }
        else
            cout << "-1" << "\n";
    }
}