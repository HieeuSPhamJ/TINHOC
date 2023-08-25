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
#define int long long

#define FOR(i , x , n) for(int i = x ; i <= n ; ++i)
#define REP(i , n) for(int i = 0 ; i < n ; ++i)
#define FORD(i , x , n) for(int i = x ; i >= n ; --i)

#define oo 1e18
#define int long long

const int N = 1e6 + 5;
int n , q , x , y , z , m , d , w , f;
int a[N] , b[N];
string s = "vika";
bool dp[N];

void debug(multiset < int > s)
{
    cout << "======" << endl;
    for(auto it = s.begin() ; it != s.end() ; it++)
        cout << *(it) << " ";
    cout << endl << "======" << endl;
}

main()
{
    //freopen("test.inp", "r", stdin);
	//freopen("1.ans", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int qq;
    cin >> qq;
    while(qq--)
    {
        cin >> n;
        multiset < int > s , st;
        FOR(i , 1 , n)
        {
            cin >> a[i];
            s.insert(a[i]);
            b[i] = a[i];
        }
        sort(b + 1 , b + 1 + n);
        FOR(i , 2 , n)
            st.insert(b[i] - b[i - 1]);
        cin >> q;
//                    debug(s);
//            debug(st);
        FOR(i , 1 , q)
        {
            int pos , val;
            cin >> pos >> val;
            //cout << pos << " " << val << endl;
            auto it = s.find(a[pos]);
            int x = -1;
            int y = -1;
            if(it != s.begin()){
                auto it1 = it;
                it1--;
                x = *it1;
            }
            auto it1 = it;
            it1++;
            if(it1 != s.end())
                y = *(it1);
            if(x != -1)
                st.erase(st.find(a[pos] - x));
            if(y != -1)
                st.erase(st.find(y - a[pos]));
            if(x != -1 && y != -1)
                st.insert(y - x);
            s.erase(s.find(a[pos]));
//            cout << "cac" << endl;
//            debug(s);
//            debug(st);


            a[pos] = val;
            s.insert(a[pos]);

            it = s.find(a[pos]);
            x = -1;
            y = -1;
            if(it != s.begin())
            {
                auto it1 = it;
                it1--;
                x = *it1;
            }
            it1 = it;
            it1++;
            if(it1 != s.end())
                y = *(it1);
            if(x != -1)
                st.insert(a[pos] - x);
            if(y != -1)
                st.insert(y - a[pos]);
            if(x != -1 && y != -1)
                st.erase(st.find(y - x));

//                            cout << "cac" << endl;
//            debug(s);
//            debug(st);

            it = s.end();
            it--;
            int ans = *(it);
            x = 0;
            if(!st.empty())
            {
                auto it = st.end();
                it--;
                x = *it;
            }
            cout <<  ans + x << " ";
            //cout << "cac" << endl;
        }
        cout << "\n";
    }
}
