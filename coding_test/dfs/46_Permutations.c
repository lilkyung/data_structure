/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
static int idx;
static int** answer; //답
static int* arr; //완성 조합 임시 저장고
static int cnt;

void backtrack(int* , int*, int);
void save(int*, int);

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
	int n = numsSize;
	int used[6] = {0,};
	idx = 0;
	cnt = 0;
	
	arr = malloc(sizeof(int *) * 6);
	answer = malloc(sizeof(int *) * 720);

	backtrack(nums, used, n);

	*returnSize = cnt;
	*returnColumnSizes = malloc(sizeof(int) * cnt);
	for(int i=0; i<cnt; i++) (*returnColumnSizes)[i] = n;
	
	free(arr);
	return answer;

}

void backtrack(int* nums, int* used, int n){
	if(idx == n){
		save(nums, n);
		return;
	}
	for(int j=0; j<n; j++){ //원소 찾아서 넣기
		if(!used[j]){
			arr[idx++] = nums[j];
			used[j] = 1; //j번째 수 사용체크
			backtrack(nums, used, n);
			used[j] = 0;
            idx--; //재귀가 들어간 만큼 idx도 --해주기
		}
	}
}
/*if(idx == n){
		save(nums, n);
		idx = 1;    save되면 첫 원소로 돌아간다고 생각했었음. [1, 2, 3]까지는 잘 돌아가서 제출하고 발견
		return;
	}
*/
void save(int* nums, int n){
	int* copy = malloc(sizeof(int) * n);

	for(int i=0; i<n; i++) copy[i] = arr[i];

	answer[cnt++] = copy;
	
	return;
}
