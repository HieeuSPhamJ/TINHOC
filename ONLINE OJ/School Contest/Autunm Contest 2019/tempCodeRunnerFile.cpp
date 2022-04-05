for (int i = 1; i <= d; i++){
            for (int j = 1; j <= d; j += 3){
                maze[i][j] = 'A';
            }
        }
        for (int i = 3; i <= d; i++){
            for (int j = 3; j <= d; j += 3){
                maze[i][j] = 'C';
            }
        }
        for (int i = 2; i <= d; i++){
            for (int j = 2; j <= d; j += 3){
                if (n >= 2){
                    maze[i][j] = 'B';
                    n -= 3;
                }
            }
        }
        for (int i = 2; i <= d; i += 3){
            if (n > 0){
                maze[1][i] = 'B';
                n--;
            }
            if (n > 0){
                maze[d][i] = 'B';
                n--;
            }
        }