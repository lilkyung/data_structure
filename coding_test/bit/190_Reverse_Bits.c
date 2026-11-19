int reverseBits(int n) {
    int bit = 1;
    int result = 0;
    int two = 1;
    two = two << ((sizeof(int) << 3) - 2); //비트의 양 끝은 1이 들어갈 수 없음. n이 even이면서 항상 양수
    for(int i=1; i < (sizeof(int) << 3) - 1; i++){
        if(n & bit << i) result += two;
        two/=2;
    }
    return result;
}

//if(n & bit << ((sizeof(int) << 3) - 1)) result -=two; signed int를 쉬프트 시켜서 음수가 되게 할 수 없음. + 음수는 left shift 불가능

/* int 1을 왼쪽 쉬프트 하면서 비트가 1인곳 찾기
찾았으면 해당 2 ^ (31 - index) result에 더하기
*/
