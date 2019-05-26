/*
 * @lc app=leetcode id=107 lang=c
 *
 * [107] Binary Tree Level Order Traversal II
 */

// Definition for a binary tree node.
// struct TreeNode {
// 	int val;
// 	struct TreeNode* left;
// 	struct TreeNode* right;
// };
// #include <stdbool.h>
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int maxDepth(struct TreeNode* root)
{
	if (root)
	{
		int a = maxDepth(root->left) + 1;
		int b = maxDepth(root->right) + 1;
		return a > b ? a : b;
	}
	return 0;
}
struct QueueNode {
	struct TreeNode* val;
	struct QueueNode* next;
	struct QueueNode* pre;
};

struct Queue {
	struct QueueNode* rail;
	struct QueueNode* head;
};

bool isEmptyQueue(struct Queue* q)
{
	if (!q->rail && !q->head)
		return true;
	return false;
}

void EnQueue(struct Queue* q, struct TreeNode* tr)
{
	struct QueueNode* qnode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
	qnode->val = tr;
	qnode->next = q->rail;
	qnode->pre = NULL;
	if (isEmptyQueue(q))
	{
		q->rail = q->head = qnode;
	}
	else
	{
		q->rail->pre = qnode;
		q->rail = qnode;
	}
}
void DeQueue(struct Queue* q, struct TreeNode* tr)
{
	tr = q->head->val;
	struct QueueNode* qnode = q->head;
	q->head = q->head->pre;
	if (q->head)
		q->head->next = NULL;
	free(qnode);
}

int levelNum(struct TreeNode* root, int level)
{
	if (!root)
		return 0;
	if (root && level == 1)
		return 1;
	return levelNum(root->left, level - 1) + levelNum(root->right, level - 1);
}

int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
{
	int** ret = NULL;
	if (!root)
	{
		*returnSize = 0;
		return ret;
	}
	*returnSize = maxDepth(root);
	ret = (int**)malloc((*returnSize) * sizeof(int*));
	struct Queue que;
	struct TreeNode* tr = NULL;
	que.head = NULL;
	que.rail = NULL;
	EnQueue(&que, root);
	for (int i = *returnSize - 1; i >= 0; --i)
	{
		int num = levelNum(root, *returnSize - i);
		ret[i] = (int*)malloc(num);
		for (int j = 0; j < num; ++j)
		{
			DeQueue(&que, tr);
			ret[i][j] = tr->val;
			if (tr->left)
				EnQueue(&que, tr->left);
			if (tr->right)
				EnQueue(&que, tr->right);
		}
	}
	return ret;
}
