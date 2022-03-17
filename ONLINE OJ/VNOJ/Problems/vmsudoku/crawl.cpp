   #include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int a[10][10], dem = 0, x, y;
int dx[8]={-2, -2, -1, 1, 2, 2, 1, -1};
int dy[8]={-1, 1, 2, 2, 1,-1, -2, -2};
bool ok = false;


bool ktra( int d, int x, int y )
{
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

void test(int d,int x,int y)
{
    if (ok) {
        return;
    }
    
    if (d < dem) {
        while ( a[x][y] != 0 ) {
            y--;
            if (y<0) {
                x--;
                y = 8;
            }
        }
        for (int i=1;i<=9;i++) {
            if ( ktra( i, x, y ) ) {
                a[x][y] = i;
                test( d+1, x, y );
                a[x][y] = 0;
            }
        }
    }
    else {
        ok = true;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    } 
}

int main()
{
    freopen("vmsudoku.out", "w", stdout);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
                a[i][j] = 0;
                if (a[i][j] == 0 ) {
                    x = i;
                    y = j;
                    dem++;
                }
            }
    }
    test(0, x, y);
}