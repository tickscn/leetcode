/*
 * @lc app=leetcode id=20 lang=c
 *
 * [20] Valid Parentheses
 */

#include <stdbool.h>
bool isValid(char* s)
{
	if (strlen(s) % 2)
		return false;
	int length = strlen(s);
	char* stack = (char*)malloc(length);
	int size = 0;
	while (*s)
	{
		switch (*s)
		{
		case '(':
		case '[':
		case '{':
			stack[size] = *s;
			++size;
			break;
		case ')':
			if (size == 0 || stack[size - 1] != '(')
				return false;
			--size;
			break;
		case ']':
			if (size == 0 || stack[size - 1] != '[')
				return false;
			--size;
			break;
		case '}':
			if (size == 0 || stack[size - 1] != '{')
				return false;
			--size;
			break;
		}
		++s;
	}
	return size == 0;
}
