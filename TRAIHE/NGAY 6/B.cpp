#include<bits/stdc++.h>
#define ii pair <int,int>
#define f first
#define s second
#define ll long long
using namespace std;

int dir1[] = {1, 2, 4, 5, 6, 1, 1};
int dir2[] = {2, 3, 1, 2, 2, 5, 6};
int dir3[] = {3, 4, 2, 6, 5, 3, 3};
int dir4[] = {4, 1, 3, 4, 4, 6, 5};
int dir5[] = {5, 5, 5, 3, 1, 4, 2};
int dir6[] = {6, 6, 6, 1, 3, 2, 4};

int dice[5][6];
 int check[5];
vector <vector <int>> permu;


void backTracking(int index, vector <int> lists){
    if (index >= 4){


        return;
    }
    for (int i = 0; i < 7; i++){
    for (int i = 0; i < 7; i++){
    for (int i = 0; i < 7; i++){
    for (int i = 0; i < 7; i++){
        int backup[8];

        int temp[] = {
        dice[index][dir1[i]],
        dice[index][dir2[i]],
        dice[index][dir3[i]],
        dice[index][dir4[i]],
        dice[index][dir5[i]],
        dice[index][dir6[i]]
        };
        for (int j = 0; j < 6; j++){
            backup[j] = dice[index][j];
        }
        for (int j = 0; j < 6; j++){
            dice[index][j] = temp[j];
        }
    
        backTracking(i + 1, lists);
        for (int j = 0; j < 6; j++){
            dice[index][j] = backup[j];
        }
    }
    }
    }
    }

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (int i = 1; i <= 4; i++){
        cin >> dice[i][1] >> dice[i][3];
        cin >> dice[i][5] >> dice[i][6];
        cin >> dice[i][2] >> dice[i][4];
    }

    for (int i = 1; i <= 4; i++){
        check[i] = 1;
        for (int j = 1; j <= 4; j++){
            check[j] = 1;
            for (int k = 1; k <= 4; k++){
                check[k] = 1;
                for (int a = 1; a <= 4; a++){
                    check[a] = 1;
                    if (check[i] == 1 and check[j] == 1 and check[k] == 1 and check[a] == 1){
                        vector <int> temp = {i, j, k, a};
                        permu.push_back(temp);
                    }
                    check[a] = 0;
                }
                check[k] = 0;
            }
            check[j] = 0;
        }
        check[i] = 0;
    }

    for (auto i :permu){
        backTracking(0, i);
    }
    return 0;
}