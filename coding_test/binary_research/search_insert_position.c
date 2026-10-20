int searchInsert(int* nums, int numsSize, int target) {
	int left = 0, right = numsSize - 1;
	int idx;
	while(left <= right){ //이분 탐색
		idx = (right - left) / 2 + left;
		if(nums[idx] == target) break;
		else if(nums[idx] > target){
			right = idx - 1;
		}
		else{
			left = idx + 1;
		}
	}
	if(nums[idx] >= target) return idx; //nums[idx]가 target보다 크거나 같으면 데이터가 삽입될 위치는 idx 자리이다.
	else return idx + 1;//nums[idx]가 target보다 작으면 idx보다 한 칸 앞에 삽입된다.
}
