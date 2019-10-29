#include "stack.h"

stack *stack_init(void)
{
	stack *stk = calloc(1, sizeof(stack));
	return stk;
}

void stack_nodeFree(stack *stk)
{
	node *now = stk->top;
	node *next = now->under;
	for (int i = 0; i < stk->size; i++) {
		free(now->key);
		free(now);
		now = next;
		next = now->under;
	}
	free(stk);
}

void _pstack_push(stack *stk, void *key)
{
	node *pnew_node = (node *)malloc(1 * sizeof(node));
	pnew_node->key = key;
	if (stack_isEmpty(stk)) {
		stk->bottom = pnew_node;
		pnew_node->under = NULL;
	} else {
		pnew_node->under = stk->top;
	}
	stk->top = pnew_node;
	stk->size++;
}

void _istack_push(stack *stk, int key)
{
	int *pkey = (int *)malloc(sizeof(int));
	*pkey = key;
	_pstack_push(stk, pkey);
}

void *stack_pop(stack *stk)
{
	node *ret = stk->top;
	void *key = ret->key;
	stk->top = ret->under;
	free(ret);
	stk->size--;
	return key;
}

void *stack_dup(stack *stk, size_t key_size)
{
	void *add_key = malloc(key_size);
	memcpy(add_key, stk->top->key, key_size);
	_pstack_push(stk, add_key);
	return add_key;
}

void *stack_top(stack *stk) { return stk->top->key; }

void stack_swap(stack *stk)
{
	if (stk->size > 1) {
		node *top, *sec;
		top = stk->top;
		sec = stk->top->under;
		top->under = sec->under;
		sec->under = top;
		stk->top = sec;
	}
}

void stack_rrotate(stack *stk)
{
	if (stk->size > 1) {
		stk->bottom->under = stk->top;
		stk->bottom = stk->top;
		stk->top = stk->top->under;
		stk->bottom->under = NULL;
	}
}

void stack_lrotate(stack *stk)
{
	if (stk->size > 1) {
		node *secButtom = stk->top;
		for (int i = 0; i < stk->size - 2; i++)
			secButtom = secButtom->under;
		stk->bottom->under = stk->top;
		stk->top = stk->bottom;
		stk->bottom = secButtom;
		stk->bottom->under = NULL;
	}
}

bool stack_isEmpty(stack *stk) { return stk->size == 0; }

size_t stack_size(stack *stk) { return stk->size; }
