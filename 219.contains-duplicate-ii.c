/*
 * @lc app=leetcode id=219 lang=c
 *
 * [219] Contains Duplicate II
 */
#include <stdbool.h>
struct HashNode {
	int val;
	struct HashNode* next;
};

bool containsNearbyDuplicate(int* nums, int numsSize, int k)
{
	if (numsSize && k > 1)
	{
		struct HashNode* hashtable = (struct HashNode*)malloc(sizeof(struct HashNode) * numsSize);
		for (int i = 0; i < numsSize; ++i)
		{
			hashtable[i].val = -1;
			hashtable[i].next = NULL;
		}
		for (int i = 0; i < numsSize; ++i)
		{
			if (hashtable[nums[i] % numsSize].val == -1)
				hashtable[nums[i] % numsSize].val = i;
			else
			{
				struct HashNode* p = hashtable + nums[i] % numsSize;
				if (nums[p->val] == nums[i])
					if (abs(p->val - i) < k)
						return true;
					else
						p->val = i;
				while (p->next)
				{
					p = p->next;
					if (nums[p->val] == nums[i])
						if (abs(p->val - i) < k)
							return true;
						else
							p->val = i;
				}
				p->next = (struct HashNode*)malloc(sizeof(struct HashNode));
				p->next->val = i;
			}
		}
	}
	return false;
}
