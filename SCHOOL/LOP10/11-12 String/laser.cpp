#include<bits/stdc++.h>
using namespace std;

struct matrix{
    long long x;
    long long y;
};


struct square{
    matrix lt;
    matrix rd;
    long long s;
};



long long n, m;
matrix laser1, laser2;

int main(){
    // freopen("laser.inp", "r", stdin);
    // freopen("laser.out", "w", stdout);
    int test;
    cin >> test;
    while (test--){
        cin >> n >> m;
        cin >> laser1.x >> laser1.y;
        cin >> laser2.x >> laser2.y;

        matrix stepLeft, stepRight;
        stepLeft.x = min({abs(1 - laser1.x), abs(1 - laser2.x)});
        stepRight.x = min({abs(n - laser1.x), abs(n - laser2.x)});
        stepLeft.y = min({abs(1 - laser1.y), abs(1 - laser2.y)});
        stepRight.y = min({abs(m - laser1.y), abs(m - laser2.y)});
        // cout << stepLeft.x << ' ' << stepLeft.y << ' ';
        // cout << stepRight.x << ' ' << stepRight.y << endl;
        
        square s1, s2, sm;
        s1.lt.x = laser1.x - stepLeft.x;
        s1.lt.y = laser1.y - stepLeft.y;
        s1.rd.x = laser1.x + stepRight.x;
        s1.rd.y = laser1.y + stepRight.y;

        s2.lt.x = laser2.x - stepLeft.x;
        s2.lt.y = laser2.y - stepLeft.y;
        s2.rd.x = laser2.x + stepRight.x;
        s2.rd.y = laser2.y + stepRight.y;

        // cout << s1.lt.x << ' ' << s1.lt.y << ' ';
        // cout << s1.rd.x << ' ' << s1.rd.y << endl;
        // cout << s2.lt.x << ' ' << s2.lt.y << ' ';
        // cout << s2.rd.x << ' ' << s2.rd.y << endl;
        // cout << "-------------------" << endl;

        s1.s = (s1.rd.x - s1.lt.x + 1) * (s1.rd.y - s1.lt.y + 1);
        s2.s = (s2.rd.x - s2.lt.x + 1) * (s2.rd.y - s2.lt.y + 1);
        // cout << s1.s << " " << s2.s << endl;

        matrix connectedSquare;
        
        if (s1.lt.x < s2.lt.x){
            connectedSquare.x = s1.rd.x - s2.lt.x + 1;
            if (connectedSquare.x < 0){
                connectedSquare.x = 0;
            }

            // cout << connectedSquare.x;
        }
        else{
            connectedSquare.x = s2.rd.x - s1.lt.x + 1;
            if (connectedSquare.x < 0){
                connectedSquare.x = 0;
            }

            // cout << connectedSquare.x;
        }
        
        // cout << ' ';

        if (s1.lt.y < s2.lt.y){
            connectedSquare.y = s1.rd.y - s2.lt.y + 1;
            if (connectedSquare.y < 0){
                connectedSquare.y = 0;
            }

            // cout << connectedSquare.y;
        }
        else{
            connectedSquare.y = s2.rd.y - s1.lt.y + 1;
            if (connectedSquare.y < 0){
                connectedSquare.y = 0;
            }

            // cout << connectedSquare.y;
        }

        // cout << endl;

        cout << n*m - (s1.s + s2.s - connectedSquare.x * connectedSquare.y);
        cout << endl;
        // cout << endl;
    }


    return 0;
}
/*
1 1 3 3
2 2 4 4
*/


