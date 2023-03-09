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
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        int cap = 0;
        int done = 0;
        int undetect = 0;
        while(n--){
            int x;
            cin >> x;
            if (x == 1){
                undetect++;
            }
            else{
                done += undetect;
                undetect = 0;
            }
            int newcap = undetect;
            newcap += (done + 2 * (done > 0)) / 2;
            cap = max(cap, newcap);
            // cout << x << ": " << done << " " << undetect << " " << newcap<< endl;
        }

        cout << cap << endl;
    }
    return 0;
}