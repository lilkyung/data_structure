/* 양수로 만들어서 풀기
divisor의 MSB를 dividend의 MSB 자리까지 shift 시켜서 빼고 2 ^ (shift 번호)을 sum하기

-2^31은 unsigned하면 그냥 2^31이 된다.
*/
int return_msb_idx(unsigned);

int divide(int dividend, int divisor) {
    int minus = 1;
    unsigned end = (unsigned) dividend;
    unsigned sor = (unsigned) divisor;
    if(dividend < 0){ //음수면 양수 만들기
        minus--;
        end = ~end + 1; 
    }
    if(divisor < 0){
        minus--;
        sor = ~sor + 1;
    }
    if(end < sor) { //2^31은 못들어온다. msb가 1이니까 제일 큼. 여기 다 int 범위
        return 0;
    }
    int end_idx = 0;
    int sor_idx = return_msb_idx(sor); //sor의 MSB idx 구하기
    unsigned sum = 0;
    while(end >= sor){
        unsigned tmp = 0;
        end_idx = return_msb_idx(end); //end의 MSB idx 구하기
        int shift = end_idx - sor_idx;
        tmp = sor << shift;
        if(tmp > end) {
            tmp >>= 1; //unsigned여서 논리 쉬프트
            shift--;
        }
        end -= tmp;
        sum += 1u << shift;
    }
    if(minus == 0) sum = ~sum +1;
    else{
        if(sum >= 1u << 31) sum = (1u << 31) - 1;
    }
    return (int) sum;
}

int return_msb_idx(unsigned dividend){
    unsigned tmp = dividend;
    unsigned msb = 0;
    int idx = 0;
    for(int i=0; i<5; i++){
            tmp |= tmp >> (1 << i);
    }
    msb = tmp ^ (tmp >> 1);
    while(msb >= 1){
        idx++;
        msb >>= 1;
    }
    return idx;
}
