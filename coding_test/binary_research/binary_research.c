int search(int* nums, int numsSize, int target) {
	int left = 0, right = numsSize - 1; //left: 왼쪽 idx, right: 오른쪽 idx
	int idx;
	while(left <=right){//left가 right보다 크거나 같을 때까지
		idx = (right - left) / 2 + left; //버퍼 overflow 방지
		if(nums[idx] == target) return idx; //같으면 출력
		if(nums[idx] > target) {//target이 값 보다 작을 때 idx보다 왼쪽에 있다.
			right = idx - 1; //right를 idx - 1로 최신화(오른쪽 탐색)
		}
		else{//target이 값 보다 클 때 idx보다 오른쪽에 있다.
			left = idx + 1; //left를 idx + 1로 최신화(왼쪽 탐색)
		}
	}
	return -1;
}
