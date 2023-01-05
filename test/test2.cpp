#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 2 * 1e5 + 10;

int n;
int a[maxN];
int check[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            check[i] = 1;
        }
        int ans = 0;
        int plus = 1;
        for (int i = 1; i <= n; i++){
            int last = i;
            if (check[i]){
                vector <int> temp;
                while(check[i]){
                    temp.push_back(i);
                    check[i] = 0;
                    i = a[i];
                }
                ans--;
                ans += temp.size();
                sort(all(temp));
                for (int j = 1; j < temp.size(); j++){
                    if (abs(temp[j - 1] - temp[j]) == 1){
                        plus = 0;
                    }
                }
            }
            i = last;
        }

        if (!plus){
            cout << ans - 1 << endl;
        }
        else{
            cout << ans + 1 << endl;
        }
    }
    return 0;
}