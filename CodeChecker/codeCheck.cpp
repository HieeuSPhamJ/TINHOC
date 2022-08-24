#include <bits/stdc++.h>
#define int long long
using namespace std;


int random(int left = 0, int right = 1e8){
    if (left == right){
        return left;
    }
    return (rand() % (right - left + 1)) + left;
}

void gen_random_graph(int n, int m, std::ostream& inp)
{        
    int src[n]; // source array.
    int dst[n]; //destination array.
    int arr[n][n]; //adjacency matrix.
    for(int i=0;i<n;i++)
    {
        dst[i]=i;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            arr[i][j]=0;
        }
    }
    int top=0;
    src[0]=dst[0];
    top++;
    int i=0;
    while(top!=(n)) 
    {  
       int temp = rand()%(i+1); // random integer generator between 0 and i.
       arr[src[temp]][dst[top]]=1;
       arr[dst[top]][src[temp]]=1;
       src[i+1]=dst[top];
       top++;
       i++;
    }

    for(int i=0;i<n;i++)
    {   
        // inp << "\n";
        for(int j=0;j < i;j++)
        {
            
            // inp << arr[i][j] << " ";
            // if (arr[i][j] == 0 and m >= 0){
            //     m--;
            //     arr[i][j] = (rand()%5 == 1);
            //     // inp << '*';
            // }
            if (arr[i][j] == 1){
                inp << i + 1 << " " << j + 1 << endl;
            }
            
        }
    }

}


void genTest(){
    // Dùng inp thay cho cout và hàng random() để random 1 số
    ofstream inp(("input.inp"));

    int n = 100;
    int t = random(0, n / 3);
    int m = (n - 1);
    int k = 4;
    inp << n << " " << m + k << " " << 5 << " " << 10 << endl;
    gen_random_graph(n, 0, inp);
    for (int i = 1; i <= k; i++){
        inp << random (1,n) << " " << random(1,n) << endl;
    }
    inp.close();
}

signed main(){
    srand(time(0));
    int maxTest = 1000;
    for (int test = 1; test <= maxTest; test++){
        genTest();        
        system(("A.exe"));
        system(("B.exe"));
        if (system(("fc A.out B.out")) != 0){
            cout << "Test " << test << ": WRONG!\n";
            return 0;
        }
        cout << "Test " << test << ": CORRECT!\n";
    }

    return 0;
}