//102 Binary Tree Level Order Traversal

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
	*returnColumnSizes = malloc(sizeof(int) * 2001);
	*returnSize = 0;
	int **res = malloc(sizeof(int *) * 2001); //최대 level 2001
	if(root == NULL) return res;
	int level = 0;
	struct TreeNode **queue = malloc(sizeof(struct TreeNode *) * 2001); //node의 최대 개수가 2001
	
	queue[0] = root;//큐에 노드를 담기

	int front = 0, rear = 1, size = 1;//front == (dequeue 해야할 idx), rear = (enqueue 해야 할 위치)
	
	while(size){ //size가 0일 때 중단, size == the number of parent node
		for(int i=front; i<front + size; i++){ //자식 노드 enqueue;
			if(queue[i] -> left) queue[rear++] = queue[i] -> left; //왼쪽 자식이 있다면
			if(queue[i] -> right) queue[rear++] = queue[i] -> right; //오른쪽 자식이 있다면
		}
		int *copy = malloc(sizeof(int) * size); //level 별 node-> val 담을 배열
		int idx = 0; //copy용 idx
		for(int i = 0; i < size; i++){ //dequeue + copy, front를 건들고 i는 사용하지 않는 반복문이므로 조건을 위 조건문과는 다르게 쓰기
			copy[idx++] = queue[front] -> val;
			front++;
		}
		(*returnColumnSizes)[level] = size;
		res[level++] = copy; //결과에 담기
		size = rear - front; //size 최신화
	}
	*returnSize = level;

	free(queue);

	return res;

	
}


