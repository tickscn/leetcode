/*
 * @lc app=leetcode id=68 lang=cpp
 *
 * [68] Text Justification
 */
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
	vector<string> fullJustify(vector<string>& words, int maxWidth)
	{
		vector<string> res;
		int wordsNum = words.size();
		for (int i = 0, j, len; i < wordsNum; i = j)
		{
			for (j = i, len = 0; j < wordsNum && len + words[j].length() + j - i <= maxWidth; ++j)
			{
				len += words[j].length();
			}
			string line;
			int spaceNum = maxWidth - len;
			for (int k = i; k < j; ++k)
			{
				line += words[k];
				if (spaceNum > 0)
				{
					int tmpNum;
					if (j == wordsNum)  // 最后一行
					{
						tmpNum = j - k == 1 ? spaceNum : 1;
					}
					else
					{
						if (j - k > 1)
						{
							tmpNum = (spaceNum + j - k - 2) / (j - k - 1);
						}
						else
						{
							tmpNum = spaceNum;
						}
					}

					line.append(tmpNum, ' ');
					spaceNum -= tmpNum;
				}
			}
			res.push_back(line);
		}
		return res;
	}
};
