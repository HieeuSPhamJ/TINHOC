#include<bits/stdc++.h>

using namespace std;


int RecursionFibonacci(int n){
  if (n==1 or n==2)
    return 1;
  return RecursionFibonacci(n-1)+RecursionFibonacci(n-2);
}



int main(){
  int n=6;
  //cin>>n;
  cout<<RecursionFibonacci(n);
return 0;
}