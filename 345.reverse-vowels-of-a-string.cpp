/*
 * @lc app=leetcode id=345 lang=cpp
 *
 * [345] Reverse Vowels of a String
 */
class Solution
{
public:
	string reverseVowels(string s)
	{
		int i = 0, j = s.length() - 1;
		while (i < j)
		{
			if (!isVowels(s[i]))
			{
				++i;
			}
			if (!isVowels(s[j]))
			{
				--j;
			}
			if (isVowels(s[i]) && isVowels(s[j]))
			{
				char tmp = s[i];
				s[i] = s[j];
				s[j] = tmp;
				++i;
				--j;
			}
		}
		return s;
	}
	bool isVowels(char ch)
	{
		switch (ch)
		{
		case 'a':
		case 'A':
		case 'e':
		case 'E':
		case 'i':
		case 'I':
		case 'o':
		case 'O':
		case 'u':
		case 'U':
			return true;
		default:
			return false;
		}
	}
};
