#include <bits/stdc++.h>
#define int long long
#define ii pair <int,int>
#define iii pair <int,ii>
#define endl '\n'
#define fi first
#define se second
#define all(x) x.begin(),x.end()
using namespace std;

const int maxN = 1010;


int n, test;
int a[maxN][maxN];
int prefix[maxN][maxN];
int temp[maxN];

int cal(int i, int j){
    return prefix[i][j - 1] + prefix[i - 1][j] - prefix[i - 1][j - 1] + a[i][j];
}

int get(int x1,int y1, int x2, int y2){
    return prefix[x1][y1] - prefix[x1][y2 - 1] - prefix[x2 - 1][y1] + prefix[x2 - 1][y2 - 1];
}

void solve(int x, int y){
    a[x][y] = !a[x][y];
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            prefix[i][j] = cal(i,j);
        }
    }
    int ans = 0;
    for (int x1 = 1; x1 <= n; x1++){
        for (int y1 = 1; y1 <= n; y1++){
            for (int x2 = x1; x2 >= 1; x2--){
                for (int y2 = y1; y2 >= 1; y2--){
                    int s = get(x1,y1,x2,y2);
                    ans += (s == 0);
                }

            }
        }
    }
    cout << ans << endl;
}

void solvenao(int x, int y){
    a[x][y] = !a[x][y];
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            prefix[i][j] = cal(i,j);
        }
    }

    int ans = 0;

    for (int up = 1; up <= n; up++){
        for (int down = up; down <= n; down++){
//            cout << up << " " << down << endl;
            for (int i = 1; i <= n; i++){
                temp[i] = temp[i - 1] + get(down,i,up,i);
//                cout << temp[i] << " ";
            }
//            cout << endl;
            for (int right = 1, left = 1; right <= n; right++){
                while(left < right){
                    int now = temp[right] - temp[left - 1];
                    if (now != 0){
                        left++;
                        continue;
                    }
                    else{
                        break;
                    }
                }
                if (temp[right] - temp[left - 1] == 0){
                    ans += right - left + 1;
                }
            }
        }
    }

    cout << ans << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("RECTCNT.INP","r", stdin);
    freopen("RECTCNT.OUT","w", stdout);
    cin >> n >> test;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            char x;
            cin >> x;
            a[i][j] = x - '0';
        }
    }
    if (n < 30){
        solve(0,0);
        while(test--){
            int x, y;
            cin >> x >> y;
    //        cout << x << " " << y << endl;
            solve(x,y);
        }
        return 0;
    }

    solvenao(0,0);
    while(test--){
        int x, y;
        cin >> x >> y;
//        cout << x << " " << y << endl;
        solvenao(x,y);
    }

    return 0;
}


