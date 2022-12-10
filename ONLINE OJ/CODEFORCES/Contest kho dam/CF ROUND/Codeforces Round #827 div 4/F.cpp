#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
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
        map <int,int> A[2], hashA[2];
        A[0]['a'] = 1;
        A[1]['a'] = 1;
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++){
            int d , k;
            string s;
            cin >> d >> k >> s;
            for (int i = 0; i < s.size(); i++){
                A[d - 1][s[i]] += k;
            }
            for (int i = 'a'; i <= 'z'; i++){
                hashA[0][i] = A[0][i];
                hashA[1][i] = A[1][i];
            }
            int left = 'a';
            int right = 'z';
            
            int dmcodeforces = 0;

            while(1){
                while(A[1][right] == 0 and right >= 'a'){
                    right--;
                }
                while(A[0][left] == 0 and left <= 'z'){
                    left++;
                }
                if(left > 'z'){
                    if(right >= 'a'){
                        cout << "YES" << endl;
                        dmcodeforces = 1;
                        if (dmcodeforces){
                            break;
                        }
                    }
                    break;
                }
                if(dmcodeforces or right < 'a'){
                    break;
                }
                if(left < right){
                    cout << "YES" << endl;
                    dmcodeforces = 1;
                    if (dmcodeforces){
                        break;
                    }
                }
                if(dmcodeforces or right < left){
                    break;
                }
                int x = min(A[0][left] , A[1][right]);
                A[1][right] -= x;
                A[0][left] -= x;
            }
            if (!dmcodeforces){
                cout << "NO" << endl;
            }
            
            for (int i = 'a'; i <= 'z'; i++){
                A[0][i] = hashA[0][i];
                A[1][i] = hashA[1][i];
            }
        }
        
    }
    return 0;
}