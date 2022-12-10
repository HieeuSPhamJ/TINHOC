#include<bits/stdc++.h>
#define ii pair <int,int>
#define x first
#define y second
#define int long long
using namespace std;

int a[110][110];
int check[110][110];

void print(ii t){
    cout << t.x << ' ' << t.y << endl;
}

int getVal(ii t1, ii t2, ii t3, ii t4){
    return (a[t1.x][t1.y] + a[t2.x][t2.y] + a[t3.x][t3.y] + a[t4.x][t4.y]);
}

void setVal(ii t1, ii t2, ii t3, ii t4){
    check[t1.x][t1.y] = check[t2.x][t2.y] = check[t3.x][t3.y] = check[t4.x][t4.y] = -1;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                char inp;
                cin >> inp;
                a[i][j] = (inp == '1');
                // cout << inp;
                check[i][j] = 0;
            }
            // cout << endl;
        }

        int count = 0;

        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                if (check[i][j] == -1){
                    continue;
                }
                ii t1 = {i, j};
                ii t2 = {n - i + 1, n - j + 1};
                ii t3 = {n - j + 1, i};
                ii t4 = {n - t3.x + 1, n - t3.y + 1};

                // cout << "---" << endl;
                // print(t1);
                // print(t2);
                // print(t3);
                // print(t4);
                

                int temp = getVal(t1,t2,t3,t4);
                // cout << a[t1.x][t1.y] << ' ' << a[t2.x][t2.y] << ' ' << a[t3.x][t3.y] << ' ' << a[t4.x][t4.y] << endl;

                // cout << temp << endl;

                if (temp == 1 or temp == 3){
                    count += 1;
                }
                else if (temp == 2){
                   count += 2;
                }
                setVal(t1,t2,t3,t4);
            }
        }
        cout << count;
        cout << endl;


    }
    return 0;
}