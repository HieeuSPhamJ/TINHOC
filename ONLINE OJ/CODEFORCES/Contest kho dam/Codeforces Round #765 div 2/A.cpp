#include<bits/stdc++.h>
using namespace std;

int l;
int check[1000];
queue <int> myQueue;


void Conv(int n){
    if (n>0){
        Conv(n/2);
        myQueue.push(n%2);
    }
}



int main(){
    int test;
    cin >> test;
    while (test--){
        int n;
        cin >> n >> l;
        memset(check, 0, sizeof(check));
        while (n--){
            while (!myQueue.empty()){
                myQueue.pop();
            }
            int x;
            cin >> x;
            Conv(x);
            int len = l;
            int i = 1;
            while ((int)myQueue.size() < len){
                len--;
                check[i] = 0;
                i++;
            }
            while(!myQueue.empty()){
                if (check[i])
                check[i] = myQueue.front();
                myQueue.pop();
            }

        }
    }
}