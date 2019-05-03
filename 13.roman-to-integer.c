/*
 * @lc app=leetcode id=13 lang=c
 *
 * [13] Roman to Integer
 */

int romanToInt(char* s)
{
	int ret = 0;
	while (*s != '\0')
	{
		switch (*s)
		{
		case 'M':
			ret += 1000;
			break;
		case 'D':
			ret += 500;
			break;
		case 'C':
			if (*(s + 1) == 'M')
			{
				ret += 900;
				++s;
			}
			else if (*(s + 1) == 'D')
			{
				ret += 400;
				++s;
			}
			else
			{
				ret += 100;
			}
			break;
		case 'L':
			ret += 50;
			break;
		case 'X':
			if (*(s + 1) == 'C')
			{
				ret += 90;
				++s;
			}
			else if (*(s + 1) == 'L')
			{
				ret += 40;
				++s;
			}
			else
			{
				ret += 10;
			}
			break;
		case 'V':
			ret += 5;
			break;
		default:
			if (*(s + 1) == 'X')
			{
				ret += 9;
				++s;
			}
			else if (*(s + 1) == 'V')
			{
				ret += 4;
				++s;
			}
			else
			{
				ret += 1;
			}
			break;
		}
		++s;
	}
	return ret;
}
