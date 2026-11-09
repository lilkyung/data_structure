/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

//returnSize = 해 개수, *returnColumnSizes[i] = numsSize

static int idx;
static int size;
static int** answer; //답
static int* arr; //완성 조합 임시 저장고
static int cnt;

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
	int n = numsSize;
	int used[6] = {0,};
	idx = 0;
	size = 0;
	cnt = 0;
	
	arr = malloc(sizeof(int *) * 6);
	answer = malloc(sizeof(int *) * 720);

	for(int i=0; i<n; i++){ //첫번째 원소 정해주기
		arr[idx++]=nums[i];
		used[i]=1;
		backtrack(nums, used, n);
		used[i]=0;
	}
	*returnSize = cnt;
	returncolumnSizes = malloc(sizeof(int *) * cnt);
	for(int i=0; i<cnt; i++) {
		*returncolumnSizes = malloc(sizeof(int) * n);

	
	free(arr);

}


void backtrack(int* nums, int* used, int n){
	if(idx == n){
		save(nums);
		idx = 0;
		return;
	}
	for(int j=0; j<n; j++){ //다음에 올 원소 찾아서 넣기
		if(!used[j]){
			arr[idx++] = nums[j];
			used[j] = 1; //j번째 수 사용체크
			backtarck(nums, used, n);
			used[j] = 0;
		}
	}
}

void save(int* nums){
	int* copy = malloc(sizeof(int) * n);

	for(int i=0; i<n; i++) copy[i] = arr[i];

	*answer[size++] = copy;
	cnt++;
	
	return;
}
