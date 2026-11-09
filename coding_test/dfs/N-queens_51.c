//51 N-Queens

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

static int N; //n을 받을 변수
static char ***res; //찾은 해들
static char **board; //작업 중인 판
static int *dis; //퀸이 들어있는 지 판별하는 배열
static int rescnt; //해 개수

void backtrack(int);
bool valid(int, int);
void save(void);

//returnSize와 returnColumnSizes는 leetcode 출력을 위한 파라미터

char*** solveNQueens(int n, int* returnSize, int** returnColumnSizes) {//returnSize = the number of answer
	N = n;
	rescnt = 0;

	res = malloc(sizeof(char **) * 400); //n이 최대일 때 해는 352
	board = malloc(sizeof(char *) * N);
	for(int i=0; i<N; i++){
		*(board + i) = malloc(sizeof(char) * (N + 1));
		memset(*(board + i), '.', N); //'.'으로 문자열 채우기, stirng.h 파일 안에 함수
		board[i][N] = '\0'; //널 문자 추가하기
	}
	
	dis = malloc(sizeof(int) * N);

	backtrack(0);

	*returnSize = rescnt;
	*returnColumnSizes = malloc(sizeof(int) * rescnt); //**returnColumnSizes라는 이중 포인터를 받고 이중포인터가 가르키는 주소에 배열을 선언해야 하므로 *returnColumnSizes에 malloc 선언 
	for(int i=0; i<rescnt; i++) (*returnColumnSizes)[i] = n;

	for(int i=0; i<N; i++) free(board[i]);
	free(board);
	free(dis);
	
	return res;
}

void backtrack(int row){
	if(row == N){
		save();
		return;
	}
	for(int col = 0; col<N; col++){
		if(valid(row,col)){
			dis[row]=col;
			board[row][col] = 'Q';
			backtrack(row+1);
			board[row][col] = '.';
		}
	}
}

bool valid(int row,int col){
	for(int i=0; i<row; i++){
		if(dis[i] == col || dis[i] - i == col - row || dis[i] + i == col + row) return false;
	}
	return true;
}

void save(void){
	char **copy = malloc(sizeof(char *) * N);
	for(int i=0; i<N; i++){
		*(copy + i) = malloc(sizeof(char) * (N + 1));
		strcpy(*(copy + i), board[i]);
	}
	res[rescnt++] = copy;
}
