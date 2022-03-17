#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>
#include <utility>

using namespace std;

int a[10][10], dem = 0, x, y;
int dx[8]={-2, -2, -1, 1, 2, 2, 1, -1};
int dy[8]={-1, 1, 2, 2, 1,-1, -2, -2};
bool ok = false;
int ans = 0;

int sum(int k) {
    vector<pair<int, int>> v;

    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            if (a[i - 1][j - 1] == k) {
                v.push_back({i, j});
            }
        }
    }

    int temp = 0;
    for (int i = 0; i < (int) v.size() - 1; i++) {
        for (int j = i + 1; j < (int) v.size(); j++) {
            temp += abs(v[i].first - v[j].first) * abs(v[i].second - v[j].second);
        }
    }
    v.clear();

    return temp;
}

int cal() {
    int temp = -17000;
    for (int i = 1; i <= 9; i++) {
        temp += sum(i) * i;
    }
    return min(max(0, temp), 1062);
}

bool ktra(int d, int x, int y) {
    for (int i = 0; i < 9; i++) {
        if ( a[i][y] == d || a[x][i] == d ) {
            return false;
        }
    }
    for (int i = (x / 3) * 3; i < (x / 3 + 1) * 3; i++) {
        for (int j = (y / 3) * 3; j< (y / 3 + 1) * 3; j++) {
            if ( a[i][j] == d ) {
                return false;
            }
        }
    }
    return true;
}

void test(int d, int x, int y) {
    if (d < dem) {
        while ( a[x][y] != 0 ) {
            y--;
            if (y<0) {
                x--;
                y = 8;
            }
        }
        for (int i=9;i >= 1;i--) {
            if (ktra(i, x, y)) {
                a[x][y] = i;
                test(d + 1, x, y);
                a[x][y] = 0;
            }
        }
    }
    else {
        int temp = cal();
        if (temp > ans) {
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    //b[i][j] = a[i][j];
                    cout << a[i][j];
                }
                cout << endl;
            }
            cout << temp << endl;
            ans = temp;
        }
    } 
}

int main() {
    freopen("vmsudoku.out", "w", stdout);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            a[i][j] = 0;
            if (a[i][j] == 0) {
                x = i;
                y = j;
                dem++;
            }
        }
    }

    test(0, x, y);
}