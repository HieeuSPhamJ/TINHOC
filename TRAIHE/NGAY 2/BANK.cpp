#include<bits/stdc++.h>
#define ii pair <int,int>
#define f first
#define s second
using namespace std;

struct dataType{
    int cash;
    int time;
    dataType(int a, int b){
        cash = a;
        time = b;
    }
};

vector <dataType> lists;
int timeLine[50];

bool cmp(dataType a, dataType b){
    return a.cash > b.cash;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, t;
    cin >> n >> t;
    for (int i = 1; i <= n; i++){
        int cash, time;
        cin >> cash >> time;
        dataType temp(cash, time);
        lists.push_back(temp);
    }

    sort(lists.begin(), lists.end(), cmp);

    int ans = 0;

    for (auto i: lists){
        int time = i.time;
        if (time >= t){
            continue;
        }
        while(timeLine[time] == 1){
            time--;
            if (time < 0){
                break;
            }
        }
        if (time == -1){
            continue;
        }
        timeLine[time] = 1;
        ans += i.cash;
    }

    cout << ans;

    return 0;
}