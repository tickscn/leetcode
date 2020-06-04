/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU缓存机制
 *
 * https://leetcode-cn.com/problems/lru-cache/description/
 *
 * algorithms
 * Medium (49.34%)
 * Likes:    650
 * Dislikes: 0
 * Total Accepted:    69.9K
 * Total Submissions: 141.5K
 * Testcase Example:  '["LRUCache","put","put","get","put","get","put","get","get","get"]\n' +
  '[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]'
 *
 * 运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制。它应该支持以下操作： 获取数据 get 和 写入数据
 put 。
 *
 * 获取数据 get(key) - 如果关键字 (key) 存在于缓存中，则获取关键字的值（总是正数），否则返回 -1。
 * 写入数据 put(key, value) -
 * 如果关键字已经存在，则变更其数据值；如果关键字不存在，则插入该组「关键字/值」。当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。
 *
 *
 *
 * 进阶:
 *
 * 你是否可以在 O(1) 时间复杂度内完成这两种操作？
 *
 *
 *
 * 示例:
 *
 * LRUCache cache = new LRUCache( 2 );
 *
 * cache.put(1, 1);
 * cache.put(2, 2);
 * cache.get(1);       // 返回  1
 * cache.put(3, 3);    // 该操作会使得关键字 2 作废
 * cache.get(2);       // 返回 -1 (未找到)
 * cache.put(4, 4);    // 该操作会使得关键字 1 作废
 * cache.get(1);       // 返回 -1 (未找到)
 * cache.get(3);       // 返回  3
 * cache.get(4);       // 返回  4
 *
 *
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
struct lnode {
    weak_ptr<lnode> pre;
    shared_ptr<lnode> next;
    pair<int, int> KeyValue;
    lnode(const pair<int, int>& _kv, shared_ptr<lnode> _pre = nullptr, shared_ptr<lnode> _next = nullptr)
        : KeyValue(std::move(_kv)), pre(_pre), next(_next)
    {
    }
};
class LRUCache {
private:
    int cap;
    int size;
    shared_ptr<lnode> head;
    shared_ptr<lnode> tail;
    unordered_map<int, shared_ptr<lnode>> table;

public:
    LRUCache(int capacity) : cap(capacity), size(0), head(nullptr), tail(nullptr) {}

    int get(int key)
    {
        if (table.find(key) != table.end())
        {
            auto pt = table[key];
            MovedToHead(pt);
            return pt->KeyValue.second;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (table.find(key) != table.end())
        {
            auto pt = table[key];
            MovedToHead(pt);
            pt->KeyValue.second = value;
        }
        else if (table.size() == cap)
        {
            auto pt = tail;
            pop();
            table.erase(pt->KeyValue.first);
            pt.reset(new lnode(make_pair(key, value)));
            push(pt);
            table[key] = pt;
        }
        else
        {
            auto pt = make_shared<lnode>(make_pair(key, value));
            push(pt);
            table[key] = pt;
        }
    }
    void push(shared_ptr<lnode> node)
    {
        if (!head)
            tail = head = node;
        else
        {
            node->next = head;
            head->pre  = node;
            head       = node;
        }
    }
    void pop()
    {
        if (tail != head)
        {
            tail = tail->pre.lock();
            tail->next.reset();
        }
        else
        {
            head.reset();
            tail.reset();
        }
    }
    void MovedToHead(shared_ptr<lnode> node)
    {
        if (node != head)
        {
            if (tail == node) tail = node->pre.lock();
            node->pre.lock()->next = node->next;
            if (node->next) node->next->pre = node->pre;
            node->pre.reset();
            node->next = head;
            head->pre  = node;
            head       = node;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
