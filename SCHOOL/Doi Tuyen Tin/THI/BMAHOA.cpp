#include<bits/stdc++.h>

#define int long long
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'

using namespace std;

const int maxN = 1010;

int a[maxN];
int b[maxN][10 * maxN];
int org[maxN];
int n, m;
string s;
int Count = 0;

bool check(int d){
//    cout << "CHECK " << d << endl;
    for (int i = 1; i <= n; i++){
//        cout << b[d][i];
        if (org[i] != b[d][i]){
            return 0;
        }
    }
//    cout << endl;
    return 1;
}

void init(){
    for (int i = 1; i <= n; i++){
        org[i] = a[i];
        b[0][i] = a[i];
    }
    int d = 0;
    while(!check(d) or d == 0){
        for (int i = 1; i <= n; i++){
            a[i] = b[d][i];
        }
        for (int i = 1; i <= n; i++){
            if (i % 2){
                b[d + 1][i] = a[i / 2 + 1];
            }
            else{
                b[d + 1][i] = a[n - i / 2 + 1];
            }
        }
        d++;
    }
    Count = d;
}


signed main(){
    freopen("BMAHOA.INP", "r", stdin);
    freopen("BMAHOA.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> m;
    cin >> s;
    n = s.length();
    for (int i = 1; i <= n; i++){
        a[i] = (s[i - 1] - 'a');
    }

//    for (int i = 1; i <= n; i++){
//        cout << char(a[i] + 'a') << " ";
//    }
//    cout << endl;

    init();

//    cout << n << " " << Count << endl;
//    for (int d = 0; d <= Count; d++){
//        cout << d << ": ";
//        int x = d;
//        for (int i = 1; i <= n; i++){
//            cout << char(b[x][i] + 'a');
//
//        }
//        cout << endl;
//    }
//    cout << m % Count << endl;
//    cout << endl;

    for (int i = 1; i <= n; i++){
        cout << char(b[Count - m % Count][i] + 'a');
    }


    return 0;
}


