#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;


int main(int argc, char** argv) {

    registerGen(argc, argv, 1);
    int n = atoi(argv[1]);
    int m = atoi(argv[2]);
    int v_max = atoi(argv[3]);
    int gap = atoi(argv[4]);
    
    int h = rnd.next(-gap, 0);
    int a = rnd.next(1, gap - 1);
    int b = rnd.next(1 + 1, gap);
    int v = rnd.next(1,v_max);
    cout << h << " " << a << " " << b << " " << v << endl;
    

    
    return 0;
}