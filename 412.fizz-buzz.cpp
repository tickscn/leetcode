/*
 * @lc app=leetcode id=412 lang=cpp
 *
 * [412] Fizz Buzz
 */
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<string> fizzBuzz(int n)
	{
		vector<string> res(n);
		for (int i = 0; i < n; ++i)
		{
			if ((i + 1) % 15 == 0)
				res[i] = "FizzBuzz";
			else if ((i + 1) % 5 == 0)
				res[i] = "Buzz";
			else if ((i + 1) % 3 == 0)
				res[i] = "Fizz";
			else
				res[i] = to_string(i + 1);
		}
		return res;
	}
};
