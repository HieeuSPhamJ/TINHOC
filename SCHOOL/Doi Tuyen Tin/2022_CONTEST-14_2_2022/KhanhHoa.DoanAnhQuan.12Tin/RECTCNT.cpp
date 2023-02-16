#include<bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector <int>
#define fi first
#define se second
#define ii pair<int , int>
#define FOR(i , a , b) for(int i = a ;i <= b ; i += 1)
#define FORD(i , a , b) for(int i = a ;i >= b ; i -= 1)
#define REP(i , a) for(int i = 0 ;i < a ; i += 1)

const int oo = 1e9 + 7;
const int MOD = 1e9 + 7;

int n , q;
int a[5005][5005];
int F[5005][5005];
char c;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("RECTCNT.inp" , "r" , stdin);
    freopen("RECTCNT.out" , "w" , stdout);
    cin >> n >> q;
    int dem = 0;
    FOR(i , 1 , n){
        FOR(j , 1 , n) {
            cin >> c;
            if(c == '0') a[i][j] = 0;
            else a[i][j] = 1;
            F[i][j] = F[i - 1][j] + F[i][j - 1] - F[i - 1][j - 1] + a[i][j];
        }
    }

    FOR(i , 1 , n){
        FOR(j , 1 , n){
            FORD(x , i , 1){
                if(a[x][j] == 1) break;
                FORD(y , j , 1){
                    if(a[i][y] == 1) break;
                    if(F[i][j] - F[x - 1][j] - F[i][y - 1] + F[x - 1][y - 1] == 0) dem += 1;
                    else break;
                }
            }
        }
    }
    cout << dem << endl;
    int u ,v;
    while(q --){
        dem = 0;
        cin >> u >> v;
        if(a[u][v] == 0) a[u][v] = 1;
        else a[u][v] = 0;
        FOR(i , u , n){
            FOR(j , v , n) {
                F[i][j] = F[i - 1][j] + F[i][j - 1] - F[i - 1][j - 1] + a[i][j];
            }
        }
        FOR(i , 1 , n){
            FOR(j , 1 , n){
                FORD(x , i , 1){
                    if(a[x][j] == 1) break;
                    FORD(y , j , 1){
                        if(a[i][y] == 1) break;
                        if(F[i][j] - F[x - 1][j] - F[i][y - 1] + F[x - 1][y - 1] == 0) dem += 1;
                        else break;
                    }
                }
            }
        }
        cout << dem << endl;
    }
    return 0;
}
