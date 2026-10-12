//괄호 검사 코드
#include <stdio.h>
#include <string.h> //strlen, strcspn 쓰기 위한 헤더파일

int main(){

	char arr[10001], stack[10001]; //입력값(arr)과 스택을 구현(stack)할 배열을 생성 
	int s_cnt = 0,m_cnt = 0,l_cnt = 0; //작은 괄호, 중간 괄호, 큰 괄호 개수를 세기위한 변수 생성
	int len, idx=0;//문자열 길이, 인덱스 받을 변수 생성

	fgets(arr,10001,stdin);//문자열 입력 받기
	arr[strcspn(arr, "\n")] = '\0'; //개행 문자 처리하기
	len=strlen(arr);//문자열 길이

	for(char *p=arr; p < arr + len; ++p){ //p가 arr의 끝까지 돌기
		if(*p=='('){ //열린 괄호 시 그에 해당하는 닫힌 괄호 담기 (닫힌 괄호만 봐도 검사가 된다)
			stack[idx++]=')';
		}
		else if(*p=='{'){
			stack[idx++]='}';
		}
		else if(*p=='['){
			stack[idx++]=']';
		}
		else{ //닫힌 괄호를 만난다면 스택의 top 원소와 입력된 괄호를 비교
			if(idx - 1 < 0 || *p != stack[--idx]){ //idx가 음수가 되는 걸 막음 || top 원소와 입력된 괄호가 다르면 false
				printf("false\n");
				return 0;
			}
		}
	}
	if(idx!=0) printf("false\n"); //여는 괄호 하나만 입력 했을 때 false
	else printf("true\n");
	return 0;
}
