#include <iostream>
#include <cstring>
using namespace std;

int A[10005];
int sum,N;

void write(int M){
    for(int j=1; j <= M; j++){
        cout<< A[j];
    }
    cout << endl;
}

void CH(int K){
	write(K);
    for (int i = A[K]+1; i <= N; i++){
        A[K+1] = i;
        CH( K + 1 );
    }
}

int main(){
    memset( A, 0, sizeof(A) );
    cin >> N;
    cout << endl;
    CH(0);
    return 0;
}