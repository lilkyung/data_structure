/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void dfs(int**, int, int, int*, int, int, int, int **);

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    *returnSize = matrixSize * matrixColSize[0];
    int *result = malloc(sizeof(int) * (*returnSize));
    int residx = 0;
    int **visited= malloc(sizeof(int *) * matrixSize);
    for(int i=0; i<matrixSize; i++){
        visited[i] = malloc(sizeof(int) * matrixColSize[i]);
        for(int j=0; j<matrixColSize[i];j++) visited[i][j] = 0;
    }
    dfs(matrix, 0, 0, result, residx, matrixSize, matrixColSize[0], visited);
    for(int i=0; i<matrixSize; i++) free(visited[i]);
    free(visited);
    return result;
}

void dfs(int **matrix, int rowidx, int colidx, int* result, int residx, int rowsize, int colsize, int **visited){
    if(visited[rowidx][colidx]) return;
    result[residx++] = matrix[rowidx][colidx];
    visited[rowidx][colidx] = 1;
    int dr[4] = {0, 1, 0, -1};
    int dc[4] = {1, 0, -1, 0};
    for(int i=0; i<4; i++){
        int row = rowidx + dr[i];
        int col = colidx + dc[i];
        if(row && i==0 && !visited[rowidx - 1][colidx]) continue; //오른쪽 이동을 할 수  없는 조건 추가
        if(row >= rowsize || row < 0 || col >= colsize || col < 0) continue;
        dfs(matrix, row, col, result, residx, rowsize, colsize, visited);
    }
    return;
}
/*dfs로 구현
1. dfs들어오면 dfs실행 가능한지 확인
2. result[residx++] = matrix[rowidx][colidx]] 
3. matrix[rowidx][colidx]] = 0
4. 오른쪽 갈 수 있는지 확인
5. 아래 갈 수 있는 지 확인
6. 왼쪽 갈 수 있는 지 확인
7. 위 갈 수 있는 지 확인

dfs할 때 필요한 것: **matrix, rowidx, colidx, rowsize, colsize, *result, residx, **visited 

dfs 순서를 오, 아, 왼, 위 로 실행하면 오, 아, 왼은 문제가 없지만 위로 가는 차례일 때는 오른쪽으로 빠지는 경우가 있음 
이를 막기 위해 오른쪽을 갈 때는 자기 위에 위치한 수를 이전에 방문 했어야지만 갈 수 있다는 조건을 추가
조건: row != 0 and i==0 and visited[row - 1][colidx] == 0
*/
