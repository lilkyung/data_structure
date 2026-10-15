#include <stdio.h>
#include <stdlib.h>

typedef struct linked_list{
	int data;
	int idx;
	struct linked_list *link; // 다음 데이터 주소 가르키기
}list;

list* insert(list *first, int seq, int num); //삽입
list* delete(list *first,int seq); //삭제
list* search(list *first, int num); //탐색
void traversal(list *first); //순회
int organize_list(list *first,int seq); //idx 최신화

list* insert(list *first, int seq, int num){	
	list *pl=(list *)malloc(sizeof(list)); //데이터를 추가할 때마다 동적할당하기
	pl->data = num; //데이터 추가하기
	
	if(seq){//첫 원소에 insert가 아닌 경우
		list *tmp; //임시 포인터 만들기
		pl->link = search(first, seq); //원하는 위치(seq)에 데이터 넣고 다음 주소 가르키기
		tmp = search(first,seq - 1); //seq - 1번 데이터를 pl과 연결하기 위해서 임시로 담아놓기
		tmp->link=pl; //pl에 연결
	}
	else{//첫 원소에 insert인 경우
	     	pl->link=first;
		first=pl; //pl을 첫번째로 만들기
	}
	return first; //free는 데이터 삭제할 떄 하기
}

list* delete(list *first,int seq){ //데이터 삭제하기
	list *remove, *tmp; //제거할 놈 담을 그릇 만들기 + 임시 포인터
	if(seq){//첫 원소가 아닌 원소를 delete
		tmp = search(first,seq - 1);//제거할 데이터 앞에 있는 데이터 복사
		remove = search(first,seq); //제거할 놈 그릇에 담기
		if(remove->link==NULL) tmp->link=NULL; //제거할 놈 다음이 null이면 tmp(제거할 놈 전 데이터)가 null을 가르켜야함.
		else tmp->link = remove->link; //제거할 놈 다음 걸 tmp에 연결
	}
	else{//첫 원소 delete
		remove=first; //first를 지워야 함으로 remove에 담기
		first=first->link; //first->link를 first에 대입해서 first 만들기
	}
	free(remove);
	return first; //데이터를 없앤 새로운 연결리스트 완성
}

list* search(list *first, int num){ //찾은 데이터를 return
	if(first->idx==num){ //찾는 데이터 맞으면 정지
		return first;
	}
	else{
		if(first->link==NULL) return NULL;
		return search(first->link,num);
	}
}

int traversal(list *first){ //순회
	if(first == NULL){
		printf("\n");
		return 0;
	}
	else{
		printf("%d번 데이터: %d\n",first-> idx,first->data); //순회하면서 데이터 출력
		return traversal(first->link); //재귀로 계속 실행
	}
	
}

int organize_list(list *first,int seq){ //idx 재정리해주기 이렇게 따로 만들어 놓으면 insert나delete에서 idx를 정리할 필요 없음.
	if(first == NULL){
		return seq; //길이 반환
	}
	else{
		first->idx=seq++; //idx에 몇번째 순서인지 대입하기
		return organize_list(first->link,seq); //재귀로 계속 실행
	}
	
}


int main(){ 
	int com, num, length = 0, pos; //명령어, 입력 데이터, list 길이, 입력 위치
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
			printf("data: ");
			scanf("%d",&num);
			printf("where?: ");
			scanf("%d",&pos);
			if(pos>length) printf("!!!warning: list 길이보다 큰 번지 수에는 데이터를 추가할 수 없습니다.!!!\n");
			else if(pos<0) printf("Invaild index\n");
			else p = insert(p,pos,num);
		}
		else if(com==2){
			printf("where?: ");
			scanf("%d",&pos);
			if(pos < 0 || pos>=length) printf("Invaild index\n");
			else p = delete(p,pos);
		}
		else if(com==3){
			if(!length){ //길이가 0이면 데이터 없다고 알리기
				printf("list is empty\n");
			}
			else{
				printf("몇번 데이터를 불러올까요?:");
				scanf("%d",&num);
				if(num>=length) {
					printf("데이터가 없습니다.\n");
				}
				else{
				       list *tmp = search(p,num);
				       printf("%d번 데이터: %d\n",tmp->idx,tmp->data);
				}
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


