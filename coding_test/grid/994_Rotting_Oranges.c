typedef struct position{
	int p_row;
	int p_col;
}pos;

int orangesRotting(int** grid, int gridSize, int* gridColSize) { 
	pos queue[100];
	int front = 0;
	int rear = 0;
	
	for(int i=0; i<gridSize; i++){ //썩은 오렌지 찾기
		for(int j=0; j<*gridColSize; j++){
			if(grid[i][j] == 2){
				queue[rear++] = (pos){i,j};
			}
		}
	}
    int minute = 0;

    int size = rear - front;
	while(size){ //queue가 empty면 정지
		for(int i=0; i<size; i++){
			int row = queue[front].p_row;
			int col = queue[front++].p_col;

			int dr[4] = {0,0,1,-1};
			int dc[4] = {1,-1,0,0};
			for(int j=0; j<4; j++){
				int r = row + dr[j];
				int c = col + dc[j];
				if(r < 0 || r >= gridSize || c < 0 || c >= *gridColSize) continue;
				if(grid[r][c] == 1){
					queue[rear++] = (pos){r,c};
					grid[r][c] = 2;
				}
			}
		}
        size = rear - front;
		if(size) minute++; //enqueue가 실행 됐을 시 minute++;
	}

	for(int i=0; i<gridSize; i++){
		for(int j=0; j<*gridColSize; j++){
			if(grid[i][j] == 1) return -1; //fresh ornage가 남아있으면 -1
		}
	}

	return minute;
}

