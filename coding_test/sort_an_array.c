//leetcode 912 Sort an Array

//시간 복잡도 신경 안쓰고 기본 정렬로 구현하기

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//insertion sort로 구현

int* sortArray(int* nums, int numsSize, int* returnSize) {
	for(int i=1; i<numsSize; i++){
		int idx = i - 1, tmp; //idx=i-1로 설정해서 nums[i] 보다 앞에 위치한 데이터들을 nums[i]와 크기 비교
		tmp=nums[i]; //nums[i]가 앞에 위치한 데이터 보다 값이 작으면 nums[i] 자리에 넣어야하므로 기존 nums[i] 값을 tmp에 저장
		while(idx >= 0 &&tmp < nums[idx]) {//선택한 데이터가 들어갈 idx 위치 찾기(i 자리부터 앞으로 가면서 위치 맞는지 확인)
			nums[idx + 1]=nums[idx]; //선택한 데이터가 앞 데이터보다 작으면 앞 데이터 한 칸 뒤로 밀기
			idx--; //앞앞 데이터 idx 접근
		}
		nums[idx + 1]=tmp; //적당한 위치 idx+1에 선택한 데이터 삽입
	}
	return nums;
}
