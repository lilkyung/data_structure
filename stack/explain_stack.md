# Stack

# stack이란?

FILO(First In Last Out, 후입선출)의 형태를 띈 추상적 자료형이다.

# 연산

## push

- 데이터를 맨 위에 추가한다.

## pop

- 데이터의 맨 위를 제거한다.

## peek

- 데이터 맨 위의 값을 조회한다

## is_full

- 스택이 가득 차 있는지 조회한다. 차있으면 1 비었으면 0

## is_empty

- 스택이 비어있는지 조회한다. 차있으면 1 비었으면 0

# 사용예시

방문 기록, 실행 취소, 함수 호출 등이 있다.

# 직면했던 문제와 해결법

- stack_test 코드를 구현하면서 배열에 조건문을 사용하려고 하니 보기 불편했다
    
    → 깔끔하게 포인터로 처리를 했다. 
    

```c
//이런 코드를
for(int i=0; i<len; ++i){
	if(arr[i]='(' || arr[i] = '{' || arr[i] ='['){
				}
	}

//아래와 같이 바꿈
	for(char *p=arr; p < arr + len; ++p){
		if(*p=='(' || *p == '{' || *p =='['){
					}
		}
```

- scanf를 쓰니 buffer overflow(입력값이 정해진 양보다 많이 들어옴)를 일으킬 수 있다
    
    → 더 안전한 fgets를 사용했다. (이 과정에서 strlen과 strcspn을 사용하기 위해 헤더파일 <string.h> 사용)
    
    ※ strlen(char *s): 문자열 s안 ‘\0’을 만나기 전까지의 s의 길이를 구함.
    
    ※ strcspn(char *s, char *p): 문자열 s 안에서 문자열 p가 처음으로 나오는 index 반환.
