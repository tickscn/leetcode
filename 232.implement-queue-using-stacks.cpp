/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */
#include <stack>
using std::stack;
class MyQueue
{
private:
	stack<int> in, out;

public:
	/** Initialize your data structure here. */
	MyQueue() {}

	/** Push element x to the back of queue. */
	void push(int x)
	{
		in.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop()
	{
		if (out.empty())
			InToOut();
		int val = out.top();
		out.pop();
		return val;
	}

	/** Get the front element. */
	int peek()
	{
		if (out.empty())
			InToOut();
		return out.top();
	}

	/** Returns whether the queue is empty. */
	bool empty()
	{
		return in.empty() && out.empty();
	}
	void InToOut()
	{
		while (!in.empty())
		{
			out.push(in.top());
			in.pop();
		}
	}
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
