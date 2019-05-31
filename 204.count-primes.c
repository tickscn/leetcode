/*
 * @lc app=leetcode id=204 lang=c
 *
 * [204] Count Primes
 */
int countPrimes(int n)
{
	if (n <= 2)
		return 0;
	if (n == 3)
		return 1;
	int* prime = (int*)malloc(sizeof(int) * (n / 2));
	prime[0] = 2;
	prime[1] = 3;
	int ret = 2;
	for (int i = 5; i < n; i += 2)
	{
		if (i % 6 != 1 && i % 6 != 5)
			goto loop;
		for (int j = 1; j < ret; ++j)
		{
			if (prime[j] > sqrt(i))
				break;
			if (i % prime[j] == 0)
				goto loop;
		}
		prime[ret] = i;
		++ret;
	loop:;
	}
	return ret;
}
