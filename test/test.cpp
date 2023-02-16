#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

int a[403][403][5];

signed main(){
    freopen("nhap.txt", "r", stdin);
    freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        memset(a,0,sizeof(a));
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++){
            int x, y, t;
            cin >> x >> y >> t;
            a[x + 200][y + 200][t]++;
        }
        int ans = 0;
        for (int c1 = 1; c1 <= 4; c1++){
            for (int c2 = c1 + 1;  c2 <= 4; c2++){
                set <int> s = {1,2,3,4};
                s.erase(c1);
                s.erase(c2);
                int c3 = *s.begin();
                s.erase(c3);
                int c4 = *s.begin();
                for (int i = 0; i <= 400; i++){
                    for (int j = i + 1; j <= 400; j++){
                        int t1 = 0;
                        int t2 = 0;
                        int trash = 0;
                        for (int line = 0; line <= 400; line++){
                            int x1 = (a[line][i][c1] * a[line][j][c2] + a[line][i][c2] * a[line][j][c1]);
                            int x2 = (a[line][i][c3] * a[line][j][c4] + a[line][i][c4] * a[line][j][c3]);
                            trash += x1 * x2;
                            t1 += x1;
                            t2 += x2;
                        }
                        ans += t1 * t2 - trash;
                    }
                }
            }
        }
        cout << ans / 2 << endl;
    
    }
    return 0;
}