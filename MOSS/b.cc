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
#define pp pop_back()
#define t top()
#define int int

#define FOR(i , x , n) for(int i = x ; i <= n ; ++i)
#define REP(i , n) for(int i = 0 ; i < n ; ++i)
#define FORD(i , x , n) for(int i = x ; i >= n ; --i)

#define oo 1e18
#define int long long

const int N = 1e6 + 5;
int q , n , m , sum;
int a[N] , b[N] , c[N];

main()
{
    //freopen("test.inp", "r", stdin);
	//freopen("1.ans", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> q;
    while(q--)
    {
        cin >> n;

        int m = n * (n - 1) / 2;
        FOR(i , 1 , m)
            cin >> b[i];
        sort(b + 1 , b + 1 + m , greater < int > ());
        a[1] = 1e9;
        int sum = 1;
        for(int i = 2 ; i <= n ; i++)
        {
            a[i] = b[sum];
            sum += i;
        }
        FOR(i , 1 , n)
            cout << a[i] << " ";
        cout << "\n";
    }

}
