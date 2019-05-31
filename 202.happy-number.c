/*
 * @lc app=leetcode id=202 lang=c
 *
 * [202] Happy Number
 */

bool isHappy(int n)
{  // 用上了之前判断循环链表的方法
	if (n == 1)
		return true;
	int slow = digitPowerSum(n), fast = digitPowerSum(digitPowerSum(n));
	while (slow != fast && fast != 1)
	{
		slow = digitPowerSum(slow);
		fast = digitPowerSum(digitPowerSum(fast));
	}
	if (fast == 1)
		return true;
	return false;
}
int digitPowerSum(int n)
{
	int sum = 0;
	while (n)
	{
		sum += (n % 10) * (n % 10);
		n /= 10;
	}
	return sum;
}
