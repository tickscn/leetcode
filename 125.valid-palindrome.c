/*
 * @lc app=leetcode id=125 lang=c
 *
 * [125] Valid Palindrome
 */
bool isPalindrome(char* s)
{
	int length = strlen(s);
	int i = 0, j = length;
	while (i < j)
	{
		if (!isalnum(s[i]))
		{
			++i;
			continue;
		}
		if (!isalnum(s[j]))
		{
			--j;
			continue;
		}
		if (isdigit(s[i]) && isdigit(s[j]))
		{
			if (s[i] != s[j])
				return false;
		}
		else if (isalpha(s[i]) && isalpha(s[j]))
		{
			if (tolower(s[i]) != tolower(s[j]))
				return false;
		}
		else
		{
			return false;
		}
		++i;
		--j;
	}
	return true;
}
