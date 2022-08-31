#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 5 * 1e5 + 10;

int n, test;
int ans = 0;
int a[maxN];
int ta[maxN];

void init(){
    a[0] = a[n + 1] = 0;
    for (int i = 1; i <= n; i++){
        if (a[i - 1] < a[i] and a[i] > a[i + 1]){
            ans += a[i];
        }        
        if (a[i - 1] > a[i] and a[i] < a[i + 1]){
            ans -= a[i];
        }           
    }
}

void remove(int i){
    if (a[i - 1] < a[i] and a[i] > a[i + 1]){
        ans -= a[i];
        // cout << "Minus:" << i << endl;
    }   
    if (a[i - 1] > a[i] and a[i] < a[i + 1]){
        ans += a[i];
        // cout << "Plus:" << i << endl;
    }   
    
}

void update(int i){
    if (a[i - 1] < a[i] and a[i] > a[i + 1]){
        ans += a[i];
        // cout << "UPPlus:" << i << endl;
    }        
    if (a[i - 1] > a[i] and a[i] < a[i + 1]){
        ans -= a[i];
        // cout << "UPMinus:" << i << endl;
    } 
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int q;
    cin >> q;
    while(q--){
        ans = 0;
        cin >> n >> test;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            ta[i] = a[i];
        }

        init();
        cout << ans << endl;

        while(test--){
            // cout << "#" << test << endl;
            int left, right;
            cin >> left >> right;
            ta[left] = a[right];
            ta[right] = a[left];
            
            // cout << "ANS: " << ans << endl;

            set <int> listIndex = {left - 1, left, left + 1, right - 1, right, right + 1};

            // for (auto i: listIndex){
            //     if (i != 0 and i != n + 1){
            //         cout << i << " ";
            //         // remove(i);
            //     }
            // }
            // cout << endl;

            for (auto i: listIndex){
                if (i != 0 and i != n + 1){
                    remove(i);
                }
            }

            for (auto i: listIndex){
                if (i != 0 and i != n + 1){
                    a[i] = ta[i];
                }
            }

            // for (int i = 1; i <= n; i++){
            //     cout << a[i] << " ";
            // }
            // cout << endl;

            for (auto i: listIndex){
                if (i != 0 and i != n + 1){
                    update(i);
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}