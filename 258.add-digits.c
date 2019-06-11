/*
 * @lc app=leetcode id=258 lang=c
 *
 * [258] Add Digits
 */

int addDigits(int num)
{
	return num == 0 ? 0 : (num - 1) % 9 + 1;
}
