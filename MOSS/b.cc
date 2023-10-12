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
#define oo 1e9
#define eps 1e-8
#define div divv
#define pow poww
#define int long long

const int N = 1e6 + 5;
int n , m , x1 , x2 , y1 , y2 , q , k , x , K;
int a[N] , b[N] , c[N] , p[N];



main()
{
    //freopen("gen.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> q;
    while(q--)
    {
        cin >> n;
        // 1 + 2 + 4

        bool ok = false;
        int x = n / 3;
        for(int i = x - 10 ; i <= x + 10 ; i++)
            for(int j = i + 1 ; j <= x + 10 ; j++)
                for(int k = j + 1 ; k <= x + 10 ; k++)
                    if(i > 0 && j > 0 && k > 0 && i % 3 != 0 && j % 3 != 0 && i != j && j != k && k % 3 != 0 && i + j + k == n)
                    {
                        cout << "YES" << "\n";
                        cout << i << " " << j << " " << k <<  "\n";
                        ok = true;
                        goto l1;
                    }
        if(!ok)
            cout << "NO" << "\n";
        l1:;
    }
}
