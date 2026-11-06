static int **visited; //방문 체크
static int m;//gridSize
static int n;//gridColSize
static int size;//island size

int island_size(int **, int, int);

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize) {
	m = gridSize;
	n = *gridColSize;
	visited = malloc(sizeof(int*) * m);
	for(int i=0; i<m; i++) {
		visited[i] = malloc(sizeof(int) * n);
		for(int j=0; j<n; j++) visited[i][j] = 0;
	}
	
	int maxsize = 0;
    size = 0;

	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			if(visited[i][j] == 0 && grid[i][j] == 1) {
				size++;
				visited[i][j]=1; //island 시작점
				size = island_size(grid, i, j); //island size 파악
                if(maxsize < size) maxsize = size;
                size = 0;
			}
		}
	}
	
	return maxsize;
}

int island_size(int **grid, int i, int j){
	if(j + 1 != n && grid[i][j+1] ==1 && visited[i][j+1] == 0){ //오른쪽
		visited[i][j+1] = 1;
		island_size(grid, i, j+1);
		size++;
	}
	if(j != 0 && grid[i][j-1] ==1 && visited[i][j-1] == 0){ //왼쪽
		visited[i][j-1] = 1;
		island_size(grid, i, j-1);
		size++;
	}
	if(i != 0 && grid[i-1][j] == 1 && visited[i-1][j] == 0){ //위
		visited[i-1][j] = 1;
		island_size(grid, i-1, j);
		size++;
	}
	if(i + 1 != m && grid[i+1][j] == 1 && visited[i+1][j] == 0){//아래
		visited[i+1][j] =1;
		island_size(grid,i+1,j);
		size++;
	}
	return size;
}

