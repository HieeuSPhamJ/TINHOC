#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;

ii a[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n, k;
        cin >> n >> k;
        int sum = 0;
        
        priority_queue <ii, vector <ii>, greater <ii>> heap;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i].se;
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i].fi;
            
            heap.push(a[i]);
        }

        while (k > 0 and heap.size())
        {
            sum += k;
            while(heap.size() and heap.top().se <= sum)
            {
                heap.pop();
            }
            if (heap.size() == 0){
                break;
            }
            k -= heap.top().fi;
        }
        if (heap.size() == 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}