/*
 * @lc app=leetcode id=155 lang=c
 *
 * [155] Min Stack
 */

typedef struct stacknode {
	int val;
	struct stacknode* next;
	struct stacknode* minnext;
} StackNode;

typedef struct {
	StackNode* top;
	StackNode* mintop;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate()
{
	MinStack* ret = (MinStack*)malloc(sizeof(MinStack));
	ret->top = NULL;
	ret->mintop = NULL;
	return ret;
}

void minStackPush(MinStack* obj, int x)
{
	StackNode* t = (StackNode*)malloc(sizeof(StackNode));
	t->val = x;
	t->next = obj->top;
	obj->top = t;
	if (!obj->mintop || x <= obj->mintop->val)
	{
		t->minnext = obj->mintop;
		obj->mintop = t;
	}
}

void minStackPop(MinStack* obj)
{
	if (obj->top)
	{
		StackNode* p = obj->top;
		obj->top = p->next;
		if (p == obj->mintop)
		{
			obj->mintop = p->minnext;
		}
		free(p);
	}
}

int minStackTop(MinStack* obj)
{
	return obj->top->val;
}

int minStackGetMin(MinStack* obj)
{
	return obj->mintop->val;
}

void minStackFree(MinStack* obj)
{
	while (obj->top)
	{
		minStackPop(obj);
	}
	free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);

 * minStackPop(obj);

 * int param_3 = minStackTop(obj);

 * int param_4 = minStackGetMin(obj);

 * minStackFree(obj);
*/
