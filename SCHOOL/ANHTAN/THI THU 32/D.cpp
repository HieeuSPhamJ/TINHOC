#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;

int a[maxN];

bool cmp(int x, int y){
    return x > y; 
}

int calEnd(int left, int right){
    int i = right;
    for (; i >= 1; i--){
        if (a[i] != a[i + 1]){
            return i;
        }
    }
    return 0;
}

int calMid(int left, int right){
    int i = left;
    for (; i <= right; i++){
        if (a[i] != a[i + 1]){
            return i;
        }
    }
    return 0;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        for (int i = 1;  i <= n; i++){
            cin >> a[i];
        }
        sort(a + 1, a + 1 + n, cmp);

        // for (int i = 1; i <= n; i++){
        //     cout << a[i] << " ";
        // }
        // cout << endl;
        // for (int i = 1; i <= n / 2; i++){
        //     cout << a[i] << " ";
        // }
        // cout << endl;

        int End = calEnd(1, n / 2);
        int Mid = calMid(1, End / 3 - (End % 3 == 0));

        int M1 = 0;
        int count = 0;
        for (M1 = Mid; M1 <= End; M1++){
                count++;
                if (count > Mid and a[M1] != a[M1 + 1]){
                    break;
                }
        }
        int BD = (End - Mid);
        // cout << Mid << "-" << End;
        // cout << "-" << count << endl;
        if (Mid == 0 or End == 0 or BD < 2 or (Mid >= count) or Mid >= (BD - count)){
            cout << 0;
            cout << endl;
            continue;
        }
        cout << End;
        cout << endl;
    }
    return 0;
}

/*
9 / 3 =
--- --- ---

--- --- --
*/