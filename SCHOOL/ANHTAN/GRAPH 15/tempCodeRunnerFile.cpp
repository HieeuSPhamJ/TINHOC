 Start, ii End){
//     resetVi();
//     queue <ii> myQueue;

//     myQueue.push(Start);

//     while(!myQueue.empty()){
//         ii tempV = myQueue.front();
//         myQueue.pop();
//         for (int i = 0; i < 4; i++){
//             int newX = tempV.x + dirX[i];
//             int newY = tempV.y + dirY[i];

//             if (newX >= 1 and newX <= n and newY >= 1 and newY <= n and visited[newX][newY] == -1){
//                 visited[newX][newY] = visited[tempV.x][tempV.y];
//                 myQueue.push({newX, newY});
//             }
//         }
//     }
//     return visited[End.x][End.y];
// }