#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int one = 0;
    int zero = 0;
    int res = 0;
    for (int i = 1; i <= n; i++){
        char x;
        cin >> x;
        // cout << zero << " " << one << endl;
        if (x == '0'){
            // cout << i << ": " << one + zero << endl;
            one += zero;
            zero = 1;
            res += one;
        }
        else{
            swap(zero,one);
            one++;
            // cout << i << ": " << one << endl;
            res += one;
        }
        
    }
    cout << res << endl;
    return 0;
}

/*
10101
010
10
100



1 1
1 2
2 3
3 3
1 4
2 4
3 4
4 5
5 5
*/