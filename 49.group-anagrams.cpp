/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */
class Solution
{
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs)
	{
		unordered_map<string, vector<string>> map;
		vector<vector<string>> res;
		string charMap;
		for (string str : strs)
		{
			charMap = "";
			vector<int> cnt(26, 0);
			for (char ch : str)
			{
				++cnt[ch - 'a'];
			}
			for (int i : cnt)
			{
				charMap += to_string(i);
			}
			map[charMap].push_back(str);
		}
		for (auto out : map)
		{
			res.push_back(out.second);
		}
		return res;
	}
};
