/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int dfs(struct TreeNode*, int, int);

bool hasPathSum(struct TreeNode* root, int targetSum) {
	if(root == NULL) return 0; //tree is emtpy
	int sum=0;
	return dfs(root,targetSum,sum);
}

int dfs(struct TreeNode* tree, int targetSum, int sum){ 
	sum += tree->val;
	if(tree->left == NULL && tree -> right == NULL){ //leaf node
		if(sum==targetSum) return 1;
	}
	else if(tree-> right == NULL) return dfs(tree->left, targetSum,sum); //only has left node
	else if(tree -> left == NULL) return dfs(tree->right, targetSum,sum); //only has right node
	else{ //재귀가 양쪽방향으로 이뤄지니 한 쪽에서 값을 찾았으면 반대쪽 안가고 종료
		if(dfs(tree->left, targetSum,sum)) return 1;
		return dfs(tree->right, targetSum,sum); //get sum
	}
	return 0;
}

