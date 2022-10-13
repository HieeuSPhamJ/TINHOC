le(m--){
        int num;
        cin >> num;
        node *p = root;
        int ans = 0;
        for (int i = 1; i <= num; i++){
            int dig;
            cin >> dig;
            if (p->child[dig] == NULL){
                break;
            }   
            p = p->child[dig];
            ans += p->dp;
        }
        cout << ans << endl;
    }