typedef struct position{ //위치 정보를 담아낼 구조체
	int p_row;
	int p_col;
}pos;

static int **visited;
static pos queue[10000];
static int n; //row, col length
static int front;
static int rear;

void enqueue(int **, int, int);
void free_visited(int **);

int shortestPathBinaryMatrix(int** grid, int gridSize, int* gridColSize) {
    n = gridSize;
    front = 0;
    rear =0;

    if(grid[0][0] || grid[n-1][n-1]) return -1; //[0,0]과 [n-1,n-1]이 1이면 종료
    if(gridSize == 1) return 1; // n == 1일 때 탐색 할 필요 없이 종료

	visited = malloc(sizeof(int *) *gridSize);
	for(int i=0; i<gridSize; i++){
		visited[i] = malloc(sizeof(int) * (*gridColSize));
		for(int j=0; j<*gridColSize; j++) visited[i][j] = 0; //visited 초기화
	}
	queue[rear++] = (pos){0,0}; //시작점 큐에 넣기
	visited[0][0] = 1;

	int path_length = 1; //통로 길이
	int row, col;

	while(front != rear){
        int size = rear - front;
		for(int i=0; i<size; i++){
			row = queue[front].p_row;
			col = queue[front++].p_col; //dequeue
			if(row == n-1 && col == n-1) {
                free_visited(visited);
                return path_length;
            }
			enqueue(grid, row, col);
		}
		path_length++;
	}
    free_visited(visited);
	return -1;
}


void enqueue(int** grid, int row, int col){
	if(col != 0){ //왼쪽 3개(대각 2개 + 옆 1개)
		if(grid[row][col - 1] == visited[row][col - 1]){ //왼쪽
			visited[row][col - 1] = 1;
			queue[rear++] = (pos){row, col - 1};
		}
		if(row != 0 && grid[row - 1][col - 1] == visited[row - 1][col - 1]){ //왼쪽 상단
			visited[row - 1][col - 1] = 1;
			queue[rear++] = (pos){row - 1, col - 1};
		}
		if(row + 1 != n && grid[row + 1][col - 1] == visited[row + 1][col - 1]){//왼쪽 하단
			visited[row + 1][col - 1] = 1;
			queue[rear++] = (pos){row + 1, col - 1};
		}
	}
	if(col + 1 != n){ //오른쪽 3개
		if(grid[row][col + 1] == visited[row][col + 1]){ //오른쪽
			visited[row][col + 1] = 1;
			queue[rear++] = (pos){row, col + 1};
		}
		if(row != 0 && grid[row - 1][col + 1] == visited[row - 1][col + 1]){ //오른쪽 상단
			visited[row - 1][col + 1] = 1;
			queue[rear++] = (pos){row - 1, col + 1};
		}
		if(row + 1 != n && grid[row + 1][col + 1] == visited[row + 1][col + 1]){//오른쪽 하단
			visited[row + 1][col + 1] = 1;
			queue[rear++] = (pos){row + 1, col + 1};
		}
	}
	if(row != 0 && grid[row - 1][col] == visited[row - 1][col]){ //위
			visited[row - 1][col] = 1;
			queue[rear++] = (pos){row - 1, col};
	}
	if(row + 1 != n && grid[row + 1][col] == visited[row + 1][col]){ //아래
			visited[row + 1][col] = 1;
			queue[rear++] = (pos){row + 1, col};
	}
	return;
}

void free_visited(int **arr){
    for(int i=0; i<n; i++) free(arr[i]);
    free(arr);
}
