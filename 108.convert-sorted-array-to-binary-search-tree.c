/*
 * @lc app=leetcode id=108 lang=c
 *
 * [108] Convert Sorted Array to Binary Search Tree
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* sortedArrayToBST(int* nums, int numsSize)
{
	struct TreeNode* root = NULL;
	if (numsSize == 1)
	{
		root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
		root->val = nums[0];
		root->left = root->right = NULL;
	}
	if (numsSize)
	{
		int mid = numsSize / 2;
		root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
		root->val = nums[mid];
		root->left = sortedArrayToBST(nums, mid);
		if (numsSize - mid - 1 > 0)
			root->right = sortedArrayToBST(nums + mid + 1, numsSize - mid - 1);
		else
		{
			root->right = NULL;
		}
	}
	return root;
}
