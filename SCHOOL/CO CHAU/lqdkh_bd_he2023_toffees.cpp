#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e6 + 10;

int a[maxN];
char b[maxN];
int pa[maxN];
int pb[maxN];
int res[maxN];

map <char,char> cv;
map <char,char> cc;

signed main(){
    freopen("TOFFEES.INP", "r", stdin);
    freopen("TOFFEES.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cv['L'] = 'R';
    cv['R'] = 'L';
    cv['='] = '=';
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int mi = 0;
    for(int i = 1; i <= n - 1; i++) {
        char x;
        cin >> x;
        if(x == '='){
            a[i] = a[i - 1];
        }
        else if(x == 'R'){
            a[i] = a[i - 1] + 1;
        }
        else{
            a[i] = a[i - 1] - 1;
        }
        mi = min(mi, a[i]);
    }
    mi = max(0ll, 1 - mi);
    for(int i = 0; i < n; i++) {
        cout << a[i] + mi << ' ';
    }

    return 0;
}