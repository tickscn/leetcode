/*
 * @lc app=leetcode.cn id=1396 lang=cpp
 *
 * [1396] 设计地铁系统
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class UndergroundSystem {
public:
    unordered_map<string, pair<int, int>> Statistic;
    unordered_map<int, pair<string, int>> passenger;
    void checkIn(int id, string stationName, int t)
    {
        passenger[id] = make_pair(stationName, t);
    }

    void checkOut(int id, string stationName, int t)
    {
        string path = passenger[id].first + stationName;
        if (Statistic.count(path) == 0)
            Statistic[path] = make_pair(1, t - passenger[id].second);
        else
        {
            ++Statistic[path].first;
            Statistic[path].second += t - passenger[id].second;
        }
    }

    double getAverageTime(string startStation, string endStation)
    {
        auto path = startStation + endStation;
        return Statistic[path].second / static_cast<double>(Statistic[path].first);
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
// @lc code=end
