#include<bits/stdc++.h>
using namespace std;

int a[10003];


int main(){
    int n;
    cin >> n;
    while (n != 0){
        int streak = 0;
        int tempStreak = 0;
        for (int i = 1; i <= n; i++){
            int inp;
            cin >> inp;
            tempStreak += inp;
            streak = max(tempStreak, streak);
            if (tempStreak < 0){
                tempStreak = 0;
            }
        }
        if (streak > 0)
			cout << "The maximum winning streak is " << streak << ".";
		else
			cout <<"Losing streak.";

        cout << endl;

        cin >> n;
    }

    return 0;
}