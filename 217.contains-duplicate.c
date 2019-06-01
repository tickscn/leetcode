/*
 * @lc app=leetcode id=217 lang=c
 *
 * [217] Contains Duplicate
 */
void Merge(int* ar, int p, int q, int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;
	int *left, *right;
	left = (int*)malloc(sizeof(int) * n1);
	right = (int*)malloc(sizeof(int) * n2);
	memcpy(left, &ar[p], n1 * sizeof(int));
	memcpy(right, &ar[q + 1], n2 * sizeof(int));
	int i = 0, j = 0;
	for (int k = p; k <= r; k++)
	{

		if (i < n1 && j < n2)
		{
			if (left[i] < right[j])
			{
				ar[k] = left[i];
				i++;
			}
			else
			{
				ar[k] = right[j];
				j++;
			}
		}
		else if (i == n1)
		{
			ar[k] = right[j];
			j++;
		}
		else
		{
			ar[k] = left[i];
			i++;
		}
	}
	free(left);
	free(right);
}

void MergeSort(int* ar, int p, int r)
{
	if (p < r)
	{
		int q = (r + p) / 2;
		MergeSort(ar, p, q);
		MergeSort(ar, q + 1, r);
		Merge(ar, p, q, r);
	}
}
bool containsDuplicate(int* nums, int numsSize)
{
	MergeSort(nums, 0, numsSize - 1);
	for (int i = 1; i < numsSize; ++i)
	{
		if (nums[i] == nums[i - 1])
			return true;
	}
	return false;
}
