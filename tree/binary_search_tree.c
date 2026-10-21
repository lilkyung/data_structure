#include <stdio.h>
#include <stdlib.h>

typedef struct Tree{
	int data;
	struct Tree *l_link;//왼쪽 서브트리
	struct Tree *r_link;//오른쪽 서브트리
}Tree;

Tree *newnode(int); //새로운 노드 만들기
Tree *insert(Tree *,int);//노드 적절한 위치 삽입
Tree *search(Tree *,int);//탐색
void inorder(Tree *);//중위 순회

int main(){

	Tree *node=NULL;
	int num, com;
	
	while(com!=4){
		printf(" 1.insert\n 2.search\n 3.inorder\n 4.exit\n enter the number: ");
		scanf("%d",&com);
		if(com==1){
			printf(" data: ");
			scanf("%d",&num);
			node=insert(node,num);
		}
		else if(com==2){
			printf(" data: ");
			scanf("%d", &num);
			if(search(node, num)==NULL){
				printf("%d isn't in tree.\n", num);
			}
			else{
				printf("%d is in tree.\n",num);
			}
		}
		else if(com == 3){
			inorder(node);
			printf("\n");
		}
		else break;
	}



	return 0;
}

Tree *newnode(int num){
	Tree *p =(Tree *)malloc(sizeof(Tree));
	p->data = num;
	p->l_link = NULL;
	p->r_link = NULL;
	return p;
}

Tree *insert(Tree *p, int num){
	if(p==NULL) return newnode(num); //적절한 위치 도착. 노드 생성
	else{
		if(num > p->data) p->r_link = insert(p->r_link,num);
		else if(num < p->data) p->l_link = insert(p->l_link,num);
	}
	return p;
}

Tree *search(Tree *p, int num){
	if(p==NULL) return p;
	if(p->data == num) return p;
	else if(num > p->data) return search(p->r_link,num);
	else return search(p->l_link,num);
}

void inorder(Tree *p){
	if(p){
		inorder(p->l_link);
		printf("%d ",p->data);
		inorder(p->r_link);
	}
}

