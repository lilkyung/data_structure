static char **visited; //방문 체크
static int m;//gridSize
static int n;//gridColSize

void island(char **, int, int);

int numIslands(char** grid, int gridSize, int* gridColSize) {
	m = gridSize;
	n = *gridColSize;
	visited = malloc(sizeof(char*) * m);
	for(int i=0; i<m; i++) {
		visited[i] = malloc(sizeof(char) * n);
		memset(visited[i],'0',n); //visited를 동적할당 했기 때문에 memset을 사용해야 함으로 visited 함수를 char** 로 설정
	}

	int islandcnt = 0;
	
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			if(visited[i][j] == '0' && grid[i][j] == '1') {
				visited[i][j]='1'; //island 시작점
				island(grid, i, j); //island 파악
				islandcnt++; //island 추가
			}
		}
	}
	
	return islandcnt;
}

void island(char **grid, int i, int j){
	if(j + 1 != n && grid[i][j+1] =='1' && visited[i][j+1] == '0'){ //오른쪽
		visited[i][j+1] = '1';
		island(grid, i, j+1);
	}
	if(j != 0 && grid[i][j-1] =='1' && visited[i][j-1] == '0'){ //왼쪽
		visited[i][j-1] ='1';
		island(grid, i, j-1);
	}
	if(i != 0 && grid[i-1][j] == '1' && visited[i-1][j] == '0'){ //위
		visited[i-1][j] = '1';
		island(grid, i-1, j);
	}
	if(i + 1 != m && grid[i+1][j] == '1' && visited[i+1][j] == '0'){//아래
		visited[i+1][j] ='1';
		island(grid,i+1,j);
	}
	return;
}

