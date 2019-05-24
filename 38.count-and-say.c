/*
 * @lc app=leetcode id=38 lang=c
 *
 * [38] Count and Say
 */
char* countAndSay(int n)
{
	char* ch1 = (char*)calloc(5000, 1);
	char* ch2 = (char*)calloc(5000, 1);
	ch2[0] = '1';
	char* tmp = ch1;
	int count = 1;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; ch2[j]; ++j)
		{
			while (ch2[j] == ch2[j + 1])
			{
				++count;
				++j;
			}
			*tmp = '0' + count;
			*(tmp + 1) = ch2[j];
			tmp += 2;
			count = 1;
		}
		tmp = ch2;
		ch2 = ch1;
		ch1 = tmp;
	}
	free(ch1);
	return ch2;
}
