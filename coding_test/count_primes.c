#include <stdio.h>

int countPrimes(int n){
	int prime[5000001]={0 ,};//0으로 배열 초기화
	for(int i=2; i<n; i++){//소수가 아닌 0과 1을 제외하고 n까지 1 초기화
		prime[i]=1;
	}
	int cnt = 0;
	for(int i=2; i<n; i++){
		if(prime[i]){//소수라면
			for(int j=2; j<=n/i; j++){
				prime[i*j]=0; //그의 배수들은 소수 아니므로 0 대입
				}
			cnt++;
		}
	}
	return cnt;
}
