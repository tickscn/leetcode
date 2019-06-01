/*
 * @lc app=leetcode id=225 lang=c
 *
 * [225] Implement Stack using Queues
 */

typedef struct MyStackNode {
	int val;
	struct MyStackNode* next;
} MyStackNode;

typedef struct {
	MyStackNode* top;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate()
{
	MyStack* tmp = (MyStack*)malloc(sizeof(MyStack));
	tmp->top = NULL;
	return tmp;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x)
{
	MyStackNode* p = (MyStackNode*)malloc(sizeof(MyStackNode));
	p->val = x;
	p->next = obj->top;
	obj->top = p;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj)
{
	MyStackNode* p = obj->top;
	int i = p->val;
	obj->top = p->next;
	free(p);
	return i;
}

/** Get the top element. */
int myStackTop(MyStack* obj)
{
	return obj->top->val;
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj)
{
	return obj->top ? false : true;
}

void myStackFree(MyStack* obj)
{
	while (!myStackEmpty(obj))
	{
		myStackPop(obj);
	}
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);

 * int param_2 = myStackPop(obj);

 * int param_3 = myStackTop(obj);

 * bool param_4 = myStackEmpty(obj);

 * myStackFree(obj);
*/
