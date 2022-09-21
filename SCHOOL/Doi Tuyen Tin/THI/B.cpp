#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 1010;

int n;
string s;
int a[maxN];
int org[maxN];
int Count = 0;
int b[maxN * 3][maxN];

bool check(int d){
    for (int i = 1; i <= n; i++){
        if (b[d][i] != org[i]){
            return 0;
        }
    }
    return 1;
}

void init(){
    for (int i = 1; i <= n; i++){
        org[i] = a[i];
        b[0][i] = a[i];
    }
    while(!check(Count) or Count == 0){
        for (int i = 1; i <= n; i++){
            if (i % 2){
                b[Count + 1][i] = b[Count][i / 2 + 1];
            }
            else{
                b[Count + 1][i] = b[Count][n - i / 2 + 1];
            }
        }
        Count++;
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int x;
    cin >> x;
    cin >> s;
    n = s.length();
    for (int i = 1; i <= n; i++){
        a[i] = s[i - 1] - 'a';
        // cout << a[i];
    }

    init();

    // for (int d = 0; d <= Count; d++){
    //     cout << d << ": ";
    //     for (int i = 1; i <= n; i++){
    //         cout << char(b[d][i] + 'a');
    //     }
    //     cout << endl;
    // }

    for (int i = 1; i <= n; i++){
        cout << char(b[Count - x % Count][i] + 'a');
    }


    return 0;
}