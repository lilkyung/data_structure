int mySqrt(int x) {
	int left = 0, right = x, sqrt=0;
	if(x == 0 || x == 1) return x; //0이나 1이 입력되면 sqrt가 0이 될 수 있어서 미리 제거
	while(left <= right){ //x보다 작거나 같은 수 속에서 이진 탐색으로 제곱근 찾기
		sqrt = (right - left) / 2 + left;
		if(x / sqrt == sqrt) return sqrt; //제곱근 찾으면 출력
		else if(x / sqrt > sqrt){ //sqrt가 찾으려는 제곱근 보다 작을 때
			left = sqrt + 1;
		}
		else{//sqrt가 찾으려는 제곱근 보다 클 때
			right = sqrt - 1;
		}
	}
	if(x / sqrt > sqrt) return sqrt; // sqrt가 찾으려는 제곱근 보다 작을 때 그대로 출력
	else return sqrt - 1; //sqrt가 찾으려는 제곱근 보다 클 때 -1 해서 출력
}

