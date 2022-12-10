#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;

int a[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n, k, b, s;
        cin >> n >> k >> b >> s;

        int check = 1;
        int sum = 0;

        for (int i = 1, each = b / n; i <= n; i++){
            a[i] = each * k;
            sum += a[i];
        }

        if (sum > s){
            check = 0;
        }

        for (int i = 1; i <= b - (b / n * n); i++){
            a[i] += k;
            sum += k;
        }

        if (sum > s){
            check = 0;
        }
        
        int index = 1;
        int need = s - sum;
        // cout << "Need: " << need << endl;
        while(need and index <= n){
            if (need < k){
                a[index] += need;
                need = 0;
                break;
            }
            else{
                a[index] += (k - 1);
                need -= (k - 1);
                index++;
            }
        }   

        if (need){
            check = 0;
        }

        if (check){
            for (int i = 1; i <= n; i++){
                cout << a[i] << ' ';
            }
            cout << endl;
        }
        else{
            cout << -1 << endl;
        }
    }
    return 0;
}