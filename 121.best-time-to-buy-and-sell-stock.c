/*
 * @lc app=leetcode id=121 lang=c
 *
 * [121] Best Time to Buy and Sell Stock
 */
#include <limits.h>
int findCroMaxSubArr(int* ar, int n)
{
    int mid = n / 2;
    int left_sum, right_sum, sum = 0;
    left_sum  = ar[mid];
    right_sum = 0;
    for (int i = mid; i >= 0; --i)
    {
        sum += ar[i];
        if (sum > left_sum)
        {
            left_sum = sum;
        }
    }
    sum = 0;
    for (int i = mid + 1; i < n; ++i)
    {
        sum += ar[i];
        if (sum > right_sum)
        {
            right_sum = sum;
        }
    }
    return left_sum + right_sum;
}

int maxSubArray(int* nums, int numsSize)
{
    int ret, right, mid;
    if (numsSize == 1)
        return nums[0];
    else
    {
        mid   = numsSize / 2;
        ret   = maxSubArray(nums, mid);
        right = maxSubArray(nums + mid, numsSize - mid);
        mid   = findCroMaxSubArr(nums, numsSize);
        if (right > ret) ret = right;
        if (mid > ret) ret = mid;
        return ret;
    }
}

int maxProfit(int* prices, int pricesSize)
{
    if (pricesSize <= 1) return 0;
    // int* array = (int*)malloc((pricesSize - 1) * sizeof(int));
    int max = 0;
    int min = INT_MAX;
    for (int i = 0; i < pricesSize; ++i)
    {
        min = prices[i] < min ? prices[i] : min;
        max = prices[i] - min > max ? prices[i] - min : max;
    }
    return max;
}
