#include<bits/stdc++.h>
#define ii pair <int,int>
#define f first
#define s second
using namespace std;

int n;
vector <int> mainVec;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        int inp;
        cin >> inp;
        mainVec.push_back(inp);
    }

    int price = 0;

    while(mainVec.size() > 1){
        int index = 0;
        int val = 1e9;
        for (int i = 1; i < mainVec.size(); i++){
            if (mainVec[i] + mainVec[i - 1] < val){
                val = mainVec[i] + mainVec[i - 1];
                index = i;
            }
        }

        vector <int> tempVec;
        
        for (int i = 0; i < mainVec.size(); i++){
            if (i != (index - 1) and i != index){
                tempVec.push_back(mainVec[i]);
                // cout << mainVec[i] << ' ';
            }
            if (i == index){
                tempVec.push_back(val);
            }
        }
        // cout << endl;

        // tempVec.push_back(val);
        price += val;
        // mainVec.clear();
        mainVec = tempVec;
        // cout << mainVec.size() << endl;

    }

    cout << price;

    return 0;
}