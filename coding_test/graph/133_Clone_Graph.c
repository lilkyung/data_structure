/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numNeighbors;
 *     struct Node** neighbors;
 * };
 */

struct Node *copy_graph(struct Node *, struct Node *[]);

struct Node *cloneGraph(struct Node *s) {
	if(s==NULL) return NULL;
	struct Node *clone[101]={0,}; //copy 구조체 포인터를 받을 배열 초기화
	return copy_graph(s, clone);
}
	
struct Node *copy_graph(struct Node *s, struct Node *clone[]){
	if(clone[s->val] != NULL){ //이미 들린 노드
		return clone[s->val];
	}
	struct Node *copy = malloc(sizeof(struct Node));
	copy->val = s->val;
	copy->numNeighbors = s->numNeighbors;
	copy->neighbors = malloc(sizeof(struct Node*) * copy->numNeighbors);
	clone[s->val] = copy; //clone에 정보 저장
	for(int i=0; i<copy->numNeighbors; i++){
		copy->neighbors[i] = copy_graph(s->neighbors[i], clone); //dfs
	}
	return copy;
}
