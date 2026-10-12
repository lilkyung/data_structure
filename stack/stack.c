#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

typedef struct StackType{ //stack을 실현할 구조체
	int arr[SIZE]; //stack을 이용할 배열 만들기
	int top; //top 원소 기억하기
} StackType; 

void init(StackType *s){
	s->top =-1; //stack 초기화
}

bool is_empty(StackType *s){
	if(s->top==-1)
		return 1; //stack이 비었을 시true
	return 0; //stack이 차 있을 시 false
}

bool is_full(StackType *s){
	if(s->top == SIZE - 1)
		return 1; //stack이 가득 찼을 시 true
	return 0; //stack이 가득 차 있지 않을 시 false
}

void push(StackType *s, int value){ //삽입
	if(is_full(s)){ //가득 찼을 시
		printf("Stack is full\n"); //가득 차서 push 못 함
		exit(1); //함수 종료
	}
	printf("\npushed: %d\n", value); //가득 차지 않은 경우 push 실행
	s->arr[++(s->top)]=value; //stack의 top 원소 다음 칸에 삽입
}

int pop(StackType *s){ //제거
	if(is_empty(s)){ //비었을 시
		printf("Stack is empty\n"); //비어서 pop 못함
		exit(1); //함수 종료
	}
	//비어있지 않은 경우 pop 실행
	return s->arr[(s->top)--]; //top 원소 return하고 top 원소 전 원소로  최신화
}

int peek(StackType *s){ //top 원소 조회
	if(is_empty(s)){ //비었을 시
		printf("Stack is empty\n"); //비어서 조회 못함
		exit(1);//함수 종료
	}
	return s->arr[(s->top)]; //top 원소 return
}

int main(){
	StackType s; //stack 구조체 생성
	init(&s); //stack 초기화
	
	push(&s, 3);//삽입
	push(&s, 2);
	push(&s, 1);

	printf("\npeek: %d\n", peek(&s)); //top 원소 조회
	printf("\npop: %d\n", pop(&s)); //제거
	printf("\npop: %d\n", pop(&s));
	printf("\npop: %d\n", pop(&s));
	
	printf("\npop: %d\n", pop(&s));//비었을 때 실행해서 예외 코드 실행해보기

		
	return 0;
}

