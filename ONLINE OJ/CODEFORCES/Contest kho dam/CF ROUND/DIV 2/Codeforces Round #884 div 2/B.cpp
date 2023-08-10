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
        if (n == 1){
            cout << 1 << endl;
            continue;
        }
        if (n == 2){
            cout << "1 2" << endl;
            continue;
        }
        deque <int> q;
        q.push_back(1);
        for (int i = 4; i <= n; i++){
            if (i % 2){
                q.push_back(i);
            }
            else{
                q.push_front(i);
            }
        }
        q.push_back(2);
        q.push_front(3);
        for (auto i: q){
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}

/*

*/