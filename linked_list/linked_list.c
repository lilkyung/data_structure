#include <stdio.h>
#include <stdlib.h>

typedef struct linked_list{
	int data;
	int idx;
	struct linked_list *link; // 다음 데이터 주소 가르키기
}list;


list* insert_first(list *first,int num){//연결 리스트 맨 앞에 데이터 추가하기
	
	list *pl=(list *)malloc(sizeof(list)); //데이터를 추가할 때마다 동적할당하기
	pl->data = num; //데이터 추가하기
	pl->link = first; //기존 front를 가르킴으로써 맨 앞 자리 먹기
	first = pl; //first를 pl로 바꿔서 이제는 pl이 first
	return first;
} 

list* delete_first(list *first){ // 첫 데이터 삭제하기
	list *remove; //제거할 놈 담을 그릇 만들기
	remove=first; //제거할 놈 그릇에 담기
	first=first->link; //제거 후 주소 잇기
	free(remove); //제거한 데이터 free해주기
	return first; //첫 데이터를 없앤 새로운 연결리스트 완성
}

int search(list *first, int num){ //재귀로 다음 노드로 움직이며 조회하기
	if(first->idx==num){
		printf("%d번 데이터: %d\n",first->idx, first->data);
		return 0;
	}
	else{
		return search(first->link,num);
	}
}

int traversal(list *first){ //재귀로 순회
	if(first == NULL){
		printf("\n");
		return 0;
	}
	else{
		printf("%d번 데이터: %d\n",first-> idx,first->data); //순회하면서 데이터 출력
		return traversal(first->link); //재귀로 계속 실행
	}
	
}

int organize_list(list *first,int seq){ //idx 재정리해주기.
	if(first == NULL){
		return seq; //seq는 곧 size이기 때문에 길이 반환
	}
	else{
		first->idx=seq++; //idx에 몇번째 순서인지 대입하기
		return organize_list(first->link,seq); //재귀로 계속 실행
	}
	
}


int main(){	
	int com, num, length = 0; //명령어, 입력 데이터, list 길이
	list *p=NULL;
	do{
		printf("\n명령을 실행하기\n");
		printf("1.insert\n");
		printf("2.delete\n");
		printf("3.search\n");
		printf("4.traversal\n");
		printf("5.length\n");
		printf("6.exit\n");
		printf("\n숫자 입력하기:");
		scanf("%d",&com);
		if(com==1){
			printf("값을 입력하시오:");
			scanf("%d",&num);
			p = insert_first(p,num);
		}
		else if(com==2){
			p = delete_first(p);
		}
		else if(com==3){
			if(!length){ //길이가 0이면 데이터 없다고 알리기
				printf("list is empty\n");
			}
			else{
				printf("몇번 데이터를 불러올까요?:");
				scanf("%d",&num);
				if(num>=length) { //길이보다 길면
					printf("데이터가 없습니다.\n");
				}
				else search(p,num);
			}
		}
		else if(com==4){
			if(length) traversal(p);
			else printf("list is empty\n");
		}
		else if(com==5){
			printf("길이: %d\n", length);
		}
		length = organize_list(p,0);
	}while(com!=6);




	return 0;
}
