/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

typedef struct parameters{
	int** answer;
	int* nums;
    int* copy;
	int* sub_size;
	int size;
	int res_cnt;
	int start;
}params;

void backtrack(params* , int, int, int);

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
	//자료 선언 및 초기화
	int used[10]={0,}; //사용 여부 배열
	params p;
	p.nums = nums;
	p.size = numsSize;
	p.res_cnt = 0;
	
	//해 개수 계산
	*returnSize = 1;
	for(int i=0; i<numsSize; i++) *returnSize *= 2;
	
	//답 포인터 구성
	p.answer = malloc(sizeof(int *) * (*returnSize));
	for(int i=0; i< *returnSize; i++) p.answer[i] = malloc(sizeof(int) * p.size);
	
    //copy 배열 구성
    p.copy = malloc(sizeof(int) * p.size);

	//sub_size 배열 구성
	p.sub_size = malloc(sizeof(int) * (*returnSize));

	//backtracking
	for(int i=0; i<=p.size; i++){
        backtrack(&p, 0, 0, i); //subsize를 i로 함수에 주기
    }
	//반환 값
	*returnColumnSizes = malloc(sizeof(int) * (*returnSize));
    for(int i=0; i< *returnSize; i++) (*returnColumnSizes)[i] = p.sub_size[i];

    //할당 해제
    free(p.copy);

	return p.answer;
}

void backtrack(params* p, int depth, int start, int size){
		if(depth == size){
			p->sub_size[p->res_cnt] = size;
            for(int i=0;i<size;i++) p->answer[p->res_cnt][i] = p->copy[i];//copy 저장
            p->res_cnt++;
			return;
		}
		for(int i=start; i<p->size; i++){ //중복이 제외임으로 start가 첫 원소로 들어가는 집합이 start가 집합에 들어갈 수 있는 전부이다.
				p->copy[depth] = p->nums[i];
				backtrack(p, depth + 1, i + 1, size); //start 하나 올리기
			}
        return;
}
