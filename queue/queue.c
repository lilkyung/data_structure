#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

typedef struct Queue{ //queue 구조체
   int front; //출력할 곳
   int rear; //입력 받을 곳
   int data[SIZE]; //data 몇개 들어갈 지
}Queue;

void init(Queue *q){ 
   q->front = 0;
   q->rear = 0;
}

int is_empty(Queue *q){ 
   return q->rear == q->front; //입력 받을 곳이 출력할 곳과 같으면 empty 
}

int is_full(Queue *q){ 
   return q->rear - q->front == SIZE; //rear - front이 SIZE라면 full
}

void enqueue(Queue *q, int num){
   if(is_full(q)){
      printf("Queue is full\n");
      exit(1);
   }
   q->data[q->rear % SIZE] = num;//데이터를 삽입
   q->rear++;
}
void dequeue(Queue *q){
   if(is_empty(q)){
      printf("Queue is empty\n");
      exit(1);
   }
   printf("%d\n", q->data[q->front % SIZE]);//데이터 호출
   q->front = (q->front + 1);
}

void queue_front(Queue *q){
	printf("%d\n",q->data[(q->rear - 1) % SIZE]);//출력
	return;
}

int main (){

   Queue q;
	
   init(&q);

   enqueue(&q,3);
   enqueue(&q,2);
   enqueue(&q,4);
   enqueue(&q,6);
   enqueue(&q,1);

   queue_front(&q);

   dequeue(&q);
   dequeue(&q);
   dequeue(&q);
   dequeue(&q);
   dequeue(&q);
   dequeue(&q);

   return 0;
}
