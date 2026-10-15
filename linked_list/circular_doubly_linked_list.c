#include <stdio.h>
#include <stdlib.h>

typedef struct list{
	int data;
	struct list *pre_link; 
	struct list *next_link;
}list;

void init(list *); //리스트 초기화
void insert_first(list *, int); //첫 위치 삽입
void delete_first(list *, list *); //첫 위치 삭제
void print_list(list *); //리스트 출력

int main(){
	
	int com, num; //명령어, data
	list *head = (list *)malloc(sizeof(list)); //head는 맨 앞 노드만 가르키고 실적적 데이터는 없다.
	init(head);

	while(1){
		printf("1.insert_first\n");
		printf("2.delete_first\n");
		printf("3.exit\n");
		printf("Enter the command: ");
		scanf("%d",&com);

		if(com==1){
			printf("data: ");
			scanf("%d",&num);
			insert_first(head,num);
		}
		else if(com==2){
			delete_first(head, head->next_link);
		}
		else break;
		print_list(head);
	}
	free(head);

	return 0;
}

void init(list *head){
	head->pre_link = head;
	head->next_link = head;
}

void insert_first(list *head, int num){ //파라미터는 head 주소와 data

	list *p=(list *)malloc(sizeof(list));
	p->data = num;
	p->pre_link = head; //head랑 연결시키며 첫번쨰 노드가 됨
	p->next_link = head->next_link; //p의 다음 노드가 기존 첫번쨰 노드가 되면서 p가 맨 앞에 삽입 완료.
	head->next_link->pre_link=p;//삽입 완료된 p에 기존 첫번째 노드의 pre_link 연결
	head->next_link = p;//head가 삽입 완료된 p를 연결
}

void delete_first(list *head,list* remove){ //파라미터는 head 주소와 head->next_link 주소
	if(remove == head) return; //head와 같으면 지울게 없으므로 return
	remove->next_link->pre_link = remove->pre_link; //remove의 다음 노드의 pre_link를 remove의 전 노드와 연결
	remove->pre_link->next_link=remove->next_link; //remove의 전 노드의 next_link를 remove의 다음 노드와 연결
	free(remove);
}

void print_list(list* head){
	for(list* p=head->next_link; p != head; p = p->next_link){ //head 다음부터 데이터가 있기 때문에 다음 노드부터 호출 후 p가 head가 되는 순간 종료
		printf("<%d> ", p->data);
	}
	printf("\n");
}



