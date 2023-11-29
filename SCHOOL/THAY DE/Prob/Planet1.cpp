#include<bits/stdc++.h>
#define ii pair <int,int>
#define x first
#define y second
#define ll long long
using namespace std;

const int maxN = 1e3;
int demi[6][maxN][maxN];


ii dir[] = {
    {-1, 0},
    {0, -1},
    {1, 0},
    {0, 1}
};

int a[maxN][maxN];

int checkIm = 0;

 
bool check(int x, int y, int dem){
    if (demi[dem][x][y] == 1){
        checkIm = 1;
        return 0;
    }
    if (a[x][y] == -1){
        return 0;
    }
    demi[dem][x][y] = 1;
    return 1;

}

signed main(){
    freopen("planet1.INP", "r", stdin);
    freopen("planet1.OUT", "w", stdout);
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int count = 0;
    int n, m;
    cin >> n >> m;

    for (int i = 0; i <= n + 1; i++){
        for (int j = 0; j <= m + 1; j++){
            a[i][j] = -1;
            // cout << a[i][j];
        }
        // cout << endl;
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            char inp;
            cin >> inp;
            if (inp == '.'){
                a[i][j] = 0;
            }
            else if (inp == 'C'){
                a[i][j] = -1;
            }
            else if (inp == '/'){
                a[i][j] = 1;
            }
            else {
                a[i][j] = 2;
            }
            // cout << a[i][j];
        }
        // cout << endl;
    }
    int x, y;
    cin >> x >> y;

    for (int d = 0; d < 3; d++){
        int i = x;
        int j = y;
        int dem = d;
        int tempCount = 0;
        // cout << "#" << dem << endl;
        while(check(i, j, dem)){
            // cout << dem << ' ' << i << ' ' << j << endl;
            // cout << a[i][j] << endl; 
            if (a[i][j] == 1){
                if (dem == 0){
                    // cout << "^ - >" << endl;
                    dem = 3;
                }
                else if (dem == 3){
                    dem = 0;
                    // cout << "> - ^" << endl;
                }
                else if (dem == 1){
                    dem = 2;
                    // cout << "< - D" << endl;
                }
                else if (dem == 2){
                    dem = 1;
                    // cout << "D - <" << endl;
                }
            }
            else if (a[i][j] == 2){
                if (dem == 0){
                    dem = 1;
                }
                else if (dem == 1){
                    dem = 0;
                }
                else if (dem == 3){
                    dem = 2;
                }
                else if (dem == 2){
                    dem = 3;
                }
            }
            i += dir[dem].x;
            j += dir[dem].y;
            tempCount++;
            // cout << dem << ' ' << i << ' ' << j << endl;
        }
        count = max(count, tempCount);
    }

    // cout << checkIm;

    if (checkIm){
        cout << "Voyager";
    }
    else{
        cout << count;
    }



    return 0;
}