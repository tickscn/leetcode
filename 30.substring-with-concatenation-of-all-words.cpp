/*
 * @lc app=leetcode id=30 lang=cpp
 *
 * [30] Substring with Concatenation of All Words
 */
class Solution
{
public:
	vector<int> findSubstring(string s, vector<string>& words)
	{
		vector<int> res;
		int sLength = s.length();
		int wordsSize = words.size();
		if (sLength == 0 || wordsSize == 0) return res;
		int m = words[0].length();
		if (m == 0 || m * wordsSize > sLength) return res;
		unordered_map<string, int> wordsMap;
		for (int i = 0; i < wordsSize; ++i)
		{
			if (wordsMap.find(words[i]) == wordsMap.end())
				wordsMap[words[i]] = 1;
			else
				++wordsMap[words[i]];
		}
		for (int seed = 0; seed < m; ++seed)
		{
			unordered_map<string, int> growthRes;
			int growthNum = 0;
			for (int i = seed; i <= sLength - m; i += m)
			{
				string tmp = s.substr(i, m);
				if (wordsMap.find(tmp) == wordsMap.end())
				{
					growthRes.clear();
					growthNum = 0;
				}
				else
				{
					if (growthRes.find(tmp) == wordsMap.end())
						growthRes[tmp] = 1;
					else
						++growthRes[tmp];
					++growthNum;
					while (wordsMap[tmp] < growthRes[tmp])
					{
						string tmpRemove = s.substr(i - (growthNum - 1) * m, m);
						--growthRes[tmpRemove];
						--growthNum;
					}
					if (growthNum == wordsSize) res.push_back(i - (wordsSize - 1) * m);
				}
			}
		}
		return res;
	}
};
