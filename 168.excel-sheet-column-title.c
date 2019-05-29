/*
 * @lc app=leetcode id=168 lang=c
 *
 * [168] Excel Sheet Column Title
 */

char* convertToTitle(int n)
{
	int tmp = n;
	int count = 0;
	while (tmp)
	{
		++count;
		if (tmp % 26)
		{
			tmp -= tmp % 26;
			tmp /= 26;
		}
		else
		{
			tmp -= 26;
			tmp /= 26;
		}
	};
	char* returnStr = (char*)malloc(count + 1);
	returnStr[count] = '\0';
	int i;
	for (i = count - 1; i >= 0; --i)
	{
		if (n % 26)
		{
			returnStr[i] = 'A' - 1 + n % 26;
			n -= n % 26;
		}
		else
		{
			returnStr[i] = 'Z';
			n -= 26;
		}

		n /= 26;
	}
	return returnStr;
}
