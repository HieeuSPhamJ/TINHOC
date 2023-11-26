int n, test;
    cin >> n >> test;
    while(test--){
        int t;
        cin >> t;
        if (t == 1){
            int l, r, v;
            cin >> l >> r >> v;
            for (int i = l; i <= r; i++){
                a[i] = v;
            }
        }
        else{
            int l, r;
            cin >> l >> r;
            int res = 0;
            for (int i = l; i <= r; i++){
                res += i * a[i];
            }
            cout << res << endl;
        }
    }