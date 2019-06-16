/*
 * @lc app=leetcode id=401 lang=cpp
 *
 * [401] Binary Watch
 */
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
	vector<string> readBinaryWatch(int num)
	{
		vector<string> ret;
		vector<vector<string>> hor{{"0"}, {"1", "2", "4", "8"}, {"3", "5", "6", "9", "10"}, {"7", "11"}};
		vector<vector<string>> min{{"00"},
		                           {"01", "02", "04", "08", "16", "32"},
		                           {"03", "05", "09", "17", "33", "06", "10", "18", "34", "12", "20", "36", "24", "40", "48"},
		                           {"07", "11", "19", "35", "13", "21", "37", "25", "41", "49", "14", "22", "38", "26", "42", "50", "28", "44", "52", "56"},
		                           {"15", "23", "39", "27", "43", "51", "29", "45", "53", "57", "30", "46", "54", "58"},
		                           {"31", "47", "55", "59"}};
		for (int h = 0; h <= num && h < 4; h++)
		{
			int m = num - h;
			if (m > 5) continue;
			for (string hour : hor[h])
				for (string mins : min[m])
				{
					ret.push_back(hour + ":" + mins);
				}
		}
		return ret;
	}
};
