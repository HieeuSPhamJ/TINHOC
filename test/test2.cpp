#include <iostream>

using namespace std;

int n;
long long m;
long long a[501], b[501], t[501];
bool type[501];
long long ansTime = 1000000000000000000;

void dfs( int d, long long sum, long long count ) {
    cout<<sum<<' '<<d<<' '<<count<<' '<<endl;
    if ( d == n ) {
        if ( sum <= m ) {
            if ( ansTime == 1000000000000000000 || ansTime > count ) {
                ansTime = count;
            }
        }
    }
    else {
        
        dfs( d + 1, sum + a[d], count );
        dfs( d + 1, sum + b[d], count + t[d] );
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> t[i];
    }

    dfs( 0, 0, 0 );

    // if ( ansTime == 1000000000000000000 ) {
    //     cout << -1;
    // }
    // else {
    //     cout << ansTime;
    // }


    return 0;
}