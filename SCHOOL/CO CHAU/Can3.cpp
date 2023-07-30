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
int b[maxN];

signed main(){
    // freopen("Can3.INP", "r", stdin);
    // freopen("Can3.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int m;
    cin >> m;
    vector <int> st;
    while(m){
        st.push_back(m % 3);
        m /= 3;
    }
    int len = st.size() + 2;
    for (int i = 0; i < st.size(); i++){
        a[i] = st[i];
    }
    for (int i = 0, t = 0; i <= len; i++){
        // cout << "With:" << i << endl;
        // cout << a[i] << endl;
        if (a[i] <= 1){
            continue;
        }
        b[i] = 3 - a[i];
        a[i] = 0;
        a[i + 1]++;
        // cout << b[i] << endl;
    }

    int cnt = 0;
    for (int i = 0; i <= len; i++){
        cnt += (b[i] != 0);
    }
    cout << cnt << " ";
    for (int i = 0, t = 1; i <= len; i++){
        if (b[i]){
            cout << t << ' ';
        }
        t *= 3;
    }
    cout << endl;

    cnt = 0;
    for (int i = 0; i <= len; i++){
        cnt += (a[i] != 0);
    }
    cout << cnt << " ";
    for (int i = 0, t = 1; i <= len; i++){
        if (a[i]){
            cout << t << ' ';
        }
        t *= 3;
    }
    cout << endl;


    return 0;
}