/*
 * @lc app=leetcode id=67 lang=c
 *
 * [67] Add Binary
 */

char* addBinary(char* a, char* b)
{
	int length1, length2;
	length1 = strlen(a);
	length2 = strlen(b);
	int carry = 0;
	int length = length1 > length2 ? length1 : length2;
	char* ret = (char*)malloc(length + 1);
	ret[length] = '\0';
	--length;
	--length1;
	--length2;
	while (length1 >= 0 && length2 >= 0)
	{
		ret[length] = ((a[length1] - '0') + (b[length2] - '0') + carry) % 2 + '0';
		carry = ((a[length1] - '0') + (b[length2] - '0') + carry) / 2;
		--length;
		--length1;
		--length2;
	}
	while (length1 >= 0)
	{
		ret[length] = ((a[length1] - '0') + carry) % 2 + '0';
		carry = ((a[length1] - '0') + carry) / 2;
		--length1;
		--length;
	}
	while (length2 >= 0)
	{
		ret[length] = ((b[length2] - '0') + carry) % 2 + '0';
		carry = ((b[length2] - '0') + carry) / 2;
		--length2;
		--length;
	}
	if (carry == 1)
	{
		length = strlen(ret) + 2;
		char* ret1 = (char*)malloc(length);
		ret1[0] = '1';
		strncpy(&ret1[1], ret, length - 1);
		free(ret);
		return ret1;
	}
	return ret;
}
