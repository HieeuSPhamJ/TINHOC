#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 2e5 + 10;

int len[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    int no = n;
    int ko = k;
    
    for (int i = 1; i < maxN; i++){
        len[i] = 1e18;
    }

    len[1] = 1;

    for (int i = 2; i <= 60; i++){
        len[i] = len[i - 1] * 2 + log10(i) + 1;
    }
    
    if (len[n] < k){
        cout << -1 << endl;
        return 0;
    }

    while (n >= 1 and k > (int)log10(n) + 1){
        k -= ((int)log10(n) + 1);
        n--;
        if (len[n] <= k){
            k = k % len[n];
            if (k == 0){
                k = len[k];
            }
        }
    }

    cout << -1 << endl;

    return 0;

    deque <int> s;
    while(n >= 1){
        s.push_front(n % 10);
        n /= 10;
    }
    if (s[k - 1] == 0){
        cout << -1 << endl;
        return 0;
    }
    cout << s[k - 1];
    return 0;
}


/*
2: 3
3: 7
4: 15
5: 31
6: 63
7: 127
8: 255
9: 511
10: 1023
11: 2047
12: 4095
13: 8191
14: 16383
15: 32767
16: 65535

654321121132112114321121132112115432112113211211432112113211211
2 2 3
3 6 7
4 14 15

1
211
3211211

len[i] = len[i - 1] * 2 + 1

123456789012345
321121132112115
*/